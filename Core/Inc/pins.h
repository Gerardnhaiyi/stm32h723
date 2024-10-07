 /***********************************************************************************************************************************
 *  File name          : pins.hpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 20, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_PINS_H_

/***********************************************************************************************************************************
 *  Used defines       : 
 **********************************************************************************************************************************/
    #define	INC_PINS_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

	#include "gpio.h"
	#include <generic.h>


	#ifndef VERSION2
		// pinconfiguration for lower than V2.xx boards (BGA chip)
		//Port A
		#define XTR_FMC_GPIO_Port           GPIOA
		#define XTR_FMC_Pin                 GPIO_PIN_0
		#define IN_nFLT_GPIO_Port           GPIOA
		#define IN_nFLT_Pin                 GPIO_PIN_1
		#define IN_IMON_GPIO_Port           GPIOA
		#define IN_IMON_Pin                 GPIO_PIN_2
		#define SENSE_24V_GPIO_Port         GPIOA
		#define SENSE_24V_Pin               GPIO_PIN_3
		#define DAC_SCLK_GPIO_Port          GPIOA
		#define DAC_SCLK_Pin                GPIO_PIN_5
		#define DAC_SS_GPIO_Port            GPIOA
		#define DAC_SS_Pin                  GPIO_PIN_6
		#define DAC_MOSI_GPIO_Port          GPIOA
		#define DAC_MOSI_Pin                GPIO_PIN_7
		#define MTF_SCL_GPIO_Port           GPIOA
		#define MTF_SCL_Pin                 GPIO_PIN_8
		#define USB_FS_VBUS_GPIO_Port       GPIOA
		#define USB_FS_VBUS_Pin             GPIO_PIN_9
		#define MTF_RESET_GPIO_Port         GPIOA
		#define MTF_RESET_Pin               GPIO_PIN_10
		#define USB_DAT_N_GPIO_Port         GPIOA
		#define USB_DAT_N_Pin               GPIO_PIN_11
		#define USB_DAT_P_GPIO_Port         GPIOA
		#define USB_DAT_P_Pin               GPIO_PIN_12
		#define SWDIO_GPIO_Port             GPIOA
		#define SWDIO_Pin                   GPIO_PIN_13
		#define SWCLK_GPIO_Port             GPIOA
		#define SWCLK_Pin                   GPIO_PIN_14
		#define IN_nSHDN_GPIO_Port          GPIOA
		#define IN_nSHDN_Pin                GPIO_PIN_15
		//Port B
		#define XTR_M2_GPIO_Port            GPIOB
		#define XTR_M2_Pin                  GPIO_PIN_0
		#define XTR_OD_GPIO_Port            GPIOB
		#define XTR_OD_Pin                  GPIO_PIN_1
		#define FLASH_CLK_GPIO_Port         GPIOB
		#define FLASH_CLK_Pin               GPIO_PIN_2
		#define SWO_GPIO_Port               GPIOB
		#define SWO_Pin                     GPIO_PIN_3
		#define mA_EN_CH3_GPIO_Port         GPIOB
		#define mA_EN_CH3_Pin               GPIO_PIN_4
		#define VIRT_GND_nEN_CH1_GPIO_Port  GPIOB
		#define VIRT_GND_nEN_CH1_Pin        GPIO_PIN_5
		#define ADC_RESET_GPIO_Port         GPIOB
		#define ADC_RESET_Pin               GPIO_PIN_7
		#define ADC_nDRDY_EXTI_IRQn         EXTI9_5_IRQn
		#define ADC_nDRDY_GPIO_Port         GPIOB
		#define ADC_nDRDY_Pin               GPIO_PIN_8
		#define ADC_nCS_GPIO_Port           GPIOB
		#define ADC_nCS_Pin                 GPIO_PIN_9
		#define TEMP_SCL_GPIO_Port          GPIOB
		#define TEMP_SCL_Pin                GPIO_PIN_10
		#define TEMP_SDA_GPIO_Port          GPIOB
		#define TEMP_SDA_Pin                GPIO_PIN_11
		#define TEMP_ALERT_EXTI_IRQn        EXTI15_10_IRQn
		#define TEMP_ALERT_GPIO_Port        GPIOB
		#define TEMP_ALERT_Pin              GPIO_PIN_12
		#define TimingPin_GPIO_Port         GPIOB
		#define TimingPin_Pin               GPIO_PIN_13
		//Port C
		#define XTR_FOT_EXTI_IRQn           EXTI0_IRQn
		#define XTR_FOT_GPIO_Port           GPIOC
		#define XTR_FOT_Pin                 GPIO_PIN_0
		#define XTR_FLD_EXTI_IRQn           EXTI1_IRQn
		#define XTR_FLD_GPIO_Port           GPIOC
		#define XTR_FLD_Pin                 GPIO_PIN_1
		#define RS485_TX_EN_GPIO_Port       GPIOC
		#define RS485_TX_EN_Pin             GPIO_PIN_2
		#define XTR_IMON_GPIO_Port          GPIOC
		#define XTR_IMON_Pin                GPIO_PIN_3
		#define XTR_IAOUT_GPIO_Port         GPIOC
		#define XTR_IAOUT_Pin               GPIO_PIN_4
		#define XTR_M1_GPIO_Port            GPIOC
		#define XTR_M1_Pin                  GPIO_PIN_5
		#define MTF_EOC_EXTI_IRQn           EXTI9_5_IRQn
		#define MTF_EOC_GPIO_Port           GPIOC
		#define MTF_EOC_Pin                 GPIO_PIN_7
		#define MTF_SDA_GPIO_Port           GPIOC
		#define MTF_SDA_Pin                 GPIO_PIN_9
		#define FLASH_nCS_GPIO_Port         GPIOC
		#define FLASH_nCS_Pin               GPIO_PIN_11
		#define RS485_RX_EN_GPIO_Port       GPIOC
		#define RS485_RX_EN_Pin             GPIO_PIN_13
		#define CR_32_N_GPIO_Port       	GPIOC
		#define CR_32_N_Pin             	GPIO_PIN_14
		#define CR_32_P_GPIO_Port       	GPIOC
		#define CR_32_P_Pin             	GPIO_PIN_15
		//Port D
		#define USER_BTN_GPIO_Port          GPIOD
		#define USER_BTN_Pin                GPIO_PIN_0
		#define VIRT_GND_nEN_CH3_GPIO_Port  GPIOD
		#define VIRT_GND_nEN_CH3_Pin        GPIO_PIN_2
		#define CHAN_EN_CH3_GPIO_Port       GPIOD
		#define CHAN_EN_CH3_Pin             GPIO_PIN_5
		#define CHAN_EN_CH1_GPIO_Port       GPIOD
		#define CHAN_EN_CH1_Pin             GPIO_PIN_6
		#define mA_EN_CH1_GPIO_Port         GPIOD
		#define mA_EN_CH1_Pin               GPIO_PIN_7
		#define LED_G_GPIO_Port             GPIOD
		#define LED_G_Pin                   GPIO_PIN_8
		#define LED_R_GPIO_Port             GPIOD
		#define LED_R_Pin                   GPIO_PIN_9
		#define CHAN_EN_CH2_GPIO_Port       GPIOD
		#define CHAN_EN_CH2_Pin             GPIO_PIN_10
		#define mA_EN_CH2_GPIO_Port         GPIOD
		#define mA_EN_CH2_Pin               GPIO_PIN_11
		#define LED_B_GPIO_Port             GPIOD
		#define LED_B_Pin                   GPIO_PIN_12
		#define VIRT_GND_nEN_CH2_GPIO_Port  GPIOD
		#define VIRT_GND_nEN_CH2_Pin        GPIO_PIN_13
		//Port E
		#define RS485_RX_GPIO_Port          GPIOE
		#define RS485_RX_Pin                GPIO_PIN_0
		#define RS485_TX_GPIO_Port          GPIOE
		#define RS485_TX_Pin                GPIO_PIN_1
		#define ADC_SCLK_GPIO_Port          GPIOE
		#define ADC_SCLK_Pin                GPIO_PIN_2
		#define RS485_THERM_EN_GPIO_Port    GPIOE
		#define RS485_THERM_EN_Pin          GPIO_PIN_4
		#define ADC_MISO_GPIO_Port          GPIOE
		#define ADC_MISO_Pin                GPIO_PIN_5
		#define ADC_MOSI_GPIO_Port          GPIOE
		#define ADC_MOSI_Pin                GPIO_PIN_6
		#define FLASH_IO0_GPIO_Port         GPIOE
		#define FLASH_IO0_Pin               GPIO_PIN_7
		#define FLASH_IO1_GPIO_Port         GPIOE
		#define FLASH_IO1_Pin               GPIO_PIN_8
		#define FLASH_IO2_GPIO_Port         GPIOE
		#define FLASH_IO2_Pin               GPIO_PIN_9
		#define FLASH_IO3_GPIO_Port         GPIOE
		#define FLASH_IO3_Pin               GPIO_PIN_10
		#define PWM_VALVE1_GPIO_Port        GPIOE
		#define PWM_VALVE1_Pin              GPIO_PIN_11
		#define PWM_VALVE2_GPIO_Port        GPIOE
		#define PWM_VALVE2_Pin              GPIO_PIN_13
		//Port H
		#define CR_N_GPIO_Port          	GPIOH
		#define CR_N_Pin                	GPIO_PIN_0
		#define CR_P_GPIO_Port          	GPIOH
		#define CR_P_Pin                	GPIO_PIN_1
	#else
		//pinconfiguration for V2.xx (QFN chip)
		//Port A
		#define FRAM_nCS_GPIO_Port          GPIOA
		#define FRAM_nCS_Pin                GPIO_PIN_0
		#define IN_nFLT_GPIO_Port           GPIOA
		#define IN_nFLT_Pin                 GPIO_PIN_1
		#define IN_IMON_GPIO_Port           GPIOA
		#define IN_IMON_Pin                 GPIO_PIN_2
		#define SENSE_24V_GPIO_Port         GPIOA
		#define SENSE_24V_Pin               GPIO_PIN_3
		#define SEN_OUT_nSYNC_B_GPIO_Port   GPIOA
		#define SEN_OUT_nSYNC_B_Pin         GPIO_PIN_4
		#define FRAM_SCK_GPIO_Port          GPIOA
		#define FRAM_SCK_Pin                GPIO_PIN_5
		#define FRAM_MISO_GPIO_Port         GPIOA
		#define FRAM_MISO_Pin               GPIO_PIN_6
		#define FRAM_MOSI_GPIO_Port         GPIOA
		#define FRAM_MOSI_Pin               GPIO_PIN_7
		#define MTF_SCL_GPIO_Port           GPIOA
		#define MTF_SCL_Pin                 GPIO_PIN_8
		#define USB_FS_VBUS_GPIO_Port       GPIOA
		#define USB_FS_VBUS_Pin             GPIO_PIN_9
		#define MTF_RESET_GPIO_Port         GPIOA
		#define MTF_RESET_Pin               GPIO_PIN_10
		#define USB_DAT_N_GPIO_Port         GPIOA
		#define USB_DAT_N_Pin               GPIO_PIN_11
		#define USB_DAT_P_GPIO_Port         GPIOA
		#define USB_DAT_P_Pin               GPIO_PIN_12
		#define SWDIO_GPIO_Port             GPIOA
		#define SWDIO_Pin                   GPIO_PIN_13
		#define SWCLK_GPIO_Port             GPIOA
		#define SWCLK_Pin                   GPIO_PIN_14
		#define IN_nSHDN_GPIO_Port          GPIOA
		#define IN_nSHDN_Pin                GPIO_PIN_15
		//Port B
		#define DAC_nFAULT_EXTI_IRQn        EXTI0_IRQn
		#define DAC_nFAULT_GPIO_Port        GPIOB
		#define DAC_nFAULT_Pin              GPIO_PIN_0
		#define FLASH_CLK_GPIO_Port         GPIOB
		#define FLASH_CLK_Pin               GPIO_PIN_2
		#define SWO_GPIO_Port               GPIOB
		#define SWO_Pin                     GPIO_PIN_3
		#define mA_EN_CH3_GPIO_Port         GPIOB
		#define mA_EN_CH3_Pin               GPIO_PIN_4
		#define VIRT_GND_nEN_CH1_GPIO_Port  GPIOB
		#define VIRT_GND_nEN_CH1_Pin        GPIO_PIN_5
		#define VALVE1_EN_GPIO_Port         GPIOB
		#define VALVE1_EN_Pin               GPIO_PIN_6
		#define ADC_RESET_GPIO_Port         GPIOB
		#define ADC_RESET_Pin               GPIO_PIN_7
		#define ADC_nCS_GPIO_Port           GPIOB
		#define ADC_nCS_Pin                 GPIO_PIN_9
		#define TEMP_SCL_GPIO_Port          GPIOB
		#define TEMP_SCL_Pin                GPIO_PIN_10
		#define TEMP_SDA_GPIO_Port          GPIOB
		#define TEMP_SDA_Pin                GPIO_PIN_11
		#define TEMP_ALERT_EXTI_IRQn        EXTI15_10_IRQn
		#define TEMP_ALERT_GPIO_Port        GPIOB
		#define TEMP_ALERT_Pin              GPIO_PIN_12
		#define TimingPin_GPIO_Port         GPIOB
		#define TimingPin_Pin               GPIO_PIN_13
		#define DAC_MISO_GPIO_Port          GPIOB
		#define DAC_MISO_Pin                GPIO_PIN_14
		#define DAC_MOSI_GPIO_Port          GPIOB
		#define DAC_MOSI_Pin                GPIO_PIN_15
		//Port C
		#define FRAM_nWP_GPIO_Port          GPIOC
		#define FRAM_nWP_Pin                GPIO_PIN_0
		#define FRAM_nHOLD_GPIO_Port        GPIOC
		#define FRAM_nHOLD_Pin              GPIO_PIN_1
		#define RS485_TX_EN_GPIO_Port       GPIOC
		#define RS485_TX_EN_Pin             GPIO_PIN_2
		#define DAC_nSYNC_GPIO_Port         GPIOC
		#define DAC_nSYNC_Pin               GPIO_PIN_5
		#define SEL_IN_OUT_CH1_GPIO_Port    GPIOC
		#define SEL_IN_OUT_CH1_Pin          GPIO_PIN_6
		#define MTF_EOC_EXTI_IRQn           EXTI9_5_IRQn
		#define MTF_EOC_GPIO_Port           GPIOC
		#define MTF_EOC_Pin                 GPIO_PIN_7
		#define SEN_OUT_nFAULT_B_EXTI_IRQn  EXTI9_5_IRQn
		#define SEN_OUT_nFAULT_B_GPIO_Port  GPIOC
		#define SEN_OUT_nFAULT_B_Pin        GPIO_PIN_8
		#define MTF_SDA_GPIO_Port           GPIOC
		#define MTF_SDA_Pin                 GPIO_PIN_9
		#define VALVE1_n12V_GPIO_Port       GPIOC
		#define VALVE1_n12V_Pin             GPIO_PIN_10
		#define FLASH_nCS_GPIO_Port         GPIOC
		#define FLASH_nCS_Pin               GPIO_PIN_11
		#define SEL_IN_OUT_CH2_GPIO_Port    GPIOC
		#define SEL_IN_OUT_CH2_Pin          GPIO_PIN_12
		#define RS485_RX_EN_GPIO_Port       GPIOC
		#define RS485_RX_EN_Pin             GPIO_PIN_13
		#define CR_32_N_GPIO_Port           GPIOC
		#define CR_32_N_Pin                 GPIO_PIN_14
		#define CR_32_P_GPIO_Port           GPIOC
		#define CR_32_P_Pin                 GPIO_PIN_15
		//Port D
		#define USER_BTN_GPIO_Port          GPIOD
		#define USER_BTN_Pin                GPIO_PIN_0
		#define SEN_OUT_nFAULT_A_GPIO_Port  GPIOD
		#define SEN_OUT_nFAULT_A_Pin        GPIO_PIN_1
		#define SEN_OUT_nFAULT_A_EXTI_IRQn  EXTI1_IRQn
		#define VIRT_GND_nEN_CH3_GPIO_Port  GPIOD
		#define VIRT_GND_nEN_CH3_Pin        GPIO_PIN_2
		#define DAC_SCK_GPIO_Port           GPIOD
		#define DAC_SCK_Pin                 GPIO_PIN_3
		#define VALVE2_n12V_GPIO_Port       GPIOD
		#define VALVE2_n12V_Pin             GPIO_PIN_4
		#define CHAN_EN_CH3_GPIO_Port       GPIOD
		#define CHAN_EN_CH3_Pin             GPIO_PIN_5
		#define CHAN_EN_CH1_GPIO_Port       GPIOD
		#define CHAN_EN_CH1_Pin             GPIO_PIN_6
		#define mA_EN_CH1_GPIO_Port         GPIOD
		#define mA_EN_CH1_Pin               GPIO_PIN_7
		#define LED_G_GPIO_Port             GPIOD
		#define LED_G_Pin                   GPIO_PIN_8
		#define LED_R_GPIO_Port             GPIOD
		#define LED_R_Pin                   GPIO_PIN_9
		#define CHAN_EN_CH2_GPIO_Port       GPIOD
		#define CHAN_EN_CH2_Pin             GPIO_PIN_10
		#define mA_EN_CH2_GPIO_Port         GPIOD
		#define mA_EN_CH2_Pin               GPIO_PIN_11
		#define LED_B_GPIO_Port             GPIOD
		#define LED_B_Pin                   GPIO_PIN_12
		#define VIRT_GND_nEN_CH2_GPIO_Port  GPIOD
		#define VIRT_GND_nEN_CH2_Pin        GPIO_PIN_13
		#define VALVE2_EN_GPIO_Port         GPIOD
		#define VALVE2_EN_Pin               GPIO_PIN_14
		#define SEN_OUT_nSYNC_A_GPIO_Port   GPIOD
		#define SEN_OUT_nSYNC_A_Pin         GPIO_PIN_15
		//Port E
		#define RS485_RX_GPIO_Port          GPIOE
		#define RS485_RX_Pin                GPIO_PIN_0
		#define RS485_TX_GPIO_Port          GPIOE
		#define RS485_TX_Pin                GPIO_PIN_1
		#define ADC_SCLK_GPIO_Port          GPIOE
		#define ADC_SCLK_Pin                GPIO_PIN_2
		#define SEN_OUT_nRESET_GPIO_Port    GPIOE
		#define SEN_OUT_nRESET_Pin          GPIO_PIN_3
		#define RS485_THERM_EN_GPIO_Port    GPIOE
		#define RS485_THERM_EN_Pin          GPIO_PIN_4
		#define ADC_MISO_GPIO_Port          GPIOE
		#define ADC_MISO_Pin                GPIO_PIN_5
		#define ADC_MOSI_GPIO_Port          GPIOE
		#define ADC_MOSI_Pin                GPIO_PIN_6
		#define FLASH_IO0_GPIO_Port         GPIOE
		#define FLASH_IO0_Pin               GPIO_PIN_7
		#define FLASH_IO1_GPIO_Port         GPIOE
		#define FLASH_IO1_Pin               GPIO_PIN_8
		#define FLASH_IO2_GPIO_Port         GPIOE
		#define FLASH_IO2_Pin               GPIO_PIN_9
		#define FLASH_IO3_GPIO_Port         GPIOE
		#define FLASH_IO3_Pin               GPIO_PIN_10
		#define PWM_VALVE1_GPIO_Port        GPIOE
		#define PWM_VALVE1_Pin              GPIO_PIN_11
		#define PWM_VALVE2_GPIO_Port        GPIOE
		#define PWM_VALVE2_Pin              GPIO_PIN_13
		#define VALVE1_24V_GPIO_Port        GPIOE
		#define VALVE1_24V_Pin              GPIO_PIN_14
		#define VALVE2_24V_GPIO_Port        GPIOE
		#define VALVE2_24V_Pin              GPIO_PIN_15
		//Port H
		#define CR_N_GPIO_Port              GPIOH
		#define CR_N_Pin                    GPIO_PIN_0
		#define CR_P_GPIO_Port              GPIOH
		#define CR_P_Pin                    GPIO_PIN_1
	#endif

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used constantes    :
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
 *	Class name         : 
 *
 *  Class Description  : 
 *
 *	Inheritance        : None
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/

	#ifdef __cplusplus
		}
	#endif

    
#endif	/* INC_PINS_H_ */

