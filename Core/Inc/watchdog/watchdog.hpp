/***********************************************************************************************************************************
 *  File name          : watchdog.hpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Jan 5, 2024
 *
 **********************************************************************************************************************************/
#ifndef INC_WATCHDOG_WATCHDOG_HPP_

/***********************************************************************************************************************************
 *  Used defines       :
 **********************************************************************************************************************************/
	#define INC_WATCHDOG_WATCHDOG_HPP_

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/
	#include <cstdint>
	#include "iwdg.h"
	#include "utils.hpp"
//	#include "alarmManager.hpp"

/***********************************************************************************************************************************
 *  Used constantes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	enum name          : wdResetControl
 *
 *  enum Description   : enum of all process-loops (max 32)
 *
 **********************************************************************************************************************************/
	enum class wdResetControl : uint8_t
	{
		SENSOR_CONTROL_TASK = 0,
		ADC_SENSORS_TASK,
		REF_SENSOR_TASK,
		SETPOINT_TASK,

		ALGORITHM_TASK,
		ANALOG_OUT_TASK,
		STATUS_TASK,
		MODBUS_TASK,

		LOG_TASK,
		SECURITY_TASK,
		BUTTON_TASK,
		WATCHDOG_TASK,
		
		VALVE_CURRENT_TASK,
		LED_TASK,

		MAX_WDRC
	};

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
 *	Class name         : watchdog
 *
 *  Class Description  : watchdog class to keep the firmware checking on health
 *  					 The hardware watchdog is checking if the RTOS runs and each task must report a timer-bit
 *  					 to do: It might be handy to reset only the task if a specific task get stuck.
 *
 *	Inheritance        : None
 *
 **********************************************************************************************************************************/
	class watchdog
	{
		private:
			static constexpr uint32_t controlBits = 0x00000804; //Bits that must be set each round

			uint32_t ReloadTime;
			uint32_t downCounter;
			uint32_t windowTime;

			uint32_t tasksOK; //below are the bits for tasks to set
			uint32_t faultCode;

			utils* ut;

			void resetWatchDog(void);

		public:
			watchdog(void);
			void setWdrcFlags(uint8_t wdrc);
			uint32_t getFaultCode(void);//(alarmManager& alrm);
	};

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/


#endif /* INC_WATCHDOG_WATCHDOG_HPP_ */
