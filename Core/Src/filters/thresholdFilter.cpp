/***********************************************************************************************************************************
 *  File name        : thresholdFilter.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 *  File Description : this file contains the thresholdFilter that can be used if needed
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
#include <cmath>
#include "thresholdFilter.hpp"

/***********************************************************************************************************************************
 *    Used Methods   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : tresholdFilter
 *
 *  Method Description : This method will provides a simple way to smooth noisy measurements from analog sensors by a Threshold
 *  					 filter of the old value against the new value
 *
 *  Entry              : float oldValue, float newValue, float percentage
 *
 *  Exit               : float tFilter
 *
 **********************************************************************************************************************************/
float tresholdFilter(float oldValue, float newValue, float percentage)
{
	float result = 0.0f;
    if (oldValue == 0)
    {
    	result = newValue;
    }
    else
    {
    	float threshold = oldValue / 100 * percentage; //calculate the threshold value
        if(abs(newValue - oldValue) < threshold)
        {
        	result = newValue;
        }
    }
    return result;
}

