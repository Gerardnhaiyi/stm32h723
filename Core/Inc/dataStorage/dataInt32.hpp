/********************************************************************************************************************************
 *	File name:				dataInt32.hpp
 *
 *	File Description:		Declaration of the dataInt32 class. a storage class for int32s.
 *
 ********************************************************************************************************************************/

#ifndef DATAINT32_HPP_
#define DATAINT32_HPP_

#include "dataClass.hpp"
#include "paramNames.hpp"

/********************************************************************************************************************************
 *	Class name:				dataInt32
 *
 *	Class Description:		A class to store and convert int32s and some important value.
 *
 *	Inheritance:			dataClass.
 *
 ********************************************************************************************************************************/
class dataInt32: public dataClass
{
	protected:
		int32_t min;
		int32_t max;
		int32_t defaultValue;
		int32_t value;

	public:
		dataInt32();
		dataInt32( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataInt32( int32_t valueIn, int32_t minIn, int32_t maxIn, int32_t defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
		        bool readOnlyIn );
		~dataInt32();

		int32_t getValue();
		void setValue( int32_t valueIn );
		int32_t getMin();
		void setMin( int32_t minIn );
		int32_t getMax();
		void setMax( int32_t maxIn );
		int32_t getDefault();
		void setDefault( int32_t defaultValueIn );

		size_t getByteSize();
		void setToDefault();
		size_t toBytes( uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

};
// class dataInt32

#endif /* DATAINT32_HPP_ */
