/********************************************************************************************************************************
 *	File name:				dataStorage.hpp
 *
 *	File Description:		Declaration of the dataStorage class. this class will store all parameters and will make them
 *							available in useful manners
 *
 ********************************************************************************************************************************/

#ifndef CORE_INC_STORAGE_DATASTORAGE_HPP_
#define CORE_INC_STORAGE_DATASTORAGE_HPP_

#include <cstdint>
#include <cstddef>
#include "paramNames.hpp"
#include "dataFloatTrend.hpp"
#include "dataFloat.hpp"
#include "dataInt32.hpp"
#include "dataUint32.hpp"
#include "dataUint16.hpp"
#include "dataBool.hpp"
#include "dataClass.hpp"


#define MAX_MODBUS_ADRESS  1000
#define MAX_FLASH_ADRESS   2000

#define AMOUNT_OF_INT32S		19
#define AMOUNT_OF_FLOATS		173
#define AMOUNT_OF_UINT32S		13
#define AMOUNT_OF_UINT16S		142
#define AMOUNT_OF_BOOLS			57
#define AMOUNT_OF_FLOATS_TREND	4

/********************************************************************************************************************************
 *	Class name:				dataStorage
 *
 *	Class Description:		A class to store all parameters and keep them accessible to the rest of the classes

 *
 ********************************************************************************************************************************/
class dataStorage
{
	private:
		//storage for the parameters
		dataFloat dataFloatStorage[ AMOUNT_OF_FLOATS ];
		uint16_t floatFilled = 0;
		dataBool dataBoolStorage[ AMOUNT_OF_BOOLS ];
		uint16_t boolFilled = 0;
		dataInt32 dataInt32Storage[ AMOUNT_OF_INT32S ];
		uint16_t int32Filled = 0;
		dataUint16 dataUint16Storage[ AMOUNT_OF_UINT16S ];
		uint16_t uint16Filled = 0;
		dataUint32 dataUint32Storage[ AMOUNT_OF_UINT32S ];
		uint16_t uint32Filled = 0;
		dataFloatTrend dataFloatTrendStorage[ AMOUNT_OF_FLOATS_TREND ];
		uint16_t FloatTrendFilled = 0;

		//loop up table for the parameters
		dataClass *datapoint[ static_cast< uint16_t >( paramNames::MAX_PARAMS ) ] = { NULL };
		dataClass *datapointModbus[ MAX_MODBUS_ADRESS ] = { NULL };
		dataClass *datapointFlash[ MAX_FLASH_ADRESS ] = { NULL };

		bool addValue( dataClass* );
		bool addValue( dataFloat );
		bool addValue( dataBool );
		bool addValue( dataInt32 );
		bool addValue( dataUint16 );
		bool addValue( dataUint32 );
		bool addValue( dataFloatTrend );

	public:
		dataStorage();

		dataType getDataTypeName( paramNames );

		dataClass* getDataName( paramNames );
		dataClass* getDataflash( uint32_t );
		dataClass* getDataModbus( uint16_t );

		dataFloat* getDataFloatName( paramNames );
		dataFloatTrend* getDataFloatTrendName( paramNames );
		dataBool* getDataBoolName( paramNames );
		dataInt32* getDataInt32Name( paramNames );
		dataUint16* getDataUint16Name( paramNames );
		dataUint32* getDataUint32Name( paramNames );

		float getFloatValueName( paramNames );
		float getFloatTrendValueName( paramNames );
		bool getBoolValueName( paramNames );
		int32_t getInt32ValueName( paramNames );
		uint16_t getUint16ValueName( paramNames );
		uint32_t getUint32ValueName( paramNames );

		bool setFloatValueName( paramNames, float );
		bool setBoolValueName( paramNames, bool );
		bool setInt32ValueName( paramNames, int32_t );
		bool setUint16ValueName( paramNames, uint16_t );
		bool setUint32ValueName( paramNames, uint32_t );

		size_t toBytesName( paramNames, uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytesName( paramNames, uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytesName( paramNames, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

		size_t toBytesFlash( uint32_t, uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytesFlash( uint32_t, uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytesFlash( uint32_t, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

		size_t toBytesModbus( uint16_t, uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytesModbus( uint16_t, uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytesModbus( uint16_t, uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

};
// class dataStorage

#endif /* CORE_INC_STORAGE_DATASTORAGE_HPP_ */
