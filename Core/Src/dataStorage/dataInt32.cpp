/********************************************************************************************************************************
 *	File name:				dataInt32.cpp
 *
 *	File Description:		Implementation of the dataInt32 class. a storage class for int32s.
 *
 ********************************************************************************************************************************/

#include "dataInt32.hpp"
#include "dataClass.hpp"
#include <cstring>

/********************************************************************************************************************************
 *	Method name:			dataInt32::dataInt32
 *
 *	Method Description:		Constructor for the dataInt32 class. sets up class with default values and parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataInt32::dataInt32() : dataInt32( 0, 0, 0, 0, NO_FLASH, NO_MODBUS, paramNames::MAX_PARAMS, accessLevel::MEDIUM, false )
{
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::dataInt32
 *
 *	Method Description:		Constructor for the dataInt32 class. sets up class with default values while using the given
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
dataInt32::dataInt32( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataInt32( 0, 0, 0, 0, flashAdressIn, modbusAdressIn, nameIn,
        accessLevelIn, readOnlyIn )
{
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::dataInt32
 *
 *	Method Description:		Constructor for the dataInt32 class. sets up class with the given values and parameters.
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
dataInt32::dataInt32( int32_t valueIn, int32_t minIn, int32_t maxIn, int32_t defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
        bool readOnlyIn ) : dataClass( flashAdressIn, modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, dataType::INT32 ), min( minIn ), max( minIn )
{
	setMax( maxIn );
	setDefault( defaultValueIn );
	setValue( valueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::~dataInt32
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataInt32::~dataInt32()
{
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::getValue
 *
 *	Method Description:		Getter for the value.
 *
 *	Entry:					None
 *
 *	exit:					int32_t 			Value.
 *
 ********************************************************************************************************************************/
int32_t dataInt32::getValue()
{
	return ( value );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::setValue
 *
 *	Method Description:		Setter for the value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataInt32::setValue( int32_t valueIn )
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
 *	Method name:			dataInt32::getMin
 *
 *	Method Description:		Getter for the minimum value.
 *
 *	Entry:					None
 *
 *	exit:					int32_t 			minimum value.
 *
 ********************************************************************************************************************************/
int32_t dataInt32::getMin()
{
	return ( min );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::setMin
 *
 *	Method Description:		Setter for the minimum value. if this is above the maximum value the input is ignored.
 *
 *	Entry:					minIn			minimum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataInt32::setMin( int32_t minIn )
{
	if ( minIn <= max )
	{
		min = minIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::getMax
 *
 *	Method Description:		Getter for the maximum value.
 *
 *	Entry:					None
 *
 *	exit:					int32_t 			maximum value.
 *
 ********************************************************************************************************************************/
int32_t dataInt32::getMax()
{
	return ( max );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::setMax
 *
 *	Method Description:		Setter for the maximum value. if this is below the minimum value the input is ignored.
 *
 *	Entry:					maxIn			maximum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataInt32::setMax( int32_t maxIn )
{
	if ( maxIn >= min )
	{
		max = maxIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::getDefault
 *
 *	Method Description:		Getter for the default value.
 *
 *	Entry:					None
 *
 *	exit:					int32_t 			Default value.
 *
 ********************************************************************************************************************************/
int32_t dataInt32::getDefault()
{
	return ( defaultValue );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::setDefault
 *
 *	Method Description:		Setter for the default value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Default value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataInt32::setDefault( int32_t defaultValueIn )
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
 *	Method name:			dataInt32::getByteSize
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
size_t dataInt32::getByteSize()
{
	return ( sizeof( value ) );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::setToDefault
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
void dataInt32::setToDefault()
{
	value = defaultValue;
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::toBytes
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
size_t dataInt32::toBytes( uint8_t *buffer, size_t bytesfree )
{
	if ( getByteSize() <= bytesfree )
	{
		int32_t tempValue = value;
		memcpy( buffer, &tempValue, getByteSize() );
		return ( getByteSize() );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataInt32::fromBytes
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
dataErrors dataInt32::fromBytes( uint8_t *buffer, size_t bytesAvaleble )
{
	if ( getByteSize() <= bytesAvaleble )
	{
		int32_t tempValue;
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
 *	Method name:			dataInt32::fromBytes
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
dataErrors dataInt32::fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	if ( userAccessLevel >= accessLevelSet && !readOnly )
	{
		return ( fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::NO_RIGHTS );
}
