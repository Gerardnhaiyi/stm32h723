/***********************************************************************************************************************************
 *  File name        : exponentialFilter.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 *  File Description : this file contains an ExponentialFilter that can be used if needed
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
#include <cmath>
#include "exponentialFilter.hpp"

/***********************************************************************************************************************************
 *    Used Methods   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : ExponentialFilter
 *
 *  Method Description : This method will provides a simple way to smooth noisy measurements from analog sensors by a simple
 *  					 linear recursive exponential filter against weight of the new value.
 *
 *  Entry              : float lastExponentialFilterValue, float newValue, float weight
 *
 *  Exit               : float LastExponentialFilterValue
 *
 **********************************************************************************************************************************/
float exponentialFilter(float lastExponentialFilterValue, float newValue, float weight)
{
    return weight * newValue + lastExponentialFilterValue * (1 - weight);
}

