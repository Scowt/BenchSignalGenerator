#ifndef INC_IODEFS_H_
#define INC_IODEFS_H_

#include "stm32l4xx_hal.h"

#define FREQ_CLOCK			75000000

#define Select_Pin 			GPIO_PIN_13
#define Select_GPIO_Port 	GPIOC
#define Power_Pin 			GPIO_PIN_14
#define Power_GPIO_Port 	GPIOC
#define Enter_Pin 			GPIO_PIN_15
#define Enter_GPIO_Port 	GPIOC
#define Phase_Pin 			GPIO_PIN_0
#define Phase_GPIO_Port 	GPIOH
#define Spare_Pin 			GPIO_PIN_1
#define Spare_GPIO_Port 	GPIOH
#define DebugLed_Pin 		GPIO_PIN_8
#define DebugLed_GPIO_Port 	GPIOA
#define Amplitude_Pin 		GPIO_PIN_5
#define Amplitude_GPIO_Port GPIOB
#define WaveType_Pin 		GPIO_PIN_8
#define WaveType_GPIO_Port 	GPIOB
#define Frequency_Pin 		GPIO_PIN_9
#define Frequency_GPIO_Port GPIOB

#define DDS_CS_Pin 			GPIO_PIN_12
#define DDS_CS_Port 		GPIOB
#define DDS_CLK_Pin 		GPIO_PIN_13
#define DDS_CLK_Port 		GPIOB
#define DDS_MOSI_Pin 		GPIO_PIN_15
#define DDS_MOSI_Port 		GPIOB

#define DDS_ResetWave_Pin 	GPIO_PIN_2
#define DDS_ResetWave_Port 	GPIOB



#endif
