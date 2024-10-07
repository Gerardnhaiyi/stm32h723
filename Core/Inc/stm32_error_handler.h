#ifndef __ERROR_HANDLERS
#define __ERROR_HANDLERS

#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
	//User can add his own implementation to report the HAL error return state
	__disable_irq();
	while (1)
	{
	}
	//USER CODE END Error_Handler_Debug
}

#ifdef __cplusplus
}
#endif
#endif /*__ERROR_HANDLERS*/