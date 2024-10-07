/********************************************************************************************************************************
 *	File name:				dataFloat.hpp
 *
 *	File Description:		Declaration of the dataFloat class. a storage class for floats.
 *
 ********************************************************************************************************************************/

#ifndef DATAFLOAT_HPP_
#define DATAFLOAT_HPP_

#include "dataClass.hpp"
#include "paramNames.hpp"

/********************************************************************************************************************************
 *	Class name:				dataFloat
 *
 *	Class Description:		A class to store and convert floats and some important value.
 *
 *	Inheritance:			dataClass.
 *
 ********************************************************************************************************************************/
class dataFloat: public dataClass
{
	protected:
		float min;
		float max;
		float defaultValue;
		float value;

		float limitValue(float valueIn);

		dataFloat( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn, dataType dataTypeIn );

	public:
		dataFloat();
		dataFloat( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataFloat( float valueIn, float minIn, float maxIn, float defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		~dataFloat();

		float getValue();
		virtual void setValue( float valueIn );
		float getMin();
		void setMin( float minIn );
		float getMax();
		void setMax( float maxIn );
		float getDefault();
		void setDefault( float defaultValueIn );

		size_t getByteSize() override;
		void setToDefault() override;
		size_t toBytes( uint8_t *buffer, size_t bytesfree ) override;
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble ) override;
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel ) override;
};
// class dataFloat

#endif /* DATAFLOAT_HPP_ */
