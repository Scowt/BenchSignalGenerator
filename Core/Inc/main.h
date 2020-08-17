/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Select_Pin GPIO_PIN_13
#define Select_GPIO_Port GPIOC
#define Power_Pin GPIO_PIN_14
#define Power_GPIO_Port GPIOC
#define Enter_Pin GPIO_PIN_15
#define Enter_GPIO_Port GPIOC
#define Phase_Pin GPIO_PIN_0
#define Phase_GPIO_Port GPIOH
#define Spare_Pin GPIO_PIN_1
#define Spare_GPIO_Port GPIOH
#define DebugLed_Pin GPIO_PIN_8
#define DebugLed_GPIO_Port GPIOA
#define Amplitude_Pin GPIO_PIN_5
#define Amplitude_GPIO_Port GPIOB
#define WaveType_Pin GPIO_PIN_8
#define WaveType_GPIO_Port GPIOB
#define Frequency_Pin GPIO_PIN_9
#define Frequency_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/