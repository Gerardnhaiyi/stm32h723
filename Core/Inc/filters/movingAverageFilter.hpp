/***********************************************************************************************************************************
 *  File name          : movingAverageFilter.h
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 27, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_FILTERS_MOVING_AVERAGE_FILTER_HPP_

/***********************************************************************************************************************************
 *  Used defines       : 
 **********************************************************************************************************************************/
    #define	INC_FILTERS_MOVING_AVERAGE_FILTER_HPP_

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/
	#include <cstdint>
	#include "dataStorage.hpp"

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
 *	 Class name        : movingAverage
 *
 *	 Class Description : this class contains a large moving average
 *
 *	 Inheritance       : None
 *
 **********************************************************************************************************************************/
    class movingAverageFilter
	{
		private:
			//large moving average for ref sensor
			const static uint16_t movingAverageArraySize = 500;
			static float averageArray[movingAverageArraySize];
			static uint16_t movingAverageCount;
	        uint16_t movingAveragePeriods;
	        uint16_t prevMovingAveragePeriods;
	        float pressureMeasurement;
	        float movingAverage;
	        bool useMovingAverage;
	        bool filterEnable;
	        float sum;

		public:
			paramNames periodValue = paramNames::REFERENCE_PRESSURE_MOVING_AVG_PERIODS;
			paramNames measuredValue = paramNames::REFERENCE_PRESSURE_PRESSURE_MEASUREMENT;
			paramNames storageLoc = paramNames::REFERENCE_PRESSURE_MOV_AVG;

			movingAverageFilter(void);
			float calculateMovingAverage(float periodValue, float measuredValue);
//			void calculateMovingAverage(void);
	};

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/


    
#endif	/* INC_FILTERS_MOVING_AVERAGE_FILTER_HPP_ */

