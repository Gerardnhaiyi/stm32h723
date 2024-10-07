/********************************************************************************************************************************
 *	File name:				dataUint16.cpp
 *
 *	File Description:		Implementation of the dataUint16 class. a storage class for uint16s.
 *
 ********************************************************************************************************************************/

#include "dataUint16.hpp"
#include "dataClass.hpp"
#include <cstring>

/********************************************************************************************************************************
 *	Method name:			dataUint16::dataUint16
 *
 *	Method Description:		Constructor for the dataFloat class. sets up class with default values and parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataUint16::dataUint16() : dataUint16( 0, 0, 0, 0, NO_FLASH, NO_MODBUS, paramNames::MAX_PARAMS, accessLevel::MEDIUM, false )
{
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::dataUint16
 *
 *	Method Description:		Constructor for the dataFloat class. sets up class with default values while using the given
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
dataUint16::dataUint16( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataUint16( 0, 0, 0, 0, flashAdressIn, modbusAdressIn,
        nameIn, accessLevelIn, readOnlyIn )
{
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::dataUint16
 *
 *	Method Description:		Constructor for the dataFloat class. sets up class with the given values and parameters.
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
dataUint16::dataUint16( uint16_t valueIn, uint16_t minIn, uint16_t maxIn, uint16_t defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
        bool readOnlyIn ) : dataClass( flashAdressIn, modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, dataType::UINT16 ), min( minIn ), max( minIn )
{
	setMax( maxIn );
	setDefault( defaultValueIn );
	setValue( valueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::~dataUint16
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataUint16::~dataUint16()
{
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::getValue
 *
 *	Method Description:		Getter for the value.
 *
 *	Entry:					None
 *
 *	exit:					uint16_t 			Value.
 *
 ********************************************************************************************************************************/
uint16_t dataUint16::getValue()
{
	return ( value );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::setValue
 *
 *	Method Description:		Setter for the value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataUint16::setValue( uint16_t valueIn )
{
	if ( valueIn > min )
	{
		if ( valueIn < max )
		{
			value = valueIn;
		}
		else
		{
			value = max;
		}
	}
	else
	{
		value = min;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::getMin
 *
 *	Method Description:		Getter for the minimum value.
 *
 *	Entry:					None
 *
 *	exit:					uint16_t 			minimum value.
 *
 ********************************************************************************************************************************/
uint16_t dataUint16::getMin()
{
	return ( min );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::setMin
 *
 *	Method Description:		Setter for the minimum value. if this is above the maximum value the input is ignored.
 *
 *	Entry:					minIn			minimum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataUint16::setMin( uint16_t minIn )
{
	if ( minIn <= max )
	{
		min = minIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::getMax
 *
 *	Method Description:		Getter for the maximum value.
 *
 *	Entry:					None
 *
 *	exit:					uint16_t 			maximum value.
 *
 ********************************************************************************************************************************/
uint16_t dataUint16::getMax()
{
	return ( max );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::setMax
 *
 *	Method Description:		Setter for the maximum value. if this is below the minimum value the input is ignored.
 *
 *	Entry:					maxIn			maximum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataUint16::setMax( uint16_t maxIn )
{
	if ( maxIn >= min )
	{
		max = maxIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::getDefault
 *
 *	Method Description:		Getter for the default value.
 *
 *	Entry:					None
 *
 *	exit:					uint16_t 			Default value.
 *
 ********************************************************************************************************************************/
uint16_t dataUint16::getDefault()
{
	return ( defaultValue );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::setDefault
 *
 *	Method Description:		Setter for the default value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Default value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataUint16::setDefault( uint16_t defaultValueIn )
{
	if ( defaultValueIn > min )
	{
		if ( defaultValueIn < max )
		{
			defaultValue = defaultValueIn;
		}
		else
		{
			defaultValue = max;
		}
	}
	else
	{
		defaultValue = min;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::getByteSize
 *
 *	Method Description:		Gets the amount of bytes of the value
 *
 *							Overrides dataClass::getByteSize
 *
 *	Entry:					None
 *
 *	exit:					size_t 			Number of bytes.
 *
 ********************************************************************************************************************************/
size_t dataUint16::getByteSize()
{
	return ( sizeof( value ) );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::setToDefault
 *
 *	Method Description:		Sets the value to the default value
 *
 *							Overrides dataClass::setToDefault
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataUint16::setToDefault()
{
	value = defaultValue;
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::toBytes
 *
 *	Method Description:		copy's the value the the buffer if the amount of free bytes is large enough.
 *
 *							Overrides dataClass::toBytes
 *
 *	Entry:					buffer		A pointer to the buffer to copy the value to.
 *							bytesfree	the amount of bytes available in the buffer.
 *
 *	exit:					size_t		the amount of bytes copied to the buffer.
 *
 ********************************************************************************************************************************/
size_t dataUint16::toBytes( uint8_t *buffer, size_t bytesfree )
{
	if ( getByteSize() <= bytesfree )
	{
		uint16_t tempValue = value;
		memcpy( buffer, &tempValue, getByteSize() );
		return ( getByteSize() );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::fromBytes
 *
 *	Method Description:		copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *							Overrides dataClass::fromBytes
 *
 *	Entry:					buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *
 *	exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *
 ********************************************************************************************************************************/
dataErrors dataUint16::fromBytes( uint8_t *buffer, size_t bytesAvaleble )
{
	if ( getByteSize() <= bytesAvaleble )
	{
		uint16_t tempValue;
		memcpy( &tempValue, buffer, getByteSize() );
		if ( tempValue > min && tempValue < max )
		{
			value = tempValue;
		}
		else
		{
			return ( dataErrors::OUT_OF_RANGE );
		}
		return ( dataErrors::SUCCESS );
	}
	return ( dataErrors::SIZE_ERROR );
}

/********************************************************************************************************************************
 *	Method name:			dataUint16::fromBytes
 *
 *	Method Description:		copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will check for access level and read only tag
 *
 *							This function is intended to be called from outside communication protocols.
 *
 *							Overrides dataClass::fromBytes
 *
 *	Entry:					buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *							userAccessLevel	The access level of the calling unit.
 *
 *	Exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											NO_RIGHTS		Access level to low or read only value.
 *
 ********************************************************************************************************************************/
dataErrors dataUint16::fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	if ( userAccessLevel >= accessLevelSet && !readOnly )
	{
		return ( fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::NO_RIGHTS );
}
