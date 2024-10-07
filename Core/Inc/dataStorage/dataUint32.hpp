/********************************************************************************************************************************
 *	File name:				dataUint32.hpp
 *
 *	File Description:		Declaration of the dataUint32 class. a storage class for uint32s.
 *
 ********************************************************************************************************************************/

#ifndef DATAUINT32_HPP_
#define DATAUINT32_HPP_

#include "dataClass.hpp"
#include "paramNames.hpp"

/********************************************************************************************************************************
 *	Class name:				dataUint32
 *
 *	Class Description:		A class to store and convert uint32s and some important value.
 *
 *	Inheritance:			dataClass.
 *
 ********************************************************************************************************************************/
class dataUint32: public dataClass
{
	protected:
		uint32_t min;
		uint32_t max;
		uint32_t defaultValue;
		uint32_t value;

	public:
		dataUint32();
		dataUint32( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataUint32( uint32_t valueIn, uint32_t minIn, uint32_t maxIn, uint32_t defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
		        bool readOnlyIn );
		~dataUint32();

		uint32_t getValue();
		void setValue( uint32_t valueIn );
		uint32_t getMin();
		void setMin( uint32_t minIn );
		uint32_t getMax();
		void setMax( uint32_t maxIn );
		uint32_t getDefault();
		void setDefault( uint32_t defaultValueIn );

		size_t getByteSize();
		void setToDefault();
		size_t toBytes( uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

};
// class dataUint32

#endif /* DATAUINT32_HPP_ */
