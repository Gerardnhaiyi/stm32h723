/********************************************************************************************************************************
 *	File name:				dataFloat.cpp
 *
 *	File Description:		Implementation of the dataFloat class. a storage class for floats.
 *
 ********************************************************************************************************************************/

#include "dataFloat.hpp"
#include "dataClass.hpp"
#include <cstring>

/********************************************************************************************************************************
 *	Method name:			dataFloat::limitValue
 *
 *	Method Description:		Check if valueIn is within minimum and maximum. Set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Value to be Checked.
 *
 *	exit:					float			Value checked and limited.
 *
 ********************************************************************************************************************************/
float dataFloat::limitValue( float valueIn )
{
	if ( valueIn > min )
	{
		if ( valueIn < max )
		{
			return ( valueIn );
		}
		else
		{
			return ( max );
		}
	}
	return ( min );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::dataFloat
 *
 *	Method Description:		Constructor for the dataFloat class. sets up class with default values and parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloat::dataFloat() : dataFloat( 0.0, 0.0, 0.0, 0.0, NO_FLASH, NO_MODBUS, paramNames::MAX_PARAMS, accessLevel::MEDIUM, false )
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::dataFloat
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
dataFloat::dataFloat( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataFloat( 0.0, 0.0, 0.0, 0.0, flashAdressIn, modbusAdressIn,
        nameIn, accessLevelIn, readOnlyIn )
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::dataFloat
 *
 *	Method Description:		Constructor for the dataFloat class. sets up class using the given parameters.
 *							This function is intended to be called from a class that inherits this class to set the datatype.
 *
 *	Entry:					flashAdressIn		The address of the first byte in the flash.
 *							modbusAdressIn		The address of the first byte on the modbus
 *							nameIn				The name of the variable (from the enum)
 *							accessLevelIn		The access level for the variable. mainly for external communications.
 *							readOnlyIn			If the variable is read only or not.
 *							dataTypeIn			the Datatype to set.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloat::dataFloat( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn, dataType dataTypeIn ) : dataClass( flashAdressIn, modbusAdressIn,
        nameIn, accessLevelIn, readOnlyIn, dataTypeIn )
{
}
/********************************************************************************************************************************
 *	Method name:			dataFloat::dataFloat
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
dataFloat::dataFloat( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataClass(
        flashAdressIn, modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, dataType::FLOAT ), min( minIn ), max( minIn )
{
	setMax( maxIn );
	defaultValue = limitValue( defaultValueIn );
	value = limitValue( valueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::~dataFloat
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataFloat::~dataFloat()
{
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::getValue
 *
 *	Method Description:		Getter for the value.
 *
 *	Entry:					None
 *
 *	exit:					Float 			Value.
 *
 ********************************************************************************************************************************/
float dataFloat::getValue()
{
	return ( value );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::setValue
 *
 *	Method Description:		Setter for the value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataFloat::setValue( float valueIn )
{
	value = limitValue( valueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::getMin
 *
 *	Method Description:		Getter for the minimum value.
 *
 *	Entry:					None
 *
 *	exit:					Float 			minimum value.
 *
 ********************************************************************************************************************************/
float dataFloat::getMin()
{
	return ( min );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::setMin
 *
 *	Method Description:		Setter for the minimum value. if this is above the maximum value the input is ignored.
 *
 *	Entry:					minIn			minimum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataFloat::setMin( float minIn )
{
	if ( minIn <= max )
	{
		min = minIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::getMax
 *
 *	Method Description:		Getter for the maximum value.
 *
 *	Entry:					None
 *
 *	exit:					Float 			maximum value.
 *
 ********************************************************************************************************************************/
float dataFloat::getMax()
{
	return ( max );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::setMax
 *
 *	Method Description:		Setter for the maximum value. if this is below the minimum value the input is ignored.
 *
 *	Entry:					maxIn			maximum value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataFloat::setMax( float maxIn )
{
	if ( maxIn >= min )
	{
		max = maxIn;
	}
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::getDefault
 *
 *	Method Description:		Getter for the default value.
 *
 *	Entry:					None
 *
 *	exit:					Float 			Default value.
 *
 ********************************************************************************************************************************/
float dataFloat::getDefault()
{
	return ( defaultValue );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::setDefault
 *
 *	Method Description:		Setter for the default value. set to minimum or maximum if the value is out of range.
 *
 *	Entry:					valueIn			Default value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataFloat::setDefault( float defaultValueIn )
{
	defaultValue = limitValue( defaultValueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::getByteSize
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
size_t dataFloat::getByteSize()
{
	return ( sizeof( value ) );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::setToDefault
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
void dataFloat::setToDefault()
{
	value = defaultValue;
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::toBytes
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
size_t dataFloat::toBytes( uint8_t *buffer, size_t bytesfree )
{
	if ( getByteSize() <= bytesfree )
	{
		float tempValue = value;
		memcpy( buffer, &tempValue, getByteSize() );
		return ( getByteSize() );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::fromBytes
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
dataErrors dataFloat::fromBytes( uint8_t *buffer, size_t bytesAvaleble )
{
	if ( getByteSize() <= bytesAvaleble )
	{
		float tempValue;
		memcpy( &tempValue, buffer, getByteSize() );
		if ( tempValue > min && tempValue < max )
		{
			value = tempValue;
			return ( dataErrors::SUCCESS );
		}
		return ( dataErrors::OUT_OF_RANGE );
	}
	return ( dataErrors::SIZE_ERROR );
}

/********************************************************************************************************************************
 *	Method name:			dataFloat::fromBytes
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
dataErrors dataFloat::fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	if ( userAccessLevel >= accessLevelSet && !readOnly )
	{
		return ( fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::NO_RIGHTS );
}
