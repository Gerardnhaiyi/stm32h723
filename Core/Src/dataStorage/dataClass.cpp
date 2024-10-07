/********************************************************************************************************************************
 *	File name:				dataClass.cpp
 *
 *	File Description:		Implementation of the dataClass class. a template for storage classes. contains some general
 *							functions and some empty implementation to stop the compiler from complaining.
 *
 ********************************************************************************************************************************/

#include "paramNames.hpp"
#include "dataClass.hpp"

/********************************************************************************************************************************
 *	Method name:			dataClass::dataClass
 *
 *	Method Description:		Constructor for the dataClass class. sets up class with default parameters.
 *
 *	Entry:					None.
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataClass::dataClass() : flashAdress( NO_FLASH ), modbusAdress( NO_MODBUS ), name( paramNames::MAX_PARAMS ), accessLevelSet( accessLevel::MEDIUM ), readOnly( false ), dataTypeSet( dataType::NONE )
{
}

/********************************************************************************************************************************
 *	Method name:			dataClass::dataClass
 *
 *	Method Description:		Constructor for the dataClass class. sets up class with the given parameters.
 *
 *	Entry:					flashAdressIn		The address of the first byte in the flash.
 *							modbusAdressIn		The address of the first byte on the modbus
 *							nameIn				The name of the variable (from the enum)
 *							accessLevelIn		The access level for the variable. mainly for external communications.
 *							readOnlyIn			If the variable is read only or not.
 *							dataTypeIn			The data type used in the final implementation of the dataClass
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataClass::dataClass( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn, dataType dataTypeIn ) : flashAdress( flashAdressIn ), modbusAdress(
        modbusAdressIn ), name( nameIn ), accessLevelSet( accessLevelIn ), readOnly( readOnlyIn ), dataTypeSet( dataTypeIn )
{
}
/********************************************************************************************************************************
 *	Method name:			dataClass::~dataClass
 *
 *	Method Description:		Destuctor.compiler was complaining about not having a destructor. destroctor is not doing anything.
 *
 *	Entry:					None
 *
 *	exit:					None.
 *
 ********************************************************************************************************************************/
dataClass::~dataClass()
{
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getModbusAdress
 *
 *	Method Description:		Getter for the modbus address.
 *
 *	Entry:					None
 *
 *	exit:					uint16_t 			modbus address.
 *
 ********************************************************************************************************************************/
uint16_t dataClass::getModbusAdress()
{
	return ( modbusAdress );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getFlashAdress
 *
 *	Method Description:		Getter for the flash address.
 *
 *	Entry:					None
 *
 *	exit:					uint32_t 			flash address.
 *
 ********************************************************************************************************************************/
uint32_t dataClass::getFlashAdress()
{
	return ( flashAdress );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getReadOnly
 *
 *	Method Description:		Getter for the read only flag.
 *
 *	Entry:					None
 *
 *	exit:					bool 			the read only flag.
 *
 ********************************************************************************************************************************/
bool dataClass::getReadOnly()
{
	return ( readOnly );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getDataType
 *
 *	Method Description:		Getter for the data type.
 *
 *	Entry:					None
 *
 *	exit:					dataType 			the data type of the data stored.
 *
 ********************************************************************************************************************************/
dataType dataClass::getDataType()
{
	return ( dataTypeSet );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getName
 *
 *	Method Description:		Getter for the name.
 *
 *	Entry:					None
 *
 *	exit:					paramNames 			the name of data stored.
 *
 ********************************************************************************************************************************/
paramNames dataClass::getName()
{
	return ( name );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getAccessLevel
 *
 *	Method Description:		Getter for the access level.
 *
 *	Entry:					None
 *
 *	exit:					accessLevel 			the access level of data stored.
 *
 ********************************************************************************************************************************/
accessLevel dataClass::getAccessLevel()
{
	return ( accessLevelSet );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::getByteSize
 *
 *	Method Description:		placeholder getter for the byte size of the data stored.
 *
 *							Override in implementation class
 *
 *	Entry:					None
 *
 *	exit:					size_t 			byte size of the data stored.
 *
 ********************************************************************************************************************************/
size_t dataClass::getByteSize()
{
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::setToDefault
 *
 *	Method Description:		placeholder set to default.
 *
 *							Override in implementation class
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
void dataClass::setToDefault()
{
}

/********************************************************************************************************************************
 *	Method name:			dataClass::toBytes
 *
 *	Method Description:		placeholder copy's the value the the buffer if the amount of free bytes is large enough.
 *
 *							Override in implementation class
 *
 *	Entry:					buffer		A pointer to the buffer to copy the value to.
 *							bytesfree	the amount of bytes available in the buffer.
 *
 *	exit:					size_t		the amount of bytes copied to the buffer.
 *
 ********************************************************************************************************************************/
size_t dataClass::toBytes( uint8_t *buffer, size_t bytesfree )
{
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::fromBytes
 *
 *	Method Description:		placeholder copy's the bytes in the buffer to value it checks if the value is within the minimum and
 *							maximum and it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *							Override in implementation class
 *
 *	Entry:					buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *
 *	exit:					dataErrors		Status of conversion
 *											INVALID_TYPE			The type of the data is not capable to be converted.
 *
 ********************************************************************************************************************************/
dataErrors dataClass::fromBytes( uint8_t *buffer, size_t bytesAvaleble )
{
	return ( dataErrors::INVALID_TYPE );
}

/********************************************************************************************************************************
 *	Method name:			dataClass::fromBytes
 *
 *	Method Description:		placeholder copy's the bytes in the buffer to value it checks if the value is within the minimum and
 *							maximum and it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *							Override in implementation class
 *
 *	Entry:					buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *							userAccessLevel	The access level of the calling unit.
 *
 *	exit:					dataErrors		Status of conversion
 *											INVALID_TYPE			The type of the data is not capable to be converted.
 *
 ********************************************************************************************************************************/
dataErrors dataClass::fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	return ( dataErrors::INVALID_TYPE );
}
