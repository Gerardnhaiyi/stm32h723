/********************************************************************************************************************************
 *	File name:				dataClass.hpp
 *
 *	File Description:		Declaration of the dataClass class. a template for storage classes. also includes some
 *							supporting enumerators.
 *
 ********************************************************************************************************************************/

#ifndef DATACLASS_HPP_
#define DATACLASS_HPP_

#include <cstdint>
#include <cstddef>
#include <cfloat>
#include "paramNames.hpp"

#define NO_FLASH   0xFFFFFFFF
#define NO_MODBUS  UINT16_MAX
#define FLOAT_MIN  (-1000000.000f)

/********************************************************************************************************************************
 *	Class name:				accessLevel
 *
 *	Class Description:		A class that contains the list of the access levels
 *
 ********************************************************************************************************************************/
enum class accessLevel : uint16_t
{
	NORMAL = 0x0,
	MEDIUM = 0x71,
	FULL = 0x81,
	MANUFACTURER = 0x91
};

/********************************************************************************************************************************
 *	Class name:				dataType
 *
 *	Class Description:		A class that contains the list of the data types
 *
 ********************************************************************************************************************************/
enum class dataType
{
	NONE,
	BOOL,
	UINT16,
	UINT32,
	INT16,
	INT32,
	FLOAT,
	FLOAT_TREND
};

/********************************************************************************************************************************
 *	Class name:				dataErrors
 *
 *	Class Description:		A class that contains the list of the data errors
 *
 ********************************************************************************************************************************/
enum class dataErrors
{
	SUCCESS,
	SIZE_ERROR,
	OUT_OF_RANGE,
	NO_RIGHTS,
	INVALID_ADRESS,
	INVALID_TYPE
};

/********************************************************************************************************************************
 *	Class name:				dataClass
 *
 *	Class Description:		A template class for the data storage.
 *
 ********************************************************************************************************************************/
class dataClass
{
	protected:
		uint32_t flashAdress = NO_FLASH;
		uint16_t modbusAdress = NO_MODBUS;
		paramNames name = paramNames::MAX_PARAMS;
		accessLevel accessLevelSet = accessLevel::MEDIUM;
		bool readOnly = false;
		dataType dataTypeSet = dataType::NONE;

	public:
		virtual ~dataClass();
		dataClass();
		dataClass( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn, dataType dataTypeIn );

		uint16_t getModbusAdress();
		uint32_t getFlashAdress();
		bool getReadOnly();
		dataType getDataType();
		paramNames getName();
		accessLevel getAccessLevel();

		//virtual functions, to be defined in
		virtual size_t getByteSize();
		virtual void setToDefault();
		virtual size_t toBytes( uint8_t *buffer, size_t bytesfree );
		virtual dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble );
		virtual dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );
};
// class dataClass

#endif /* DATACLASS_HPP_ */
