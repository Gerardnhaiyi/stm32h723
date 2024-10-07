/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "bdma.h"
#include "dma.h"
#include "i2c.h"
#include "mdma.h"
#include "memorymap.h"
#include "octospi.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include "iwdg.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "systemClock.h"
#include "stm32_error_handler.h"
#include "callbacks.h"
#if defined(USE_FULL_ASSERT)
	#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

#include <generic.h>
#include "rtc.hpp"
#include "dataStorage.hpp"
#include "watchdog.hpp"
#include "xLDRefpres.hpp"
#include "utils.hpp"
//#include "ina219.hpp"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


//Local objects, used on multiple tasks
dataStorage ds;
rtcTimer rtc;
utils ut;
watchdog wd;

#define NR_TASKS	14
uint16_t Task[60] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool led = false;
uint32_t wdError;


/* Definitions for RefSensorThread */
osThreadId_t RefSensorThreadHandle;
const osThreadAttr_t RefSensorThread_attributes = { .name = "RefSensorThread", .stack_size = 256 * 4, .priority = (osPriority_t) osPriorityNormal,};
/* Definitions for WatchDogThread */
osThreadId_t WatchDogThreadHandle;
const osThreadAttr_t WatchDogThread_attributes = { .name = "WatchDogThread", .stack_size = 256 * 4, .priority = (osPriority_t) osPriorityNormal,};

/* Definitions for eqDaMutex */
osMutexId_t eqDaMutexHandle;
const osMutexAttr_t eqDaMutex_attributes = { .name = "eqDaMutex"};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */
void StartRefSensorThread(void *argument);
void StartWatchDogThread(void *argument);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* Configure the peripherals common clocks */
	PeriphCommonClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_BDMA_Init();
	MX_MDMA_Init();
	MX_ADC2_Init();
	MX_ADC3_Init();
	MX_ADC1_Init();
	MX_TIM1_Init();
	MX_I2C2_Init();
	MX_I2C3_Init();
	MX_OCTOSPI1_Init();
	MX_SPI4_Init();
	MX_SPI6_Init();
	MX_UART8_Init();
	MX_RTC_Init();
	MX_IWDG1_Init();

	/* USER CODE BEGIN 2 */
	//	rtc.rtcInit();

	/* USER CODE END 2 */

	/* Init scheduler */
	osKernelInitialize();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */
	/* Create the mutex(es) */
	/* creation of eqDaMutex */
	eqDaMutexHandle = osMutexNew(&eqDaMutex_attributes);

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* Create the timer(s) */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of RefSensorThread */
	RefSensorThreadHandle = osThreadNew(StartRefSensorThread, NULL, &RefSensorThread_attributes);

	/* creation of WatchDogThread */
	WatchDogThreadHandle = osThreadNew(StartWatchDogThread, NULL, &WatchDogThread_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

	osMutexRelease(eqDaMutexHandle);

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


/* USER CODE BEGIN Header_StartRefSensorThread */
/**
* @brief Function implementing the RefSensorThread thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRefSensorThread */
void StartRefSensorThread(void *argument)
{
	/* USER CODE BEGIN StartSensorControlThread */
		Task[3] = 4;
	uint8_t busAddress = 0x40;
	DMA_HandleTypeDef i2c3DmaRecv;
	DMA_HandleTypeDef i2c3DmaSend;
	I2C_HandleTypeDef hi2c3;

	xLDRefpres refP(busAddress, hi2c3, i2c3DmaRecv, i2c3DmaSend, MTF_RESET_GPIO_Port, MTF_RESET_Pin);
	/* Infinite loop */
	while(1)
	{
		osMutexAcquire(eqDaMutexHandle, osWaitForever);
		Task[23] = 24;

		refP.run(ds);
		Task[43] = 44;

		wd.setWdrcFlags(static_cast<uint8_t>(wdResetControl::REF_SENSOR_TASK));

		osMutexRelease(eqDaMutexHandle);
		osDelay(1);
	}
	/* USER CODE END StartSensorControlThread */
}

/* USER CODE BEGIN Header_StartWatchDogThread */
/**
* @brief Function implementing the WatchDogThread thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartWatchDogThread */
void StartWatchDogThread(void *argument)
{
	/* USER CODE BEGIN StartSensorControlThread */
		Task[13] = 14;
	/* Infinite loop */
	while(1)
	{
		Task[33] = 34;
		osMutexAcquire(eqDaMutexHandle, osWaitForever);
		for(uint32_t x=0; x<60000;x++) {}

		bool clear = true;
		for(uint8_t x=20; x<60;x++)
		{
			if(Task[x] == 0)
				clear = false;
		}
		for(uint8_t x=20; x<60;x++)
		{
			if(clear)
			{
				Task[x] = 0;
			}
		}

		wd.setWdrcFlags(static_cast<uint8_t>(wdResetControl::WATCHDOG_TASK));
		wdError = wd.getFaultCode();
		if(wdError == 0)
		{
			//watchdog error, at least 1 task is not running
		}

		osMutexRelease(eqDaMutexHandle);
		Task[53] = 54;
		osDelay(1);

	}
	/* USER CODE END StartSensorControlThread */
}

