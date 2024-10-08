/***********************************************************************************************************************************
 *  File name          : medianFilter.hpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 27, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_FILTERS_MEDIAN_FILTER_HPP_

/***********************************************************************************************************************************
 *  Used defines       : 
 **********************************************************************************************************************************/
    #define	INC_FILTERS_MEDIAN_FILTER_HPP_

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/
	#include <cstdint>

/***********************************************************************************************************************************
 *  Used constants    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	enum name          : 
 *
 *  enum Description   : 
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	array name         :
 *
 *  array Description  :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	struct name        :
 *
 *	struct Description :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 Class name        : medianFilter
 *
 *	 Class Description : a small median filter, returns the middle value from the three values
 *	 					 The first time a value is added it fills all three spaces
 *
 *	 Inheritance       : None
 *
 **********************************************************************************************************************************/
	class medianFilter
	{
		private:
			float median[3];
			uint8_t smoothCounter;

		public:
			medianFilter(void);
			float medianCalculation(float Value);
	};

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/


    
#endif	/* INC_FILTERS_MEDIAN_FILTER_HPP_ */

