/***********************************************************************************************************************************
 *  File name        : medianFilter.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 *  File Description : this file contains a median Filter that can be used if needed
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
#include <cmath>
#include "medianFilter.hpp"

/***********************************************************************************************************************************
 *    Used Methods   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : medianFilter
 *
 *  Method Description : constructor of the class
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
medianFilter::medianFilter(void)
{
	for(uint8_t i = 0; i < 3; i ++)
	{
		median[i] = 0;
	}
	smoothCounter = 255;
}

/***********************************************************************************************************************************
 *  Method Name        : getInstance
 *
 *  Method Description : Get the instance object
 *
 *  Entry              : None
 *
 *  Exit               : median&, Return reference to the median object
 *
 **********************************************************************************************************************************/
/*medianFilter& medianFilter::getInstance(void)
{
    static medianFilter med;
    return med;
}*/

/***********************************************************************************************************************************
 *  Method Name        : MedianFilter
 *
 *  Method Description : This method will provides a simple way to smooth noisy measurements from analog sensors by a taking 3
 *   					 measurements and taking the median from that as the new value.
 *
 *  Entry              : uint16_t sensorNr, float value
 *
 *  Exit               : float Median
 *
 **********************************************************************************************************************************/
float medianFilter::medianCalculation(float value)
{
	float result = 0.0f;
    if(smoothCounter == 255)
    {
        for(uint8_t x = 0; x < 3; x ++)
        {
            median[x] = value;
        }
        smoothCounter = 0;
    }
    else
    {
        median[smoothCounter] = value;
    }
    
    smoothCounter ++;
    if(smoothCounter >= 3)
    {
        smoothCounter = 3;
    }

    if (median[0] < median[1])
    {
        if (median[0] > median[2])
        {
        	result = median[0];
        }
        else if (median[1] < median[2])
        {
        	result = median[1];
        }
        else
        {
        	result = median[2];
        }
    }
    else
    {
        if (median[1] > median[2])
        {
        	result = median[1];
        }
        else if (median[0] < median[2])
        {
        	result = median[0];
        }
        else
        {
        	result = median[2];
        }
    }
    return result;
}

