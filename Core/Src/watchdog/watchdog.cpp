/***********************************************************************************************************************************
 *  File name          : watchdog.cpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Jan 5, 2024
 *
 *  File Description   : class of the independent watchdog which must be reset by command
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Defines       :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Includes      :
 **********************************************************************************************************************************/
#include "watchdog.hpp"

/***********************************************************************************************************************************
 *  Used Prototypes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : watchdog
 *
 *  Method Description : method to initialize the independent watch-dog
 *  					 Max watch-dog-time is set to 1 second
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
watchdog::watchdog(void)
{
	//reset time before 1s because (1/32000)*64*500 = 1s
	ReloadTime = IWDG_PRESCALER_256;
	downCounter = 4095;
	windowTime = 4095;
	tasksOK = 0;
	faultCode = 0;

	hiwdg1.Instance = IWDG1;

	hiwdg1.Init.Prescaler = ReloadTime;
	hiwdg1.Init.Window = windowTime;
	hiwdg1.Init.Reload = downCounter;

	if (HAL_IWDG_Init(&hiwdg1) != HAL_OK)
	{
		Error_Handler();
	}

}

/***********************************************************************************************************************************
 *  Method Name        : resetWatchDog
 *
 *  Method Description : method to reset the watchdog
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void watchdog::resetWatchDog(void)
{
	if(tasksOK == controlBits)
	{
		if(HAL_IWDG_Refresh(&hiwdg1) != HAL_OK) //reset the watchdog
		{
			Error_Handler();
		}
		tasksOK = 0; //reset the control
	}
}

/***********************************************************************************************************************************
 *  Method Name        : setWdrcFlags
 *
 *  Method Description : method to set a flag on watch-dog control
 *
 *  Entry              : wdResetControl& wdrc,  fill in the enum item to set.
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void watchdog::setWdrcFlags(uint8_t wdrc)
{
	tasksOK = ut->setBit(tasksOK, wdrc); //set taskId
}

/***********************************************************************************************************************************
 *  Method Name        : getFaultCode
 *
 *  Method Description : method to show bits that are not set, this to be able to see what went wrong.
 *  					 These bits must be reported.
 *
 *  Entry              : None
 *
 *  Exit               : tasksOK, the complete control value
 *
 **********************************************************************************************************************************/
uint32_t watchdog::getFaultCode(void)//(alarmManager& alrm)
{
	faultCode = tasksOK ^ controlBits;
	if(faultCode == 0)
	{
		resetWatchDog(); //reset the watchdog if all is running
	}

#ifdef VERSION2
	uint8_t offset = static_cast<uint8_t>(problemEvents::WD_RTOS);
	for(uint8_t i=0; i<32; i++)
	{
		problemEvents test = static_cast<problemEvents>(i + offset);
		if(ut->checkBit(faultCode, i))
		{
			alrm.setAlarm(test, errorTypes::ERROR_MSG); //set all wd errors
		}
		else
		{
			alrm.resetAlarm(test); //if it has no error, clear it
		}
	}
#endif
	tasksOK = 0;

	return faultCode;
}

