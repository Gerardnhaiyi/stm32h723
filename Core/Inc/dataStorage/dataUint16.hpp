/********************************************************************************************************************************
 *	File name:				dataUint16.hpp
 *
 *	File Description:		Declaration of the dataUint16 class. a storage class for Uint16s.
 *
 ********************************************************************************************************************************/

#ifndef DATAUINT16_HPP_
#define DATAUINT16_HPP_

#include "dataClass.hpp"
#include "paramNames.hpp"

/********************************************************************************************************************************
 *	Class name:				dataUint16
 *
 *	Class Description:		A class to store and convert uint16s and some important value.
 *
 *	Inheritance:			dataClass.
 *
 ********************************************************************************************************************************/
class dataUint16: public dataClass
{
	protected:
		uint16_t min;
		uint16_t max;
		uint16_t defaultValue;
		uint16_t value;

	public:
		dataUint16();
		dataUint16( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataUint16( uint16_t valueIn, uint16_t minIn, uint16_t maxIn, uint16_t defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn,
		        bool readOnlyIn );
		~dataUint16();

		uint16_t getValue();
		void setValue( uint16_t valueIn );
		uint16_t getMin();
		void setMin( uint16_t minIn );
		uint16_t getMax();
		void setMax( uint16_t maxIn );
		uint16_t getDefault();
		void setDefault( uint16_t defaultValueIn );

		size_t getByteSize();
		void setToDefault();
		size_t toBytes( uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

};
// class dataUint16

#endif /* DATAUINT16_HPP_ */
