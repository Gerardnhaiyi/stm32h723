/********************************************************************************************************************************
 *	File name:				dataBool.hpp
 *
 *	File Description:		Declaration of the dataBool class. a storage class for booleans.
 *
 ********************************************************************************************************************************/

#ifndef DATABOOL_HPP_
#define DATABOOL_HPP_

#include "dataClass.hpp"
#include "paramNames.hpp"

/********************************************************************************************************************************
 *	Class name:				dataBool
 *
 *	Class Description:		A class to store and convert booleans and some important values.
 *
 *	Inheritance:			dataClass.
 *
 ********************************************************************************************************************************/
class dataBool: public dataClass
{
	protected:
		bool defaultValue;
		bool value;

	public:
		dataBool();
		dataBool( uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataBool( bool valueIn, bool defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		dataBool( bool valueIn, bool, bool, bool defaultValueIn, uint32_t flashAdressIn, uint16_t modbusAdressIn, paramNames nameIn, accessLevel accessLevelIn, bool readOnlyIn );
		~dataBool();

		bool getValue();
		void setValue( bool valueIn );
		bool getDefault();
		void setDefault( bool defaultValueIn );

		size_t getByteSize();
		void setToDefault();
		size_t toBytes( uint8_t *buffer, size_t bytesfree );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble );
		dataErrors fromBytes( uint8_t *buffer, size_t bytesAvaleble, accessLevel userAccessLevel );

};
// class dataBool

#endif /* DATABOOL_HPP_ */
