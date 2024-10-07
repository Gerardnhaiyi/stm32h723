/***********************************************************************************************************************************
 *  File name          : callbacks.h
 *  Author             : Gerard
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Aug 30, 2024
 *
 *  File Description   : This file contains all the callback functions of the eq_da
 *
 **********************************************************************************************************************************/
#ifndef INC_CALLBACKS_H_
#define INC_CALLBACKS_H_

/*#include "rs485.hpp"
#include "flashCommands.hpp"
#include "SHT30.hpp"
#include "statusLed.hpp"*/


#ifdef __cplusplus
	extern "C" {
#endif


/***********************************************************************************************************************************
 *  Used Prototypes    :
 **********************************************************************************************************************************/
/*	rs485 rs;
	flashCommands fcmd;
	dataStorage sd;
	statusLed sLed(&sd, 75);*/

/***********************************************************************************************************************************
 *  uart
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : HAL_UART_TxCpltCallback
 *
 *  Method Description : Callback function
 *
 *  Entry              : UART_HandleTypeDef *huart
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
/*void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	rs.endTransmitRsData();
}*/

/***********************************************************************************************************************************
 *  flash
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : HAL_OSPI_RxCpltCallback
 *
 *  Method Description : receive callback function
 *
 *  Entry              : *hospi, finish the receive function on flash memory
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
/*void HAL_OSPI_RxCpltCallback(OSPI_HandleTypeDef *hospi)
{
	fcmd.setDataReady();
}*/

/***********************************************************************************************************************************
 *  Method Name        : HAL_OSPI_TxCpltCallback
 *
 *  Method Description : transmit callback function
 *
 *  Entry              : *hospi, finish the transmit function on flash memory
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
/*void HAL_OSPI_TxCpltCallback(OSPI_HandleTypeDef *hospi)
{
    if (fcmd.state == flashState::WRITING)
    {
    	fcmd.state = flashState::FINISHED_WRITING;
    }
}*/

/***********************************************************************************************************************************
 *  temperature & humidity
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : HAL_GPIO_Temp_Alert_Callback
 *
 *  Method Description : method to set an alert
 *
 *  Entry              : None
 *
 *  Exit               : GPIO_Pin, interrupt pin that start the callback
 *
 **********************************************************************************************************************************/
/*void HAL_GPIO_Temp_Alert_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == TEMP_ALERT_Pin) //SHT30
    {
    	sht30Sensor alertRegistered;
    }
}*/

/***********************************************************************************************************************************
 *  timers
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : timerCallback
 *
 *  Method Description : Period elapsed callback in non blocking mode.
 *  					 This function is called  when the period timer of RTOS interrupt took place.
 *  					 It will call the method to set the color led status. This should run every period.
 *
 *  Entry              : argument, not used
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
/*void timerCallback(void *argument)
{
	sLed.run();
}*/

/***********************************************************************************************************************************
 *  Method Name        : HAL_TIM_PeriodElapsedCallback
 *
 *  Method Description : Period elapsed callback in non blocking mode.
 *  					 This function is called  when TIM6 interrupt took place, inside HAL_TIM_IRQHandler(). It makes a
 *  					 direct call to HAL_IncTick() to increment a global variable "uwTick" used as application time base.
 *
 *  Entry              : htim, TIM handle
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM2)
	{
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}



#ifdef __cplusplus
}
#endif

#endif /* INC_CALLBACKS_H_ */
