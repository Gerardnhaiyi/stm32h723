/*
 * dataFloatTrend.cpp
 *
 *  Created on: Nov 24, 2023
 *      Author: Martinv
 */

#include "dataFloat.hpp"
#include "dataFloatTrend.hpp"

#include <cmath>
#include "cmsis_os.h"
#include "semphr.h"

#define MUTEX_WAIT_TIME (static_cast< TickType_t >( 100 ))

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::dataFloatTrend
 *
 *	Method Description:		Constructor for the dataFloatTrend class. sets up class with default values and parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloatTrend::dataFloatTrend() : dataFloatTrend( 0.0, 0.0, 0.0, 0.0, NO_FLASH, NO_MODBUS, paramNames::MAX_PARAMS, accessLevel::MEDIUM, false, TRENDBUFFERSIZE )
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::dataFloatTrend
 *
 *	Method Description:		Constructor for the dataFloatTrend class. sets up class with default values while using the given
 *							parameters.
 *
 *	Entry:					flashAdressIn		The address of the first byte in the flash.
 *							modbusAdressIn		The address of the first byte on the modbus
 *							nameIn				The name of the variable (from the enum)
 *							accessLevelIn		The access level for the variable. mainly for external communications.
 *							readOnlyIn			If the variable is read only or not.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloatTrend::dataFloatTrend( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataFloatTrend( 0.0, 0.0, 0.0, 0.0, flashAdressIn,
        modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, TRENDBUFFERSIZE )
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::dataFloatTrend
 *
 *	Method Description:		Constructor for the dataFloatTrend class. sets up class with the given values and parameters.
 *
 *	Entry:					valueIn				The value, must be between the minimum and maximum
 *							minIn				The minimum value
 *							maxIn				The maximum value, can't be lower than the minimum value
 *							defaultValueIn		The default value, must be between the minimum and maximum
 *							flashAdressIn		The address of the first byte in the flash.
 *							modbusAdressIn		The address of the first byte on the modbus
 *							nameIn				The name of the variable (from the enum)
 *							accessLevelIn		The access level for the variable. mainly for external communications.
 *							readOnlyIn			If the variable is read only or not.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloatTrend::dataFloatTrend( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
        bool readOnlyIn ) : dataFloatTrend( valueIn, minIn, maxIn, defaultValueIn, flashAdressIn,modbusAdressIn, nameIn, accessLevelIn, readOnlyIn , TRENDBUFFERSIZE )
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::dataFloatTrend
 *
 *	Method Description:		Constructor for the dataFloatTrend class. sets up class with the given values and parameters.
 *
 *	Entry:					valueIn				The value, must be between the minimum and maximum
 *							minIn				The minimum value
 *							maxIn				The maximum value, can't be lower than the minimum value
 *							defaultValueIn		The default value, must be between the minimum and maximum
 *							flashAdressIn		The address of the first byte in the flash.
 *							modbusAdressIn		The address of the first byte on the modbus
 *							nameIn				The name of the variable (from the enum)
 *							accessLevelIn		The access level for the variable. mainly for external communications.
 *							readOnlyIn			If the variable is read only or not.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloatTrend::dataFloatTrend( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
        bool readOnlyIn, uint8_t bufferSize ) : dataFloat( flashAdressIn, modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, dataType::FLOAT_TREND ), BufferLN(bufferSize <= TRENDBUFFERSIZE ? bufferSize: TRENDBUFFERSIZE )
{
	min = minIn;
	max = minIn;
	setMax( maxIn );
	defaultValue = limitValue( defaultValueIn );
	value = limitValue( valueIn );
	for(int i = 0; i < TRENDBUFFERSIZE; i++)
	{
		buffer[ i ] = value;
	}
}
/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::~dataFloatTrend
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloatTrend::~dataFloatTrend()
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::setValue
 *
 *	Method Description:		Setter for the value. set to minimum or maximum if the value is out of range.
 *							Adjusts the trend array with the new value.
 *
 *	Entry:					valueIn			Value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataFloatTrend::setValue( float valueIn )
{
	dataFloat::setValue( valueIn );

	startPosition = countA;
	endPosition = countB;
	if(countA == 255)
	{
		if ( xSemaphoreTake( mutex, MUTEX_WAIT_TIME ) == pdTRUE ) // @suppress("C-Style cast instead of C++ cast")
		{
			for(uint8_t i = 0; i < BufferLN; i ++)
			{
				buffer[i] = value;
			}
			xSemaphoreGive( mutex ); // @suppress("C-Style cast instead of C++ cast")
		}
		countA = 1;
		countB = countA + distance*2;
	}
	else
	{
		if ( xSemaphoreTake( mutex, MUTEX_WAIT_TIME ) == pdTRUE ) // @suppress("C-Style cast instead of C++ cast")
		{
			buffer[countA] = value;
			xSemaphoreGive( mutex ); // @suppress("C-Style cast instead of C++ cast")
		}
		countA ++;
		countB = countA + distance*2;
		if(countA > distance)
		{
			IsReady = true;
		}
		countA %= BufferLN;
		countB %= BufferLN;
	}

}

/********************************************************************************************************************************
 *	Method name:			dataFloatTrend::getTrend
 *
 *	Method Description:		returns the trend value. The value will be NAN if it can't secure access to the trend buffer.
 *
 *	Entry:					None
 *
 *	exit:					float 	A value for the trend. returns NAN if buffer can't be accessed.
 *
 ********************************************************************************************************************************/
float dataFloatTrend::getTrend()
{
	//float returnValue = 0.0f;
	if(!IsReady)
	{
		return (0.0f);
	}

	if ( xSemaphoreTake( mutex, MUTEX_WAIT_TIME ) == pdTRUE ) // @suppress("C-Style cast instead of C++ cast")
	{
		float end = buffer[endPosition];
		float start = buffer[startPosition];
		xSemaphoreGive( mutex ); // @suppress("C-Style cast instead of C++ cast")
		uint8_t position = startPosition;
		if((position < endPosition))
		{
			position += BufferLN;
		}

		float valueB = (start - (start - end) / (position - endPosition));
		return (0.25 * (start - valueB));
	}
	return (NAN);
}
