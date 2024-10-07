/***********************************************************************************************************************************
 *  File name        : utils.hpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 30, 2023
 **********************************************************************************************************************************/

#ifndef INC_UTILS_HPP_
/***********************************************************************************************************************************
 *    Used defines :
 **********************************************************************************************************************************/
	#define INC_UTILS_HPP_

/***********************************************************************************************************************************
 *    Used includes :
 **********************************************************************************************************************************/
	#include <cstdint>

/***********************************************************************************************************************************
 *  Used constantes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 enum name         :
 *
 *   enum Description  :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 array name        :
 *
 *   array Description :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 struct name        :
 *
 *	 struct Description :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 Class name        : utils
 *
 *	 Class Description : class of utilities
 *
 *	 Inheritance       : None
 *
 **********************************************************************************************************************************/
	class utils
	{
		private:
			constexpr static float MAX_RANGE = 100.0f;
			constexpr static float MIN_RANGE = 0.0f;
			const uint32_t dfuBootKey = 0xBEEFBEEF;

			float limit = 0;
			float mapValue = 0;
			uint32_t tickResult = 0;

		public:
			uint32_t getDifferenceTick(uint32_t tickNew, uint32_t tickOld);
			void dfuBoot(void);
			float checkLimits(float value, float min, float max);
			float map(float x, float inMin, float inMax, float outMin = MIN_RANGE, float outMax = MAX_RANGE);
			uint32_t uint32Reverser(uint32_t value);
			uint16_t uint16Reverser(uint16_t value);
			void reverseArray(uint8_t start, uint8_t len, uint8_t* arr);
			uint8_t getLowByteOfUint32(uint32_t value);
			uint8_t getMiddleLowByteOfUint32(uint32_t value);
			uint8_t getMiddleHighByteOfUint32(uint32_t value);
			uint8_t getHighByteOfUint32(uint32_t value);
			uint32_t setBit(uint32_t value, uint8_t bitnr);
			uint32_t clearBit(uint32_t value, uint8_t bitnr);
			bool checkBit(uint32_t value, uint8_t bitnr);
			uint32_t toggleBit(uint32_t value, uint8_t bitnr);
	};



#endif /* INC_UTILS_HPP_ */
