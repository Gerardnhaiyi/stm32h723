/********************************************************************************************************************************
 *	File name:				dataStorage.cpp
 *
 *	File Description:		Implementation of the dataStorage class. this class will store all parameters and will make them
 *							available in useful manners
 *
 ********************************************************************************************************************************/

#include "dataStorage.hpp"
#include "dataFloatTrend.hpp"
#include "dataFloat.hpp"
#include "dataInt32.hpp"
#include "dataUint32.hpp"
#include "dataUint16.hpp"
#include "dataBool.hpp"
#include "dataClass.hpp"
#include "paramNames.hpp"
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the look up tables at the correct positions. checks if the parameter has a
 *							valid name. duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataClass *dataInput )
{
	bool returnVall = false;

	if ( dataInput->getName() < paramNames::MAX_PARAMS )
	{
		if ( getDataName( dataInput->getName() ) == NULL )
		{
			datapoint[ static_cast< uint16_t >( dataInput->getName() ) ] = dataInput;
			returnVall = true;
		}

		if ( dataInput->getModbusAdress() < MAX_MODBUS_ADRESS )
		{
			datapointModbus[ dataInput->getModbusAdress() ] = getDataName( dataInput->getName() );
		}
		if ( dataInput->getFlashAdress() < MAX_FLASH_ADRESS )
		{
			datapointFlash[ dataInput->getFlashAdress() ] = getDataName( dataInput->getName() );
		}
	}
	return ( returnVall );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataFloat dataInput )
{
	if ( floatFilled < AMOUNT_OF_FLOATS )
	{
		dataFloatStorage[ floatFilled ] = dataInput;
		bool returnval = addValue( &( dataFloatStorage[ floatFilled ] ) );
		if ( returnval )
		{
			floatFilled++;
		}
		return ( returnval );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataFloatTrend dataInput )
{
	if ( FloatTrendFilled < AMOUNT_OF_FLOATS )
	{
		dataFloatTrendStorage[ FloatTrendFilled ] = dataInput;
		bool returnval = addValue( &( dataFloatTrendStorage[ FloatTrendFilled ] ) );
		if ( returnval )
		{
			FloatTrendFilled++;
		}
		return ( returnval );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataInt32 dataInput )
{
	if ( int32Filled < AMOUNT_OF_INT32S )
	{
		dataInt32Storage[ int32Filled ] = dataInput;
		bool returnval = addValue( &( dataInt32Storage[ int32Filled ] ) );
		if ( returnval )
		{
			int32Filled++;
		}
		return ( returnval );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataUint32 dataInput )
{
	if ( uint32Filled < AMOUNT_OF_UINT32S )
	{
		dataUint32Storage[ uint32Filled ] = dataInput;
		bool returnval = addValue( &( dataUint32Storage[ uint32Filled ] ) );
		if ( returnval )
		{
			uint32Filled++;
		}
		return ( returnval );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataUint16 dataInput )
{
	if ( uint16Filled < AMOUNT_OF_UINT16S )
	{
		dataUint16Storage[ uint16Filled ] = dataInput;
		bool returnval = addValue( &( dataUint16Storage[ uint16Filled ] ) );
		if ( returnval )
		{
			uint16Filled++;
		}
		return ( returnval );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::addValue
 *
 *	Method Description:		Adds a parameter to the storage arrays and to the look up tables at the correct positions.
 *							checks if there is room for the type of parameter and if the parameter has a valid name.
 *							duplicates will report success and will have there modbus and flesh adress added to the
 *							lookup table with the original value and type.
 *
 *	Entry:					dataInput	the parameter to add.
 *
 *	exit:					bool		parameter added successfully.
 *
 ********************************************************************************************************************************/
bool dataStorage::addValue( dataBool dataInput )
{
	if ( boolFilled < AMOUNT_OF_UINT16S )
	{
		dataBoolStorage[ boolFilled ] = dataInput;
		bool returnval = addValue( &( dataBoolStorage[ boolFilled ] ) );
		if ( returnval )
		{
			boolFilled++;
		}
		return ( returnval );
	}
	return ( false );
}
/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataTypeName
 *
 *	Method Description:		Returns the type of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataType			The type of the parameter if a known name is given, else NONE
 *
 ********************************************************************************************************************************/
dataType dataStorage::getDataTypeName( paramNames name )
{
	dataClass *temp = getDataName( name );
	if ( temp != NULL )
	{
		return ( temp->getDataType() );
	}
	return ( dataType::NONE );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataName
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataClass*			The parameter if a known name is given, else NULL
 *
 ********************************************************************************************************************************/
dataClass* dataStorage::getDataName( paramNames name )
{
	if ( name < paramNames::MAX_PARAMS )
	{
		return ( datapoint[ static_cast< uint16_t >( name ) ] );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataflash
 *
 *	Method Description:		Returns the parameter by its flash address
 *
 *	Entry:					flassAdress			The flash address of the parameter
 *
 *	exit:					dataClass*			The parameter if a known address is given, else NULL
 *
 ********************************************************************************************************************************/
dataClass* dataStorage::getDataflash( uint32_t flassAdress )
{
	if ( flassAdress < MAX_FLASH_ADRESS )
	{
		return ( datapointFlash[ flassAdress ] );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataModbus
 *
 *	Method Description:		Returns the parameter by its modus address
 *
 *	Entry:					modbusAdress		The modbus address of the parameter
 *
 *	exit:					dataClass*			The parameter if a known address is given, else NULL
 *
 ********************************************************************************************************************************/
dataClass* dataStorage::getDataModbus( uint16_t modbusAdress )
{
	if ( modbusAdress < MAX_MODBUS_ADRESS )
	{
		return ( datapointModbus[ modbusAdress ] );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataFloatTrendName
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataFloatTrend		The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataFloatTrend* dataStorage::getDataFloatTrendName( paramNames name )
{
	dataFloatTrend *temp = static_cast< dataFloatTrend* >( getDataName( name ) );
	if ( temp != NULL && ( temp->getDataType() == dataType::FLOAT_TREND ) )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataFloatName
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataFloat*			The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataFloat* dataStorage::getDataFloatName( paramNames name )
{
	dataFloat *temp = static_cast< dataFloat* >( getDataName( name ) );
	if ( temp != NULL && ( temp->getDataType() == dataType::FLOAT || temp->getDataType() == dataType::FLOAT_TREND ) )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataBoolName
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataBool*			The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataBool* dataStorage::getDataBoolName( paramNames name )
{
	dataBool *temp = static_cast< dataBool* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::BOOL )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataInt32Name
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataInt32*			The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataInt32* dataStorage::getDataInt32Name( paramNames name )
{
	dataInt32 *temp = static_cast< dataInt32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::INT32 )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataUint16Name
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataUint16*			The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataUint16* dataStorage::getDataUint16Name( paramNames name )
{
	dataUint16 *temp = static_cast< dataUint16* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT16 )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getDataUint32Name
 *
 *	Method Description:		Returns the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					dataUint32*			The parameter if a known name is given, and the correct type is called.
 *												else NULL
 *
 ********************************************************************************************************************************/
dataUint32* dataStorage::getDataUint32Name( paramNames name )
{
	dataUint32 *temp = static_cast< dataUint32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT32 )
	{
		return ( temp );
	}
	return ( NULL );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getFloatValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					float				The value if a known name is given, and the correct type is called.
 *												else NAN
 *
 ********************************************************************************************************************************/
float dataStorage::getFloatValueName( paramNames name )
{
	dataFloat *temp = static_cast< dataFloat* >( getDataName( name ) );
	if ( temp != NULL && ( temp->getDataType() == dataType::FLOAT || temp->getDataType() == dataType::FLOAT_TREND ) )
	{
		return ( temp->getValue() );
	}
	return ( NAN );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getFloatTrendValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					float 	A value for the trend. returns NAN if the varable is the wrong type.
 *
 ********************************************************************************************************************************/
float dataStorage::getFloatTrendValueName( paramNames name )
{
	dataFloatTrend *temp = static_cast< dataFloatTrend* >( getDataName( name ) );
	if ( temp != NULL && ( temp->getDataType() == dataType::FLOAT_TREND ) )
	{
		return ( temp->getTrend() );
	}
	return ( NAN );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getBoolValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					bool				The value if a known name is given, and the correct type is called.
 *												else false
 *
 ********************************************************************************************************************************/
bool dataStorage::getBoolValueName( paramNames name )
{
	dataBool *temp = static_cast< dataBool* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::BOOL )
	{
		return ( temp->getValue() );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getInt32ValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					int32_t				The value if a known name is given, and the correct type is called.
 *												else INT32_MIN
 *
 ********************************************************************************************************************************/
int32_t dataStorage::getInt32ValueName( paramNames name )
{
	dataInt32 *temp = static_cast< dataInt32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::INT32 )
	{
		return ( temp->getValue() );
	}
	return ( INT32_MIN );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getUint16ValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					uint16_t			The value if a known name is given, and the correct type is called.
 *												else UINT16_MAX
 *
 ********************************************************************************************************************************/
uint16_t dataStorage::getUint16ValueName( paramNames name )
{
	dataUint16 *temp = static_cast< dataUint16* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT16 )
	{
		return ( temp->getValue() );
	}
	return ( UINT16_MAX );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::getUint32ValueName
 *
 *	Method Description:		Returns the value of the parameter by its name
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *
 *	exit:					uint32_t			The value if a known name is given, and the correct type is called.
 *												else UINT32_MAX
 *
 ********************************************************************************************************************************/
uint32_t dataStorage::getUint32ValueName( paramNames name )
{
	dataUint32 *temp = static_cast< dataUint32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT32 )
	{
		return ( temp->getValue() );
	}
	return ( UINT32_MAX );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::setFloatValueName
 *
 *	Method Description:		sets the value of the parameter by its name. checks if the parameter is the correct type.
 *							will set the value to min or max if it is outside the range.
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *							value				The new value of the parameter.
 *
 *
 *	exit:					bool				The value is set.
 *
 ********************************************************************************************************************************/
bool dataStorage::setFloatValueName( paramNames name, float value )
{
	dataFloat *temp = static_cast< dataFloat* >( getDataName( name ) );
	if ( temp != NULL && ( temp->getDataType() == dataType::FLOAT  || temp->getDataType() == dataType::FLOAT_TREND ) )
	{
		temp->setValue( value );
		return ( true );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::setBoolValueName
 *
 *	Method Description:		sets the value of the parameter by its name. checks if the parameter is the correct type.
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *							value				The new value of the parameter.
 *
 *
 *	exit:					bool				The value is set.
 *
 ********************************************************************************************************************************/
bool dataStorage::setBoolValueName( paramNames name, bool value )
{
	dataBool *temp = static_cast< dataBool* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::BOOL )
	{
		temp->setValue( value );
		return ( true );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::setInt32ValueName
 *
 *	Method Description:		sets the value of the parameter by its name. checks if the parameter is the correct type.
 *							will set the value to min or max if it is outside the range.
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *							value				The new value of the parameter.
 *
 *
 *	exit:					bool				The value is set.
 *
 ********************************************************************************************************************************/
bool dataStorage::setInt32ValueName( paramNames name, int32_t value )
{
	dataInt32 *temp = static_cast< dataInt32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::INT32 )
	{
		temp->setValue( value );
		return ( true );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::setUint16ValueName
 *
 *	Method Description:		sets the value of the parameter by its name. checks if the parameter is the correct type.
 *							will set the value to min or max if it is outside the range.
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *							value				The new value of the parameter.
 *
 *
 *	exit:					bool				The value is set.
 *
 ********************************************************************************************************************************/
bool dataStorage::setUint16ValueName( paramNames name, uint16_t value )
{
	dataUint16 *temp = static_cast< dataUint16* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT16 )
	{
		temp->setValue( value );
		return ( true );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::setUint32ValueName
 *
 *	Method Description:		sets the value of the parameter by its name. checks if the parameter is the correct type.
 *							will set the value to min or max if it is outside the range.
 *
 *	Entry:					name				The name of the parameter (from the enum)
 *							value				The new value of the parameter.
 *
 *
 *	exit:					bool				The value is set.
 *
 ********************************************************************************************************************************/
bool dataStorage::setUint32ValueName( paramNames name, uint32_t value )
{
	dataUint32 *temp = static_cast< dataUint32* >( getDataName( name ) );
	if ( temp != NULL && temp->getDataType() == dataType::UINT32 )
	{
		temp->setValue( value );
		return ( true );
	}
	return ( false );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::toBytesName
 *
 *	Method Description:		finds the parameter that belongs to the name and
 *							copy's the value the the buffer if the amount of free bytes is large enough.
 *
 *	Entry:					name		The name of the parameter (from the enum)
 *							buffer		A pointer to the buffer to copy the value to.
 *							bytesFree	the amount of bytes available in the buffer.
 *
 *	exit:					size_t		the amount of bytes copied to the buffer.
 *
 ********************************************************************************************************************************/
size_t dataStorage::toBytesName( paramNames name, uint8_t *buffer, size_t bytesFree )
{
	dataClass *temp = getDataName( name );
	if ( temp != NULL )
	{
		return ( temp->toBytes( buffer, bytesFree ) );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesName
 *
 *	Method Description:		finds the parameter that belongs to the name and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *	Entry:					name			The name of the parameter (from the enum)
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *
 *	exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											INVALID_ADRESS	Name not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesName( paramNames name, uint8_t *buffer, size_t bytesAvaleble )
{
	dataClass *temp = getDataName( name );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesNames
 *
 *	Method Description:		finds the parameter that belongs to the name and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will check for access level and read only tag
 *
 *							This function is intended to be called from outside communication protocols.
 *
 *	Entry:					name			The name of the parameter (from the enum)
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *							userAccessLevel	The access level of the calling unit.
 *
 *	Exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											NO_RIGHTS		Access level to low or read only value.
 *											INVALID_ADRESS	Name not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesName( paramNames name, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	dataClass *temp = getDataName( name );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble, userAccessLevel ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::toBytesFlash
 *
 *	Method Description:		finds the parameter that belongs to the flash address and
 *							copy's the value the the buffer if the amount of free bytes is large enough.
 *
 *	Entry:					flashAddress	The flash address of the parameter
 *							buffer			A pointer to the buffer to copy the value to.
 *							bytesFree		the amount of bytes available in the buffer.
 *
 *	exit:					size_t			the amount of bytes copied to the buffer.
 *
 ********************************************************************************************************************************/
size_t dataStorage::toBytesFlash( uint32_t flashAddress, uint8_t *buffer, size_t bytesFree )
{
	dataClass *temp = getDataflash( flashAddress );
	if ( temp != NULL )
	{
		return ( temp->toBytes( buffer, bytesFree ) );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesFlash
 *
 *	Method Description:		finds the parameter that belongs to the flash address and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *	Entry:					flashAddress	The flash address of the parameter
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *
 *	exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											INVALID_ADRESS	Address not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesFlash( uint32_t flashAddress, uint8_t *buffer, size_t bytesAvaleble )
{
	dataClass *temp = getDataflash( flashAddress );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesFlash
 *
 *	Method Description:		finds the parameter that belongs to the flash address and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will check for access level and read only tag
 *
 *							This function is intended to be called from outside communication protocols.
 *
 *	Entry:					flashAddress	The flash address of the parameter
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *							userAccessLevel	The access level of the calling unit.
 *
 *	Exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											NO_RIGHTS		Access level to low or read only value.
 *											INVALID_ADRESS	Address not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesFlash( uint32_t flashAddress, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	dataClass *temp = getDataflash( flashAddress );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble, userAccessLevel ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::toBytesModbus
 *
 *	Method Description:		finds the parameter that belongs to the modbus address and
 *							copy's the value the the buffer if the amount of free bytes is large enough.
 *
 *	Entry:					modbusAddress	The modbus address of the parameter
 *							buffer			A pointer to the buffer to copy the value to.
 *							bytesFree		the amount of bytes available in the buffer.
 *
 *	exit:					size_t			the amount of bytes copied to the buffer.
 *
 ********************************************************************************************************************************/
size_t dataStorage::toBytesModbus( uint16_t modbusAddress, uint8_t *buffer, size_t bytesFree )
{
	dataClass *temp = getDataModbus( modbusAddress );
	if ( temp != NULL )
	{
		return ( temp->toBytes( buffer, bytesFree ) );
	}
	return ( 0 );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesModbus
 *
 *	Method Description:		finds the parameter that belongs to the modbus address and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will not check for access level and read only tag
 *
 *	Entry:					modbusAddress	The modbus address of the parameter
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *
 *	exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											INVALID_ADRESS	Address not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesModbus( uint16_t modbusAddress, uint8_t *buffer, size_t bytesAvaleble )
{
	dataClass *temp = getDataModbus( modbusAddress );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::fromBytesModbus
 *
 *	Method Description:		finds the parameter that belongs to the modbus address and
 *							copy's the bytes in the buffer to value it checks if the value is within the minimum and maximum and
 *							it checks if there are enough bytes in the buffer to convert.
 *							This function will check for access level and read only tag
 *
 *							This function is intended to be called from outside communication protocols.
 *
 *	Entry:					modbusAddress	The modbus address of the parameter
 *							buffer			A pointer to the buffer to copy the value from.
 *							bytesAvaleble	The amount of bytes available in the buffer.
 *							userAccessLevel	The access level of the calling unit.
 *
 *	Exit:					dataErrors		Status of conversion
 *											SUCCESS			Data conversion successful
 *											OUT_OF_RANGE	New value is not within minimum and maximum value.
 *											SIZE_ERROR		Not enough bytes available for conversion.
 *											NO_RIGHTS		Access level to low or read only value.
 *											INVALID_ADRESS	Address not know/incorrect
 *
 ********************************************************************************************************************************/
dataErrors dataStorage::fromBytesModbus( uint16_t modbusAddress, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel )
{
	dataClass *temp = getDataModbus( modbusAddress );
	if ( temp != NULL )
	{
		return ( temp->fromBytes( buffer, bytesAvaleble, userAccessLevel ) );
	}
	return ( dataErrors::INVALID_ADRESS );
}

/********************************************************************************************************************************
 *	Method name:			dataStorage::dataStorage
 *
 *	Method Description:		Constructor, adds the data parameters
 *
 *	Entry:					None
 *
 *	exit:					None
 *
 ********************************************************************************************************************************/
dataStorage::dataStorage()
{
	addValue(dataUint32(1, 0, UINT32_MAX, 1, 0, 0, paramNames::INFO_SOFTWARE_VS, accessLevel::MANUFACTURER, true));
	addValue(dataUint32(1, 0, UINT32_MAX, 1, 4, 2, paramNames::INFO_HARDWARE_VS, accessLevel::MANUFACTURER, true));
	addValue(dataUint32(1, 0, UINT32_MAX, 1, 8, 4, paramNames::INFO_PARAM_VS, accessLevel::MANUFACTURER, true));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, 12, 6, paramNames::INFO_SERIAL_NO, accessLevel::MANUFACTURER, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 16672, 16, 8, paramNames::INFO_SERIAL_POST_0, accessLevel::MANUFACTURER, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 18, 9, paramNames::INFO_SERIAL_POST_1, accessLevel::MANUFACTURER, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 20, 10, paramNames::GUI_PRESSURE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 22, 11, paramNames::GUI_TEMPERATURE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 24, 12, paramNames::GUI_FLOW, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 26, 13, paramNames::GUI_VOLUME, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 28, 14, paramNames::GUI_TIME, accessLevel::NORMAL, false));
	addValue(dataUint32(1, 1, 247, 1, 50, 25, paramNames::MBUS_DEVICE_ADDRESS, accessLevel::NORMAL, false));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, NO_FLASH, 27, paramNames::EQ_DA_DATE, accessLevel::NORMAL, false));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, NO_FLASH, 29, paramNames::EQ_DA_TIME, accessLevel::NORMAL, false));
	addValue(dataUint32(0, 0, 2000, 300, NO_FLASH, 50, paramNames::STATUS_MANAGER_ON_TIME, accessLevel::FULL, true));
	addValue(dataUint32(0, 0, 2000, 300, NO_FLASH, 52, paramNames::STATUS_MANAGER_OFF_TIME, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 54, paramNames::STATUS_MANAGER_ON_COLOR_RED, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 55, paramNames::STATUS_MANAGER_ON_COLOR_GREEN, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 56, paramNames::STATUS_MANAGER_ON_COLOR_BLUE, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 57, paramNames::STATUS_MANAGER_OFF_COLOR_RED, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 58, paramNames::STATUS_MANAGER_OFF_COLOR_GREEN, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 59, paramNames::STATUS_MANAGER_OFF_COLOR_BLUE, accessLevel::FULL, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, NO_FLASH, 60, paramNames::STATUS_MANAGER_STATUS, accessLevel::NORMAL, true));
	addValue(dataBool(1, 0, 1, 1, 300, 150, paramNames::TERMINATION_RESISTOR_ENABLE, accessLevel::NORMAL, false));
	addValue(dataUint32(115200, 9600, 921600, 115200, 302, 151, paramNames::RS485_BAUDRATE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, 2, 0, 306, 153, paramNames::RS485_PARITY, accessLevel::NORMAL, false));
	addValue(dataUint16(8, 7, 9, 8, 308, 154, paramNames::RS485_DATA_BITS, accessLevel::NORMAL, false));
	addValue(dataUint16(1, 1, 2, 1, 310, 155, paramNames::RS485_STOP_BITS, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, NO_FLASH, 300, paramNames::TPS26602_USAGE_MA, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, 60, 0, NO_FLASH, 302, paramNames::TPS26602_VOLTAGE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, FLT_MAX, 0, NO_FLASH, 304, paramNames::TPS26602_POWER, accessLevel::NORMAL, true));
	addValue(dataFloat(0, -40, 125, 0, 700, 350, paramNames::SHT30_LAST_TEMPERATURE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, 100, 0, 704, 352, paramNames::SHT30_LAST_HUMIDITY, accessLevel::NORMAL, true));
	addValue(dataBool(0, 0, 1, 0, 708, 354, paramNames::SHT30_SENSOR_STATUS_CHECKSUM_STATUS, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 710, 355, paramNames::SHT30_SENSOR_STATUS_COMMAND_STATUS, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 712, 356, paramNames::SHT30_SENSOR_STATUS_SYSTEM_RESET, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 714, 357, paramNames::SHT30_SENSOR_STATUS_T_TRACKING_ALERT, accessLevel::NORMAL, true));
	addValue(dataBool(0, 0, 1, 0, 716, 358, paramNames::SHT30_SENSOR_STATUS_RH_TRACKING_ALERT, accessLevel::NORMAL, true));
	addValue(dataBool(0, 0, 1, 0, 718, 359, paramNames::SHT30_SENSOR_STATUS_HEATER_ON, accessLevel::FULL, true));
	addValue(dataBool(0, 0, 1, 0, 720, 360, paramNames::SHT30_SENSOR_STATUS_ALERT_PENDING, accessLevel::NORMAL, true));
	addValue(dataBool(0, 0, 1, 0, 722, 361, paramNames::SHT30_ALERT, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, UINT16_MAX, UINT16_MAX, 724, 362, paramNames::SHT30_GUI_UNIT, accessLevel::NORMAL, false));
	addValue(dataInt32(0, 0, 100, 80, 726, 363, paramNames::SHT30_HIGH_SET_HUMIDITY, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, -20, 125, 80, 730, 365, paramNames::SHT30_HIGH_SET_TEMPERATURE, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, 0, 100, 79, 734, 367, paramNames::SHT30_HIGH_CLEAR_HUMIDITY, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, -20, 125, 78, 738, 369, paramNames::SHT30_HIGH_CLEAR_TEMPERATURE, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, 0, 100, 10, 742, 371, paramNames::SHT30_LOW_SET_HUMIDITY, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, -20, 125, -10, 746, 373, paramNames::SHT30_LOW_SET_TEMPERATURE, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, 0, 100, 12, 750, 375, paramNames::SHT30_LOW_CLEAR_HUMIDITY, accessLevel::MEDIUM, false));
	addValue(dataInt32(0, -20, 125, -9, 754, 377, paramNames::SHT30_LOW_CLEAR_TEMPERATURE, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 4, 0, 2000, 1000, paramNames::SETPOINT_MANAGER_SETPOINT_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 1001, paramNames::SETPOINT_MANAGER_RS485_SETPOINT, accessLevel::NORMAL, false));
	addValue(dataFloat(1, FLOAT_MIN, FLT_MAX, 0, 2006, 1003, paramNames::SETPOINT_MANAGER_USB_SETPOINT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 1005, paramNames::SETPOINT_MANAGER_ANALOG_SETPOINT, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 1007, paramNames::SETPOINT_MANAGER_USED_SETPOINT, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 2018, 1009, paramNames::SETPOINT_MANAGER_MIN, accessLevel::FULL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 2022, 1011, paramNames::SETPOINT_MANAGER_MAX, accessLevel::FULL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 2026, 1013, paramNames::SETPOINT_MANAGER_SLOPE_TIME, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, 2030, 1015, paramNames::SETPOINT_MANAGER_ENABLE_SLOPE, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 1, 2032, 1016, paramNames::SETPOINT_MANAGER_ENABLE_FILTER, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 1, 10000, 1, 2034, 1017, paramNames::SETPOINT_MANAGER_FILTER_WEIGHT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 1019, paramNames::SETPOINT_MANAGER_WANTED_SETPOINT, accessLevel::NORMAL, true));
	addValue(dataUint16(20547, 0, UINT16_MAX, 20547, 4000, 2000, paramNames::INFO_ID_0, accessLevel::FULL, true));
	addValue(dataUint16(21343, 0, UINT16_MAX, 21343, 4002, 2001, paramNames::INFO_ID_1, accessLevel::FULL, true));
	addValue(dataUint16(17745, 0, UINT16_MAX, 17745, 4004, 2002, paramNames::INFO_ID_2, accessLevel::FULL, true));
	addValue(dataUint16(17473, 0, UINT16_MAX, 17473, 4006, 2003, paramNames::INFO_ID_3, accessLevel::FULL, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4200, 2100, paramNames::INFO_USER_TAG_0, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4202, 2101, paramNames::INFO_USER_TAG_1, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4204, 2102, paramNames::INFO_USER_TAG_2, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4206, 2103, paramNames::INFO_USER_TAG_3, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4208, 2104, paramNames::INFO_USER_TAG_4, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4210, 2105, paramNames::INFO_USER_TAG_5, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4212, 2106, paramNames::INFO_USER_TAG_6, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4214, 2107, paramNames::INFO_USER_TAG_7, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4216, 2108, paramNames::INFO_USER_TAG_8, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4218, 2109, paramNames::INFO_USER_TAG_9, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4220, 2110, paramNames::INFO_USER_TAG_10, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4222, 2111, paramNames::INFO_USER_TAG_11, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4224, 2112, paramNames::INFO_USER_TAG_12, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4226, 2113, paramNames::INFO_USER_TAG_13, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4228, 2114, paramNames::INFO_USER_TAG_14, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4230, 2115, paramNames::INFO_USER_TAG_15, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4232, 2116, paramNames::INFO_USER_TAG_16, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4234, 2117, paramNames::INFO_USER_TAG_17, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4236, 2118, paramNames::INFO_USER_TAG_18, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4238, 2119, paramNames::INFO_USER_TAG_19, accessLevel::NORMAL, false));
	addValue(dataUint16(21093, 0, UINT16_MAX, 21093, 4400, 2200, paramNames::REFERENCE_PRESSURE_GUI_NAME_0, accessLevel::NORMAL, false));
	addValue(dataUint16(26207, 0, UINT16_MAX, 26207, 4402, 2201, paramNames::REFERENCE_PRESSURE_GUI_NAME_1, accessLevel::NORMAL, false));
	addValue(dataUint16(28786, 0, UINT16_MAX, 28786, 4404, 2202, paramNames::REFERENCE_PRESSURE_GUI_NAME_2, accessLevel::NORMAL, false));
	addValue(dataUint16(25971, 0, UINT16_MAX, 25971, 4406, 2203, paramNames::REFERENCE_PRESSURE_GUI_NAME_3, accessLevel::NORMAL, false));
	addValue(dataUint16(29557, 0, UINT16_MAX, 29557, 4408, 2204, paramNames::REFERENCE_PRESSURE_GUI_NAME_4, accessLevel::NORMAL, false));
	addValue(dataUint16(29285, 0, UINT16_MAX, 29285, 4410, 2205, paramNames::REFERENCE_PRESSURE_GUI_NAME_5, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4412, 2206, paramNames::REFERENCE_PRESSURE_GUI_NAME_6, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4414, 2207, paramNames::REFERENCE_PRESSURE_GUI_NAME_7, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4416, 2208, paramNames::REFERENCE_PRESSURE_GUI_NAME_8, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4418, 2209, paramNames::REFERENCE_PRESSURE_GUI_NAME_9, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4420, 2210, paramNames::REFERENCE_PRESSURE_GUI_NAME_10, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4422, 2211, paramNames::REFERENCE_PRESSURE_GUI_NAME_11, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4424, 2212, paramNames::REFERENCE_PRESSURE_GUI_NAME_12, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4426, 2213, paramNames::REFERENCE_PRESSURE_GUI_NAME_13, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 8224, 4428, 2214, paramNames::REFERENCE_PRESSURE_GUI_NAME_14, accessLevel::NORMAL, false));
	addValue(dataUint16(21349, 0, UINT16_MAX, 21349, 4600, 2300, paramNames::EXT_SENSOR_A_GUI_NAME_0, accessLevel::NORMAL, false));
	addValue(dataUint16(28275, 0, UINT16_MAX, 28275, 4602, 2301, paramNames::EXT_SENSOR_A_GUI_NAME_1, accessLevel::NORMAL, false));
	addValue(dataUint16(28530, 0, UINT16_MAX, 28530, 4604, 2302, paramNames::EXT_SENSOR_A_GUI_NAME_2, accessLevel::NORMAL, false));
	addValue(dataUint16(8257, 0, UINT16_MAX, 8257, 4606, 2303, paramNames::EXT_SENSOR_A_GUI_NAME_3, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4608, 2304, paramNames::EXT_SENSOR_A_GUI_NAME_4, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4610, 2305, paramNames::EXT_SENSOR_A_GUI_NAME_5, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4612, 2306, paramNames::EXT_SENSOR_A_GUI_NAME_6, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4614, 2307, paramNames::EXT_SENSOR_A_GUI_NAME_7, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4616, 2308, paramNames::EXT_SENSOR_A_GUI_NAME_8, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4618, 2309, paramNames::EXT_SENSOR_A_GUI_NAME_9, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4620, 2310, paramNames::EXT_SENSOR_A_GUI_NAME_10, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4622, 2311, paramNames::EXT_SENSOR_A_GUI_NAME_11, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4624, 2312, paramNames::EXT_SENSOR_A_GUI_NAME_12, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4626, 2313, paramNames::EXT_SENSOR_A_GUI_NAME_13, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4628, 2314, paramNames::EXT_SENSOR_A_GUI_NAME_14, accessLevel::NORMAL, false));
	addValue(dataUint16(21349, 0, UINT16_MAX, 21349, 4800, 2400, paramNames::EXT_SENSOR_B_GUI_NAME_0, accessLevel::NORMAL, false));
	addValue(dataUint16(28275, 0, UINT16_MAX, 28275, 4802, 2401, paramNames::EXT_SENSOR_B_GUI_NAME_1, accessLevel::NORMAL, false));
	addValue(dataUint16(28530, 0, UINT16_MAX, 28530, 4804, 2402, paramNames::EXT_SENSOR_B_GUI_NAME_2, accessLevel::NORMAL, false));
	addValue(dataUint16(8258, 0, UINT16_MAX, 8258, 4806, 2403, paramNames::EXT_SENSOR_B_GUI_NAME_3, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4808, 2404, paramNames::EXT_SENSOR_B_GUI_NAME_4, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4810, 2405, paramNames::EXT_SENSOR_B_GUI_NAME_5, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4812, 2406, paramNames::EXT_SENSOR_B_GUI_NAME_6, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4814, 2407, paramNames::EXT_SENSOR_B_GUI_NAME_7, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4816, 2408, paramNames::EXT_SENSOR_B_GUI_NAME_8, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4818, 2409, paramNames::EXT_SENSOR_B_GUI_NAME_9, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4820, 2410, paramNames::EXT_SENSOR_B_GUI_NAME_10, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4822, 2411, paramNames::EXT_SENSOR_B_GUI_NAME_11, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4824, 2412, paramNames::EXT_SENSOR_B_GUI_NAME_12, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4826, 2413, paramNames::EXT_SENSOR_B_GUI_NAME_13, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 4828, 2414, paramNames::EXT_SENSOR_B_GUI_NAME_14, accessLevel::NORMAL, false));
	addValue(dataUint16(21349, 0, UINT16_MAX, 21349, 5000, 2500, paramNames::EXT_SENSOR_C_GUI_NAME_0, accessLevel::NORMAL, false));
	addValue(dataUint16(28275, 0, UINT16_MAX, 28275, 5002, 2501, paramNames::EXT_SENSOR_C_GUI_NAME_1, accessLevel::NORMAL, false));
	addValue(dataUint16(28530, 0, UINT16_MAX, 28530, 5004, 2502, paramNames::EXT_SENSOR_C_GUI_NAME_2, accessLevel::NORMAL, false));
	addValue(dataUint16(8259, 0, UINT16_MAX, 8259, 5006, 2503, paramNames::EXT_SENSOR_C_GUI_NAME_3, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5008, 2504, paramNames::EXT_SENSOR_C_GUI_NAME_4, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5010, 2505, paramNames::EXT_SENSOR_C_GUI_NAME_5, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5012, 2506, paramNames::EXT_SENSOR_C_GUI_NAME_6, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5014, 2507, paramNames::EXT_SENSOR_C_GUI_NAME_7, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5016, 2508, paramNames::EXT_SENSOR_C_GUI_NAME_8, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5018, 2509, paramNames::EXT_SENSOR_C_GUI_NAME_9, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5020, 2510, paramNames::EXT_SENSOR_C_GUI_NAME_10, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5022, 2511, paramNames::EXT_SENSOR_C_GUI_NAME_11, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5024, 2512, paramNames::EXT_SENSOR_C_GUI_NAME_12, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5026, 2513, paramNames::EXT_SENSOR_C_GUI_NAME_13, accessLevel::NORMAL, false));
	addValue(dataUint16(8224, 0, UINT16_MAX, 8224, 5028, 2514, paramNames::EXT_SENSOR_C_GUI_NAME_14, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 1, 6000, 3000, paramNames::EXT_SENSOR_A_ENABLE_CHANNEL, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, 6002, 3001, paramNames::EXT_SENSOR_A_ENABLE_VIRT_GND, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 3, 0, 6004, 3002, paramNames::EXT_SENSOR_A_SENSOR_SIGNAL_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, -1, 24, 0, 6006, 3003, paramNames::EXT_SENSOR_A_SENSOR_SIGNAL_MA_V, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3005, paramNames::EXT_SENSOR_A_SENSOR_OUTPUT_CALIBRATED, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, INT32_MAX, 0, NO_FLASH, 3007, paramNames::EXT_SENSOR_A_SIGNAL_RAW, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6018, 3009, paramNames::EXT_SENSOR_A_SENSOR_MIN, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6022, 3011, paramNames::EXT_SENSOR_A_SENSOR_MAX, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6026, 3013, paramNames::EXT_SENSOR_A_A, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6030, 3015, paramNames::EXT_SENSOR_A_B, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6034, 3017, paramNames::EXT_SENSOR_A_C, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6038, 3019, paramNames::EXT_SENSOR_A_D, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 2, 0, 6042, 3021, paramNames::EXT_SENSOR_A_SENSOR_TYPE, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, 6044, 3022, paramNames::EXT_SENSOR_A_USE_MOVING_AVG, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 500, 0, 6046, 3023, paramNames::EXT_SENSOR_A_MOV_AVG_PERIODS, accessLevel::MEDIUM, false));
	addValue(dataBool(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3024, paramNames::EXT_SENSOR_A_MOVING_AVG_VALUE, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3025, paramNames::EXT_SENSOR_A_KALMAN_VALUE, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6054, 3027, paramNames::EXT_SENSOR_A_KF_VAR_MEASUREMENT, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6058, 3029, paramNames::EXT_SENSOR_A_KF_VAR_PROCESS, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 6062, 3031, paramNames::EXT_SENSOR_A_USE_KALMAN, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 3032, paramNames::EXT_SENSOR_A_FILTER_ENABLE, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 10, 0, 6066, 3033, paramNames::EXT_SENSOR_A_PROCESS_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3034, paramNames::EXT_SENSOR_A_SENSOR_SIGNAL_A, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3036, paramNames::EXT_SENSOR_A_SENSOR_SIGNAL_B, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 6076, 3038, paramNames::EXT_SENSOR_A_PARAMETERS_SIGNAL_TO_MAA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 6080, 3040, paramNames::EXT_SENSOR_A_PARAMETERS_SIGNAL_TO_MAB, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 6084, 3042, paramNames::EXT_SENSOR_A_PARAMETERS_SIGNAL_TO_VA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 6088, 3044, paramNames::EXT_SENSOR_A_PARAMETERS_SIGNAL_TO_VB, accessLevel::MANUFACTURER, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 6092, 3046, paramNames::EXT_SENSOR_A_GUI_UNIT, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 1, 6200, 3100, paramNames::EXT_SENSOR_B_ENABLE_CHANNEL, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, 6202, 3101, paramNames::EXT_SENSOR_B_ENABLE_VIRT_GND, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 3, 0, 6204, 3102, paramNames::EXT_SENSOR_B_SENSOR_SIGNAL_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, -1, 24, 0, 6206, 3103, paramNames::EXT_SENSOR_B_SENSOR_SIGNAL_MA_V, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3105, paramNames::EXT_SENSOR_B_SENSOR_OUTPUT_CALIBRATED, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, INT32_MAX, 0, NO_FLASH, 3107, paramNames::EXT_SENSOR_B_SIGNAL_RAW, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6218, 3109, paramNames::EXT_SENSOR_B_SENSOR_MIN, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6222, 3111, paramNames::EXT_SENSOR_B_SENSOR_MAX, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6226, 3113, paramNames::EXT_SENSOR_B_A, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6230, 3115, paramNames::EXT_SENSOR_B_B, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6234, 3117, paramNames::EXT_SENSOR_B_C, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6238, 3119, paramNames::EXT_SENSOR_B_D, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 2, 0, 6242, 3121, paramNames::EXT_SENSOR_B_SENSOR_TYPE, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, 6244, 3122, paramNames::EXT_SENSOR_B_USE_MOVING_AVG, accessLevel::MEDIUM, false));
	addValue(dataUint16(0, 0, 500, 0, 6246, 3123, paramNames::EXT_SENSOR_B_MOV_AVG_PERIODS, accessLevel::MEDIUM, false));
	addValue(dataBool(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3124, paramNames::EXT_SENSOR_B_MOVING_AVG_VALUE, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3125, paramNames::EXT_SENSOR_B_KALMAN_VALUE, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6254, 3127, paramNames::EXT_SENSOR_B_KF_VAR_MEASUREMENT, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6258, 3129, paramNames::EXT_SENSOR_B_KF_VAR_PROCESS, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 6262, 3131, paramNames::EXT_SENSOR_B_USE_KALMAN, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 3132, paramNames::EXT_SENSOR_B_FILTER_ENABLE, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 10, 0, 6266, 3133, paramNames::EXT_SENSOR_B_PROCESS_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3134, paramNames::EXT_SENSOR_B_SENSOR_SIGNAL_A, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3136, paramNames::EXT_SENSOR_B_SENSOR_SIGNAL_B, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 6276, 3138, paramNames::EXT_SENSOR_B_PARAMETERS_SIGNAL_TO_MAA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 6280, 3140, paramNames::EXT_SENSOR_B_PARAMETERS_SIGNAL_TO_MAB, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 6284, 3142, paramNames::EXT_SENSOR_B_PARAMETERS_SIGNAL_TO_VA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 6288, 3144, paramNames::EXT_SENSOR_B_PARAMETERS_SIGNAL_TO_VB, accessLevel::MANUFACTURER, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 6292, 3146, paramNames::EXT_SENSOR_B_GUI_UNIT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, -50, 150, 0, NO_FLASH, 3400, paramNames::REFERENCE_PRESSURE_LAST_TEMPERATURE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3402, paramNames::REFERENCE_PRESSURE_LAST_PRESSURE, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 127, 0, NO_FLASH, 3404, paramNames::REFERENCE_PRESSURE_I2C_ADDRESS, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3405, paramNames::REFERENCE_PRESSURE_START_OF_MEASURING_RANGE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3407, paramNames::REFERENCE_PRESSURE_END_OF_MEASURING_RANGE, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 11, 0, NO_FLASH, 3409, paramNames::REFERENCE_PRESSURE_UNIT, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, 2, 0, NO_FLASH, 3410, paramNames::REFERENCE_PRESSURE_SENSOR_TYPE, accessLevel::NORMAL, false));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 3411, paramNames::REFERENCE_PRESSURE_FILTER_ENABLE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, 6824, 3412, paramNames::REFERENCE_PRESSURE_USER_START_OF_MEASURING_RANGE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, 6828, 3414, paramNames::REFERENCE_PRESSURE_USER_END_OF_MEASURING_RANGE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, NO_FLASH, 3416, paramNames::REFERENCE_PRESSURE_EQUIPMENT_NO, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, NO_FLASH, 3417, paramNames::REFERENCE_PRESSURE_PLACE_NO, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, NO_FLASH, 3418, paramNames::REFERENCE_PRESSURE_FILE_NO, accessLevel::MEDIUM, true));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, NO_FLASH, 3419, paramNames::REFERENCE_PRESSURE_PART_NUMBER, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 6842, 3421, paramNames::REFERENCE_PRESSURE_GUI_UNIT, accessLevel::NORMAL, false));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, NO_FLASH, 3422, paramNames::REFERENCE_PRESSURE_CALLIBRATION_DATE_COMPRESSED, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 3424, paramNames::REFERENCE_PRESSURE_NO_RESPONSE, accessLevel::MEDIUM, true));
	addValue(dataUint16(0, 0, 500, 0, 6850, 3425, paramNames::REFERENCE_PRESSURE_MOVING_AVG_PERIODS, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3426, paramNames::REFERENCE_PRESSURE_MOV_AVG, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3428, paramNames::REFERENCE_PRESSURE_PRESSURE_MEASUREMENT, accessLevel::MEDIUM, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 6860, 3430, paramNames::REFERENCE_PRESSURE_PRESSURE_OFFSET, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 6864, 3432, paramNames::REFERENCE_PRESSURE_USE_MOVING_AVG, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 6866, 3433, paramNames::REFERENCE_PRESSURE_USE_KALMAN, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 6868, 3434, paramNames::REFERENCE_PRESSURE_KF_VAR_MEASUREMENT, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 6872, 3436, paramNames::REFERENCE_PRESSURE_KF_VAR_PROCESS, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, -1000, FLT_MAX, 0, NO_FLASH, 3438, paramNames::REFERENCE_PRESSURE_KALMAN_VALUE, accessLevel::NORMAL, true));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, 7200, 3600, paramNames::VALVE_PWM_MAX_VALUE, accessLevel::FULL, true));
	addValue(dataUint32(0, 0, UINT32_MAX, 0, 7204, 3602, paramNames::VALVE_TIMER_FREQ, accessLevel::FULL, true));
	addValue(dataUint32(0, 0, 20000, 10000, 7208, 3604, paramNames::VALVE_PWM_FREQ, accessLevel::FULL, false));
	addValue(dataFloat(0, 0, 100, 0, 7212, 3606, paramNames::VALVE1_PERCENTAGE_VALVE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, 100, 0, 7216, 3608, paramNames::VALVE2_PERCENTAGE_VALVE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, 100, 80, 7220, 3610, paramNames::VALVE1_VALVE_FULLY_OPEN, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, 0, 100, 80, 7224, 3612, paramNames::VALVE2_VALVE_FULLY_OPEN, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 7228, 3614, paramNames::VALVE1_ORIFICE_SIZE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 7232, 3616, paramNames::VALVE2_ORIFICE_SIZE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 7236, 3618, paramNames::VALVE1_CURRENT_SENSOR, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 7240, 3620, paramNames::VALVE2_CURRENT_SENSOR, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 7244, 3622, paramNames::VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 7246, 3623, paramNames::VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, 100, 80, 7248, 3624, paramNames::VALVE1_VALVE_OPENING_POINT, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, 100, 80, 7252, 3626, paramNames::VALVE2_VALVE_OPENING_POINT, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 1, 1, 7256, 3628, paramNames::VALVES_ENABLED, accessLevel::NORMAL, true));
	addValue(dataBool(0, 0, 1, 0, 7258, 3629, paramNames::VALVE_MANAGER_ACTIVATE_AUTO_OPENINGS_POINT_ADJUST, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 7260, 3630, paramNames::VALVE_TYPE, accessLevel::FULL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 7600, 3800, paramNames::EXT_SENSOR_C_KF_VAR_MEASUREMENT, accessLevel::MEDIUM, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, 7604, 3802, paramNames::EXT_SENSOR_C_KF_VAR_PROCESS, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 7608, 3804, paramNames::EXT_SENSOR_C_USE_KALMAN, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, NO_FLASH, 3805, paramNames::EXT_SENSOR_C_FILTER_ENABLE, accessLevel::NORMAL, true));
	addValue(dataUint16(0, 0, 10, 0, 7612, 3806, paramNames::EXT_SENSOR_C_PROCESS_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3807, paramNames::EXT_SENSOR_C_SENSOR_SIGNAL_A, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 0, NO_FLASH, 3809, paramNames::EXT_SENSOR_C_SENSOR_SIGNAL_B, accessLevel::FULL, true));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 7622, 3811, paramNames::EXT_SENSOR_C_PARAMETERS_SIGNAL_TO_MAA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 10, 7626, 3813, paramNames::EXT_SENSOR_C_PARAMETERS_SIGNAL_TO_MAB, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 7630, 3815, paramNames::EXT_SENSOR_C_PARAMETERS_SIGNAL_TO_VA, accessLevel::MANUFACTURER, false));
	addValue(dataFloat(0, FLOAT_MIN, FLT_MAX, 5, 7634, 3817, paramNames::EXT_SENSOR_C_PARAMETERS_SIGNAL_TO_VB, accessLevel::MANUFACTURER, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 7638, 3819, paramNames::EXT_SENSOR_C_GUI_UNIT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, 20, 0, 7800, 3900, paramNames::XTR305VALUE, accessLevel::NORMAL, true));
	addValue(dataFloat(0, 0, 4, 0, 7804, 3902, paramNames::XTR305VDAC, accessLevel::FULL, true));
	addValue(dataUint16(0, 0, 4, 0, 7808, 3904, paramNames::ANALOG_OUT_SELECTED_TYPE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, 4, 1, 7810, 3905, paramNames::ANALOG_OUT_OUTPUT_SIGNAL_TYPE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, 22, 0, 7812, 3906, paramNames::ANALOG_OUT_FORCED_VALUE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, 5, 0, 7816, 3908, paramNames::XTR305MODE, accessLevel::MEDIUM, false));
	addValue(dataBool(0, 0, 1, 0, 7818, 3909, paramNames::XTR305FCM, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 7820, 3910, paramNames::XTR305FLD, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 7822, 3911, paramNames::XTR305FOT, accessLevel::MEDIUM, true));
	addValue(dataBool(0, 0, 1, 0, 7824, 3912, paramNames::XTR305MODE_UPDATED, accessLevel::FULL, false));
	addValue(dataBool(0, 0, 1, 0, 7826, 3913, paramNames::XTR305OUTPUT_UPDATED, accessLevel::FULL, false));
	addValue(dataUint16(0, 0, 8, 0, 10000, 5000, paramNames::ALGORITHM_MODE, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10200, 5100, paramNames::RP_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10204, 5102, paramNames::RP_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10208, 5104, paramNames::RP_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10212, 5106, paramNames::RP_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10216, 5108, paramNames::RP_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10220, 5110, paramNames::RP_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10224, 5112, paramNames::RP_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10228, 5114, paramNames::RP_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, UINT16_MAX, 0, 10232, 5116, paramNames::RP_PID_DT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10236, 5118, paramNames::RP_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10238, 5119, paramNames::RP_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10240, 5120, paramNames::RP_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10400, 5200, paramNames::BP_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10404, 5202, paramNames::BP_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10408, 5204, paramNames::BP_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10412, 5206, paramNames::BP_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10416, 5208, paramNames::BP_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10420, 5210, paramNames::BP_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10424, 5212, paramNames::BP_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10428, 5214, paramNames::BP_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10432, 5216, paramNames::BP_PID_DT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10436, 5218, paramNames::BP_RP_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10438, 5219, paramNames::BP_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10440, 5220, paramNames::BP_SELECTED_SYSTEM_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10442, 5221, paramNames::BP_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10444, 5222, paramNames::BP_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10600, 5300, paramNames::FP_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10604, 5302, paramNames::FP_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10608, 5304, paramNames::FP_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10612, 5306, paramNames::FP_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10616, 5308, paramNames::FP_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10620, 5310, paramNames::FP_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10624, 5312, paramNames::FP_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10628, 5314, paramNames::FP_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10632, 5316, paramNames::FP_PID_DT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10636, 5318, paramNames::FP_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10638, 5319, paramNames::FP_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10640, 5320, paramNames::FP_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10800, 5400, paramNames::DP_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10802, 5401, paramNames::DP_LEADER_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10804, 5402, paramNames::DP_FOLLOWER_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10806, 5403, paramNames::DP_SETPOINT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10810, 5405, paramNames::DP_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10814, 5407, paramNames::DP_LEADER_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10818, 5409, paramNames::DP_LEADER_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10822, 5411, paramNames::DP_LEADER_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10826, 5413, paramNames::DP_LEADER_PID_DT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10830, 5415, paramNames::DP_LEADER_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10834, 5417, paramNames::DP_FOLLOWER_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10838, 5419, paramNames::DP_FOLLOWER_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10842, 5421, paramNames::DP_FOLLOWER_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10846, 5423, paramNames::DP_FOLLOWER_PID_DT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10850, 5425, paramNames::DP_FOLLOWER_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10854, 5427, paramNames::DP_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10858, 5429, paramNames::DP_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10862, 5431, paramNames::DP_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10866, 5433, paramNames::DP_PID_DT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10870, 5435, paramNames::DP_PID_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10874, 5437, paramNames::DP_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10878, 5439, paramNames::DP_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 10882, 5441, paramNames::DP_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10886, 5443, paramNames::DP_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 10888, 5444, paramNames::DP_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, FLT_MAX, 0, 10890, 5445, paramNames::DP_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11000, 5500, paramNames::FS_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11004, 5502, paramNames::FS_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11008, 5504, paramNames::FS_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11012, 5506, paramNames::FS_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11016, 5508, paramNames::FS_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11020, 5510, paramNames::FS_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11024, 5512, paramNames::FS_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11028, 5514, paramNames::FS_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11032, 5516, paramNames::FS_PID_DT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, UINT16_MAX, 0, 11036, 5518, paramNames::FS_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11040, 5520, paramNames::FS_SELECTED_FLOW_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11042, 5521, paramNames::FS_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11044, 5522, paramNames::FS_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11200, 5600, paramNames::FC_kP_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11204, 5602, paramNames::FC_kI_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11208, 5604, paramNames::FC_kD_AUTO, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11212, 5606, paramNames::FC_THRESHOLD_ACTIVE_DIFFERENCE_MBAR, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11216, 5608, paramNames::FC_kP_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11220, 5610, paramNames::FC_kI_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11224, 5612, paramNames::FC_kD_MANUAL, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11228, 5614, paramNames::FC_BANDWIDTH, accessLevel::NORMAL, false));
	addValue(dataFloat(0, 0, FLT_MAX, 0, 11232, 5616, paramNames::FC_PID_DT, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11236, 5618, paramNames::FC_SELECTED_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11238, 5619, paramNames::FC_SELECTED_FLOW_SENSOR, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11240, 5620, paramNames::FC_SELECTED_VALVE_MODE, accessLevel::NORMAL, false));
	addValue(dataUint16(0, 0, UINT16_MAX, 0, 11242, 5621, paramNames::FC_SELECTED_VALVE_OUTPUT, accessLevel::NORMAL, false));
}
