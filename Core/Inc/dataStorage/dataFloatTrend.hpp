/********************************************************************************************************************************
 *	File name:				dataFloatTrend.hpp
 *
 *	File Description:		Declaration of the dataFloatTrend class. a storage class for floats that need a trend.
 *
 ********************************************************************************************************************************/

#ifndef DATAFLOATTREND_HPP_
#define DATAFLOATTREND_HPP_

#include "cmsis_os.h"
#include "semphr.h"
#include "dataFloat.hpp"


/********************************************************************************************************************************
 *	Class name:				dataFloatTrend
 *
 *	Class Description:		A class to store and convert floats with trend information, and some important value.
 *
 *	Inheritance:			dataFloat.
 *
 ********************************************************************************************************************************/
class dataFloatTrend: public dataFloat
{
	protected:
		static const uint8_t step = 1;
		static const uint8_t distance = 10;

		uint8_t startPosition = 0;
		uint8_t endPosition = distance;
		//uint8_t position = 0;
		uint8_t countA = 255;
		uint8_t countB = 255;
		bool IsReady = false;

		static constexpr uint8_t TRENDBUFFERSIZE = 15;
		uint8_t BufferLN;
		float buffer[ TRENDBUFFERSIZE ] = { 0.0 };
		SemaphoreHandle_t mutex = xSemaphoreCreateMutex();

	public:
		dataFloatTrend();
		dataFloatTrend( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataFloatTrend( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataFloatTrend( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn, uint8_t bufferSize );
		~dataFloatTrend();

		void setValue( float valueIn ) override;
		float getTrend();

		float* getBuffer() { return(buffer); };
};

#endif /* DATAFLOATTREND_HPP_ */
