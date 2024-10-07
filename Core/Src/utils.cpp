/***********************************************************************************************************************************
 *  File name        : utils.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 30, 2023
 *
 *  File Description :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes :
 **********************************************************************************************************************************/
#include "utils.hpp"
#include "rtc.hpp"

/***********************************************************************************************************************************
 *    Used Prototypes :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : DFUBoot
 *
 *  Method Description : writes the boot key to rtc-register
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void utils::dfuBoot(void)
{
	*((uint32_t *)0x2404FFFC) = dfuBootKey; // Special Key to End-of-RAM
	rtcTimer::writeBackupRegister(static_cast<uint8_t>(rtcBkpReg::DFU_BOOT_KEY), dfuBootKey);
	HAL_NVIC_SystemReset();
}


/***********************************************************************************************************************************
 *  Method Name        : getDifferenceTick
 *
 *  Method Description : this method returns the difference between current and previous tick-time
 *
 *  Entry              : uint32_t tickNew, uint32_t tickOld
 *
 *  Exit               : uint32_t difference_tick
 *
 **********************************************************************************************************************************/
uint32_t utils::getDifferenceTick(uint32_t tickNew, uint32_t tickOld)
{
    if (tickNew < tickOld)
    {
        // time rollover(overflow)
    	tickResult = (0xFFFFFFFF - tickOld) + 1 + tickNew;
    }
    else
    {
    	tickResult = tickNew - tickOld;
    }
    return tickResult;
}

/***********************************************************************************************************************************
 *  Method Name        : checkValveLimits
 *
 *  Method Description : make sure the value is within limits, return the limited value, if value out of limit => return that limit
 *
 *  Entry              : float value, float min, float max
 *
 *  Exit               : float value
 *
 **********************************************************************************************************************************/
float utils::checkLimits(float value, float min, float max)
{
	//check max value
	limit = value > max ? max : value;

	//check min value
	limit = value < min ? min : value;

	return limit;
}

/***********************************************************************************************************************************
 *  Method Name        : map
 *
 *  Method Description : map current range to workable range, this formula will convert the value with it's range values to a new range
 *
 *  Entry              : float x, float inMin, float inMax, float outMin, float outMax
 *
 *  Exit               : float
 *
 **********************************************************************************************************************************/
float utils::map(float x, float inMin, float inMax, float outMin, float outMax)
{
	mapValue = (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
	return mapValue;
}

/***********************************************************************************************************************************
 *  Method Name        : uint32Reverser
 *
 *  Method Description : this method reverses the bytes of a 32bit value
 *
 *  Entry              : uint32_t value
 *
 *  Exit               : uint32_t reversed value
 *
 **********************************************************************************************************************************/
uint32_t utils::uint32Reverser(uint32_t value)
{
	uint32_t result = ((value << 24) & 0xFF000000) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x0000FF00) | ((value >> 24) & 0x000000FF);
	return result;
}

/***********************************************************************************************************************************
 *  Method Name        : uint16Reverser
 *
 *  Method Description : this method reverses the bytes of a 16bit value
 *
 *  Entry              : uint16_t value
 *
 *  Exit               : uint16_t reversed value
 *
 **********************************************************************************************************************************/
uint16_t utils::uint16Reverser(uint16_t value)
{
	uint16_t result = ((value >> 8) & 0xFF) | ((value << 8) & 0xFF00);
	return result;
}

/***********************************************************************************************************************************
 *  Method Name        : reverseArray
 *
 *  Method Description : this method reverses a number of bytes from a starting point of an array
 *
 *  Entry              : uint8_t start, the start position (first position is zero)
 *						 uint8_t len, the amount of bytes to reverse
 *						 uint8_t* arr, the pointer to the array
 *
 *  Exit               : None, the bytes are reversed
 *
 **********************************************************************************************************************************/
void utils::reverseArray(uint8_t start, uint8_t len, uint8_t* arr)
{
	uint8_t db[len];
	for(uint8_t x = 0; x < len; x ++)
	{
		db[x] = 0;
	}
	for(uint8_t x = 0; x < len; x ++)
	{
		db[len - x - 1] = arr[start + x];
	}
	for(uint8_t x = start; x < start+len; x ++)
	{
		arr[x] = db[x-start];
	}
}

