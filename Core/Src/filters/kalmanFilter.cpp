/***********************************************************************************************************************************
 *  File name        : kalmanFilter.cpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 27, 2023
 *
 *  File Description : this file contains several filters that can be used if needed
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Defines   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *    Used Includes  :
 **********************************************************************************************************************************/
#include <cmath>
#include "kalmanFilter.hpp"

/***********************************************************************************************************************************
 *    Used Methods   :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : kalmanFilter
 *
 *  Method Description : constructor of the class
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
kalmanFilter::kalmanFilter(void)
{
    varMeasurement = 0.0f;
    varProcess = 0.0f;
    Xt = 0.0f;
    Xt_update = 0.0f;
    Xt_prev = 0.0f;
    Pt = 0.0f;
    Pt_update = 0.0f;
    Pt_prev = 1.0f;
    Kt = 0.0f;
}

/***********************************************************************************************************************************
 *  Method Name        : newKalmanEstimate
 *
 *  Method Description : This method will reduce the measurement faults
 *
 *  Entry              : float sensorValue
 *
 *  Exit               : float result
 *
 **********************************************************************************************************************************/
float kalmanFilter::newKalmanEstimate(float sensorValue)
{
	if(varMeasurement == 0)
	{
		return sensorValue;
	}
	Xt_update = Xt_prev;
	Pt_update = Pt_prev + varProcess;
	Kt = Pt_update / (Pt_update + varMeasurement);
	Xt = Xt_update + ( Kt * (sensorValue - Xt_update));
	Pt = (1 - Kt) * Pt_update;
	Xt_prev = Xt;
	Pt_prev = Pt;
	return Xt;
}

