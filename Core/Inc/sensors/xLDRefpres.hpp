/********************************************************************************************************************************
 *	File name:				xLDRefpres.hpp
 *
 *	File Description:		Interface class for an xLR pressure sensor.
 *
 ********************************************************************************************************************************/
#ifndef XLDREFPRES_HPP_
#define XLDREFPRES_HPP_

#include "cmsis_os.h"
//#include "FreeRTOS.h"
//#include "semphr.h"
#include <cstdint>
#include <cmath>
#include "stm32h7xx_hal.h"
#include "dataSTorage.hpp"

/********************************************************************************************************************************
 *	Class name:				xLDRefpres
 *
 *	Class Description:		A class to interface a xLR pressure sensor sensor.
 *
 ********************************************************************************************************************************/
class xLDRefpres
{
	public:
		enum class MeasureUnit : uint8_t
		{
			VENTED_GAUGE = 0x00,
			SEALED_GAUGE = 0x01,
			ABSOLUTE_GAUGE = 0x02,
			UNDEFINED_GAUGE = 0x03,
		};

	private:
		static const uint8_t READ_REQUEST = 0xAC;
		static const uint8_t CALC_CHECKSUM = 0x90;
		static const uint8_t READ_MTP = 0x02;
		static const uint8_t WRITE_MTP = 0x42;

		static const uint8_t START_RANGE_LSB = 0x14;
		static const uint8_t START_RANGE_MSB = 0x13;
		static const uint8_t END_RANGE_LSB = 0x16;
		static const uint8_t END_RANGE_MSB = 0x15;
		static const uint8_t UNIT = 0x12;
		static const uint8_t CUST_ID_0 = 0x00;
		static const uint8_t CUST_ID_1 = 0x01;

		static const uint8_t IN_BUFFER_SIZE = 5;
		static const uint8_t OUT_REQUEST_SIZE = 1;
		static const uint8_t OUT_BUFFER_SIZE = 3;
		static const uint8_t NR_MAX_INPUT_MESSAGES = 5;

		static const uint8_t SETTING_MASK = 		0b00111111;
		static const uint8_t SETTING_CONST_RESULT = 0b01000000;
		static const uint8_t SETTING_BUSY = 		0b00100000;
		static const uint8_t SETTING_MODE = 		0b00011000;
		static const uint8_t SETTING_MEM_ERR = 		0b00000100;

		static constexpr float MBE_PRESURE = 49152;
		static constexpr float MBA_PRESURE = 16384;


		float sensetivetyPresure = NAN;

		//static constexpr float MBE_TEMP = 262143;
		static constexpr float MBA_TEMP = 384;
		//static constexpr float MBE_UNIT_TEMP = 64384;
		static constexpr float MBA_UNIT_TEMP = -50;

		static constexpr float SENSETIVETY_TEMP = 0.003125;

		uint8_t busAdress = 0x40;
		GPIO_TypeDef *resetPort;
		uint16_t resetPin;

		float mesuringRangeStart = NAN;
		float mesuringRangeEnd = NAN;
		MeasureUnit unit = MeasureUnit::UNDEFINED_GAUGE;
		uint32_t custNumber = 0;

		uint8_t rxBuffer[ IN_BUFFER_SIZE ];
		uint8_t txBuffer[ OUT_BUFFER_SIZE ];

		osMessageQueueId_t toISR;
		const osMessageQueueAttr_t toISR_attributes = {.name = "toIsrXld"};
		osMessageQueueId_t fromISR;
		const osMessageQueueAttr_t fromISR_attributes = {.name = "fromIsrXld"};
//		QueueHandle_t toISR;
//		QueueHandle_t fromISR;
		bool initialized = false;

		float pressure = 0;
		float temperature = 0;
		DMA_HandleTypeDef &dmaRecv;
		DMA_HandleTypeDef &dmaSend;
		I2C_HandleTypeDef &hi2c;

		bool busy = false;
		uint8_t mode = 0;
		bool memoryError = false;

		void DMARecvReady();
		void MTFREady();
		bool Reset();
		bool parsStatus(uint8_t status);

	public:
		xLDRefpres(uint8_t adress, I2C_HandleTypeDef &hi2cIn, DMA_HandleTypeDef &dmaReciveIn, DMA_HandleTypeDef &dmaSendIn, GPIO_TypeDef *resetPortIn, uint16_t resetPinIn);

		static void pinInterupt (xLDRefpres *instance);
		static void DMARecvInterupt (DMA_HandleTypeDef *hdma);

		float getRangeStart();
		float getRangeEnd();
		MeasureUnit getUnit();
		uint32_t getCustNr();

		float getPressure();
		float getTemperature();
		void run(dataStorage& ds);
		bool getStatus();
}; //class MTF_1

#endif /* XLDREFPRES_HPP_ */
