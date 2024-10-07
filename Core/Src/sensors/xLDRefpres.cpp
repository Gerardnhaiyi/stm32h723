/********************************************************************************************************************************
 *	File name:				xLDRefpres.cpp
 *
 *	File Description:		Implementation of the control class of a xLR pressure sensor.
 *
 ********************************************************************************************************************************/
//#include "FreeRTOS.h"
//#include "task.h"
#include "cmsis_os.h"
#include "xLDRefpres.hpp"
#include "stm32h7xx_hal.h"

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::xLDRefpres
 *
 *	Method Description:		constructor
 *
 *	Entry:					adress			I2C adress of the device
 *							resetPortIn		port of the reset pin
 *							resetPinIn		pin of the reset pin
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
xLDRefpres::xLDRefpres(uint8_t adress, I2C_HandleTypeDef &hi2cIn, DMA_HandleTypeDef &dmaReciveIn, DMA_HandleTypeDef &dmaSendIn, GPIO_TypeDef *resetPortIn, uint16_t resetPinIn) :
	busAdress( adress ), resetPort(resetPortIn), resetPin(resetPinIn), dmaRecv(dmaReciveIn), dmaSend(dmaSendIn), hi2c(hi2cIn)
{
	toISR = osMessageQueueNew(1, IN_BUFFER_SIZE, &toISR_attributes);
	fromISR = osMessageQueueNew(NR_MAX_INPUT_MESSAGES, OUT_BUFFER_SIZE, &fromISR_attributes);
//	toISR = xQueueCreate( 1, IN_BUFFER_SIZE );
//	fromISR = xQueueCreate( NR_MAX_INPUT_MESSAGES, OUT_BUFFER_SIZE );
	Reset();
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::Reset
 *
 *	Method Description:		Resets the MTF and initializes the sensor.
 *
 *	Entry:					None
 *
 *	exit:					Reset successful;
 *
 ********************************************************************************************************************************/
bool xLDRefpres::Reset()
{
	uint32_t recvData = 0;
	initialized = false;
	bool returnValue = false;
	const TickType_t xDelay = 1 / portTICK_PERIOD_MS;

	// TODO: reset
	HAL_GPIO_WritePin( resetPort, resetPin, GPIO_PIN_SET );
	HAL_Delay( 10/ portTICK_PERIOD_MS);
	HAL_GPIO_WritePin( resetPort, resetPin, GPIO_PIN_RESET );
	/*****************************************************************************************************************************
	 * Start of range
	 ****************************************************************************************************************************/
	recvData = 0;
	txBuffer[0] = START_RANGE_LSB;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay(xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<8 | rxBuffer[2];

	txBuffer[0] = START_RANGE_MSB;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<24 | rxBuffer[2]<<16;
	mesuringRangeStart = *((float*)(&recvData));

	/*****************************************************************************************************************************
	 * End of range
	 ****************************************************************************************************************************/
	recvData = 0;
	txBuffer[0] = END_RANGE_LSB;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<8 | rxBuffer[2];

	txBuffer[0] = END_RANGE_MSB;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<24 | rxBuffer[2]<<16;
	mesuringRangeEnd = *((float*)(&recvData));

	sensetivetyPresure = (MBE_PRESURE - MBA_PRESURE)/( mesuringRangeEnd - mesuringRangeStart );

	/*****************************************************************************************************************************
	 * Unit
	 ****************************************************************************************************************************/
	recvData = 0;
	txBuffer[0] = UNIT;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<8 | rxBuffer[2];
	unit = static_cast<MeasureUnit>(recvData);

	/*****************************************************************************************************************************
	 * Part number
	 ****************************************************************************************************************************/
	recvData = 0;
	txBuffer[0] = CUST_ID_0;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<8 | rxBuffer[2];

	txBuffer[0] = CUST_ID_1;
	HAL_I2C_Master_Transmit(&hi2c,busAdress,txBuffer,1,1000);
	HAL_Delay( xDelay );
	HAL_I2C_Master_Receive(&hi2c, busAdress, rxBuffer, 3, 1000);
	returnValue = parsStatus(rxBuffer[0]) || returnValue;
	recvData |= rxBuffer[1]<<24 | rxBuffer[2]<<16;
	custNumber = recvData;

	/*****************************************************************************************************************************
	 * Start receiving pressures and temperatures
	 ****************************************************************************************************************************/
	txBuffer[0] = READ_REQUEST;
	returnValue = ( HAL_I2C_Master_Transmit_DMA(&hi2c,busAdress,txBuffer,OUT_REQUEST_SIZE) != HAL_OK ) || returnValue ;
	initialized = true;
	return(!returnValue);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::pinInterupt
 *
 *	Method Description:		static function to handle interrupts from the xLDRefpres ready pin.
 *
 *	Entry:					instance	reference to the instance of the class belonging to the xLDRefpres that is ready
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void xLDRefpres::pinInterupt (xLDRefpres *instance)
{
	instance->MTFREady();
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::DMARecvInterupt
 *
 *	Method Description:		static function to handle interrupts from the DMA module. uses the Parent field in the DMA handle
 *							as a class reference.
 *
 *	Entry:					hdma	the DMA handle containing the settings for the DMA and the class.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void xLDRefpres::DMARecvInterupt (DMA_HandleTypeDef *hdma)
{
	static_cast< xLDRefpres* >( hdma->Parent )->DMARecvReady();
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::MTFREady
 *
 *	Method Description:		handles the interupt from the xLDRefpres ready pin. will start a data reception using the included
 *							DMA channels.
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void xLDRefpres::MTFREady()
{
	HAL_I2C_Master_Receive_DMA(&hi2c,busAdress,rxBuffer,IN_BUFFER_SIZE); //Receiving in DMA mode
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::DMARecvReady
 *
 *	Method Description:		handles the interupt from the DMA ready will copy the receved data to a queue to be handled by the
 *							run function. no error checking done at this point. when done it will send the request for the
 *							next set of data.
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void xLDRefpres::DMARecvReady()
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//	xQueueSendToBackFromISR( fromISR, rxBuffer, &xHigherPriorityTaskWoken );
	osMessageQueuePut( fromISR, rxBuffer, 0U, 0U );
	if ( initialized )
	{
		txBuffer[0] = READ_REQUEST;
		HAL_I2C_Master_Transmit_DMA(&hi2c,busAdress,txBuffer,OUT_REQUEST_SIZE);
	}
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::parsStatus
 *
 *	Method Description:		Parses the settings byte and fills the  in the class
 *
 *	Entry:					status		the status byte.
 *
 *	exit:					bool		true if error found.
 *
 ********************************************************************************************************************************/
bool xLDRefpres::parsStatus(uint8_t status)
{
	// 0 1 busy mode1 mode0 memerr 0 alusat
	if ( ( ~SETTING_MASK & status ) == SETTING_CONST_RESULT )
	{
		busy = ( status & SETTING_BUSY ) == SETTING_BUSY;
		mode = ( status & SETTING_MODE );
		memoryError = ( status & SETTING_MEM_ERR ) == SETTING_MEM_ERR;
		return ( busy || memoryError );
	}
	return(true);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getStatus
 *
 *	Method Description:		checks for errors in the last transmission
 *
 *	Entry:					none
 *
 *	exit:					bool		true if error.
 *
 ********************************************************************************************************************************/
bool xLDRefpres::getStatus()
{
	return ( busy || memoryError );
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::run
 *
 *	Method Description:		waits for data to be received and than error checks it and parses the data.
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void xLDRefpres::run(dataStorage& ds)
{
	uint8_t buffer[IN_BUFFER_SIZE] = {0};
//	if ( xQueueReceive( fromISR, buffer, portMAX_DELAY ) == pdTRUE )
	if ( osMessageQueueGet( fromISR, buffer, NULL, portMAX_DELAY ) == pdTRUE )
	{
		uint32_t pressureIn = 0;
		uint32_t temperatureIn = 0;
		//data: status, PD-pressure <15:8>, PD-pressure <7:0>, PD-temperature <15:8>, PD-temperature <7:0>
		if (!parsStatus(buffer[0]))
		{
			pressureIn = buffer[1]<<8 | buffer[2];		//16bit
			temperatureIn = buffer[3]<<8 | buffer[4]; 	//16bit
			pressure = ((pressureIn - MBA_PRESURE)/sensetivetyPresure)+mesuringRangeStart;
			temperature = ((temperatureIn - MBA_TEMP)*SENSETIVETY_TEMP)+MBA_UNIT_TEMP;

			ds.setFloatValueName(paramNames::REFERENCE_PRESSURE_LAST_PRESSURE, pressure);
			ds.setFloatValueName(paramNames::REFERENCE_PRESSURE_LAST_TEMPERATURE, temperature);
		}
	} //if ( xQueueReceive( fromISR, buffer, portMAX_DELAY ) == pdTRUE )
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getRangeStart
 *
 *	Method Description:		get the start of the range as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					float	range start value
 *
 ********************************************************************************************************************************/
float xLDRefpres::getRangeStart()
{
	return(mesuringRangeStart);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getRangeEnd
 *
 *	Method Description:		get the end of the range as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					float	range end value
 *
 ********************************************************************************************************************************/
float xLDRefpres::getRangeEnd()
{
	return(mesuringRangeEnd);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getUnit
 *
 *	Method Description:		get the unit as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					MeasureUnit	unit
 *
 ********************************************************************************************************************************/
xLDRefpres::MeasureUnit xLDRefpres::getUnit()
{
	return(unit);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getCusttNr
 *
 *	Method Description:		get the Cust number as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					uint32_t	cust number
 *
 ********************************************************************************************************************************/
uint32_t xLDRefpres::getCustNr()
{
	return(custNumber);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getPressure
 *
 *	Method Description:		get the last pressure as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					float	pressure
 *
 ********************************************************************************************************************************/
float xLDRefpres::getPressure()
{
	return(pressure);
}

/********************************************************************************************************************************
 *	Method name:			xLDRefpres::getTemperature
 *
 *	Method Description:		get the last temperature as given by the sensor
 *
 *	Entry:					None
 *
 *	exit:					float	temperature
 *
 ********************************************************************************************************************************/
float xLDRefpres::getTemperature()
{
	return(temperature);
}
