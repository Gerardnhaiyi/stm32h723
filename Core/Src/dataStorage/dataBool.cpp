/********************************************************************************************************************************
 *	File name:				dataBool.cpp
 *
 *	File Description:		Implementation of the dataBool class. a storage class for booleans.
 *
 ********************************************************************************************************************************/

#include "dataBool.hpp"
#include "dataClass.hpp"
#include <cstring>

/********************************************************************************************************************************
 *	Method name:			dataBool::dataBool
 *
 *	Method Description:		Constructor for the dataBool class. sets up class with default values and parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataBool::dataBool() : dataBool( false, false, NO_FLASH, NO_MODBUS, paramNames::MAX_PARAMS, accessLevel::MEDIUM, false )
{
}

/********************************************************************************************************************************
 *	Method name:			dataBool::dataBool
 *
 *	Method Description:		Constructor for the dataBool class. sets up class with default values while using the given
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
dataBool::dataBool( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataBool( false, false, flashAdressIn, modbusAdressIn, nameIn,
        accessLevelIn, readOnlyIn )
{
}

/********************************************************************************************************************************
 *	Method name:			dataBool::dataBool
 *
 *	Method Description:		Constructor for the dataBool class. sets up class with the given values and parameters.
 *
 *	Entry:					valueIn				The value, must be between the minimum and maximum
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
dataBool::dataBool( bool valueIn, bool defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataClass( flashAdressIn,
        modbusAdressIn, nameIn, accessLevelIn, readOnlyIn, dataType::BOOL )
{
	setDefault( defaultValueIn );
	setValue( valueIn );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::dataBool
 *
 *	Method Description:		Constructor for the dataBool class. sets up class with the given values and parameters.
 *
 *	Entry:					valueIn				The value, must be between the minimum and maximum
 *							minIn				Ignored with booleans
 *							maxIn				Ignored with booleans
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
dataBool::dataBool( bool valueIn, bool minIn, bool maxIn, bool defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn ) : dataBool(
        valueIn, defaultValueIn, flashAdressIn, modbusAdressIn, nameIn, accessLevelIn, readOnlyIn )
{

}

/********************************************************************************************************************************
 *	Method name:			dataBool::~dataBool
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataBool::~dataBool()
{
}

/********************************************************************************************************************************
 *	Method name:			dataBool::getValue
 *
 *	Method Description:		Getter for the value.
 *
 *	Entry:					None
 *
 *	exit:					bool 			Value.
 *
 ********************************************************************************************************************************/
bool dataBool::getValue()
{
	return ( value );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::setValue
 *
 *	Method Description:		Setter for the value.
 *
 *	Entry:					valueIn			Value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataBool::setValue( bool valueIn )
{

	value = valueIn;
}

/********************************************************************************************************************************
 *	Method name:			dataBool::getDefault
 *
 *	Method Description:		Getter for the default value.
 *
 *	Entry:					None
 *
 *	exit:					bool 			Default value.
 *
 ********************************************************************************************************************************/
bool dataBool::getDefault()
{
	return ( defaultValue );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::setDefault
 *
 *	Method Description:		Setter for the default value.
 *
 *	Entry:					valueIn			Default value to be set.
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataBool::setDefault( bool defaultValueIn )
{
	defaultValue = defaultValueIn;
}

/********************************************************************************************************************************
 *	Method name:			dataBool::getByteSize
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
size_t dataBool::getByteSize()
{
	return ( sizeof( value ) );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::setToDefault
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
void dataBool::setToDefault()
{
	value = defaultValue;
}

/********************************************************************************************************************************
 *	Method name:			dataBool::toBytes
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
size_t dataBool::toBytes( uint8_t *buffer, size_t bytesfree )
{
	if ( getByteSize() <= bytesfree )
	{
		*buffer = value;
		return ( getByteSize() );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::fromBytes
 *
 *	Method Description:		copy's the bytes in the buffer to value
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
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *
 ********************************************************************************************************************************/
dataErrors dataBool::fromBytes( uint8_t *buffer, size_t bytesAvaleble )
{
	if ( getByteSize() <= bytesAvaleble )
	{
		value = *buffer;
		return ( dataErrors::SUCCESS );
	}
	return ( dataErrors::SIZE_ERROR );
}

/********************************************************************************************************************************
 *	Method name:			dataBool::fromBytes
 *
 *	Method Description:		copy's the bytes in the buffer to value
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
dataErrors dataBool::fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	if ( userAccessLevel >= accessLevelSet && !readOnly )
	{
		return ( fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::NO_RIGHTS );
}
