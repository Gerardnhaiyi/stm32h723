/***********************************************************************************************************************************
 *  File name        : thresholdFilter.hpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_FILTERS_THRESHOLD_FILTER_HPP_

/***********************************************************************************************************************************
 *    Used defines   :
 **********************************************************************************************************************************/
	#define INC_FILTERS_THRESHOLD_FILTER_HPP_

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
	#include <cstdint>

/***********************************************************************************************************************************
 *  Used constants    :
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
 *	 Class name        : 
 *
 *	 Class Description : 
 *
 *	 Inheritance       : None
 *
 **********************************************************************************************************************************/
    
/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/
    float tresholdFilter(float oldValue, float newValue, float percentage);

#endif /* INC_FILTERS_THRESHOLD_FILTER_HPP_ */
