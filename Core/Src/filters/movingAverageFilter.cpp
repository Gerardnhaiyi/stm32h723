/***********************************************************************************************************************************
 *  File name        : filters.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 *  File Description : this file contains the movingAverageFilter that can be used if needed
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
#include <cmath>
#include "movingAverageFilter.hpp"

/***********************************************************************************************************************************
 *    Used Methods   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : movingAverageFilter
 *
 *  Method Description : constructor of the class
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
movingAverageFilter::movingAverageFilter(void)
{
	movingAverageCount = 0;
    movingAveragePeriods = 100;
    prevMovingAveragePeriods = 0;
    pressureMeasurement = 0.0f;
    movingAverage = 0.0f;
    sum = 0.0f;
    useMovingAverage = false;
    filterEnable = false;
}

/***********************************************************************************************************************************
 *  Method Name        : calculateMovingAverage
 *
 *  Method Description : This method will calculate the moving average value over a large number of values
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
float movingAverageFilter::calculateMovingAverage(float periodValue, float measuredValue)
{
	movingAveragePeriods = periodValue;

    if(prevMovingAveragePeriods != movingAveragePeriods) //amount of periods is changing?
    {
    	prevMovingAveragePeriods = movingAveragePeriods; //initialize array with zero's

        for(uint16_t i = 0 ; i < movingAverageArraySize; i ++)
        {
        	averageArray[i] = 0.0f;
        }
    }

	pressureMeasurement = measuredValue;
    if(movingAveragePeriods > 0)
    {
        sum -= averageArray[movingAverageCount]; //reduce the sum with oldest value and clear this position
        averageArray[movingAverageCount] = pressureMeasurement; // fill it with new value
        sum += pressureMeasurement; // add it to the sum

        movingAverageCount = (movingAverageCount + 1) % movingAveragePeriods; //make sure the count doesn't exceed it's limit

        movingAverage = sum / movingAveragePeriods; //get the average
    }
    else //movingAveragePeriods <= 0
    {
    	movingAverage = pressureMeasurement;
    }
    return movingAverage;
}