/***********************************************************************************************************************************
 *  Method Name        : getLowByteOfUint32
 *
 *  Method Description : method to get the lowest byte of a 32 bit integer
 *
 *  Entry              : value, the value to get the lowest byte from
 *
 *  Exit               : uint8_t, the lowest byte
 *
 **********************************************************************************************************************************/
uint8_t utils::getLowByteOfUint32(uint32_t value)
{
    return (uint8_t)(value & 0xFF);
}

/***********************************************************************************************************************************
 *  Method Name        : getMiddleLowByteOfUint32
 *
 *  Method Description : method to get the second byte of a 32 bit integer
 *
 *  Entry              : value, the value to get the byte from
 *
 *  Exit               : uint8_t, the second byte
 *
 **********************************************************************************************************************************/
uint8_t utils::getMiddleLowByteOfUint32(uint32_t value)
{
    return (uint8_t)((value >> 8) & 0xFF);
}

/***********************************************************************************************************************************
 *  Method Name        : getMiddleHighByteOfUint32
 *
 *  Method Description : method to get the third byte of a 32 bit integer
 *
 *  Entry              : value, the value to get the third byte from
 *
 *  Exit               : uint8_t, the third byte
 *
 **********************************************************************************************************************************/
uint8_t utils::getMiddleHighByteOfUint32(uint32_t value)
{
    return (uint8_t)((value >> 16) & 0xFF);
}

/***********************************************************************************************************************************
 *  Method Name        : getHighByteOfUint32
 *
 *  Method Description : method to get the highest byte of a 32 bit integer
 *
 *  Entry              : value, the value to get the highest byte from
 *
 *  Exit               : uint8_t, the highest byte
 *
 **********************************************************************************************************************************/
uint8_t utils::getHighByteOfUint32(uint32_t value)
{
    return (uint8_t)((value >> 24) & 0xFF);
}

/***********************************************************************************************************************************
 *  Method Name        : setBit
 *
 *  Method Description : method to set the selected bit of a 32 bit integer
 *
 *  Entry              : value, the 32 bit integer
 *  					 bitnr, the selected bit
 *
 *  Exit               : the 32 bit integer with selected bit set
 *
 **********************************************************************************************************************************/
uint32_t utils::setBit(uint32_t value, uint8_t bitnr)
{
    return (uint32_t)(value |= (0x01 << bitnr));
}

/***********************************************************************************************************************************
 *  Method Name        : clearBit
 *
 *  Method Description : method to clear the selected bit of a 32 bit integer
 *
 *  Entry              : value, the 32 bit integer
 *  					 bitnr, the selected bit
 *
 *  Exit               : the 32 bit integer with selected bit cleared
 *
 **********************************************************************************************************************************/
uint32_t utils::clearBit(uint32_t value, uint8_t bitnr)
{
    return (uint32_t)(value &= ~(0x01 << bitnr));
}

/***********************************************************************************************************************************
 *  Method Name        : checkBit
 *
 *  Method Description : method to test the selected bit of a 32 bit integer
 *
 *  Entry              : value, the 32 bit integer
 *  					 bitnr, the selected bit
 *
 *  Exit               : true, the selected bit is set
 *  					 false, the selected bit is cleared
 *
 **********************************************************************************************************************************/
bool utils::checkBit(uint32_t value, uint8_t bitnr)
{
    return (bool)((value >> bitnr) & 0x01);
}

/***********************************************************************************************************************************
 *  Method Name        : toggleBit
 *
 *  Method Description : method to toggle the selected bit of a 32 bit integer
 *
 *  Entry              : value, the 32 bit integer
 *  					 bitnr, the selected bit
 *
 *  Exit               : the 32 bit integer with selected bit toggled
 *
 **********************************************************************************************************************************/
uint32_t utils::toggleBit(uint32_t value, uint8_t bitnr)
{
    return (uint32_t)(value ^= (0x01 << bitnr));
}

