/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define PINA_1_Pin GPIO_PIN_4
#define PINA_1_GPIO_Port GPIOA
#define PINA_2_Pin GPIO_PIN_5
#define PINA_2_GPIO_Port GPIOA
#define PINA_3_Pin GPIO_PIN_6
#define PINA_3_GPIO_Port GPIOA
#define PINA_4_Pin GPIO_PIN_7
#define PINA_4_GPIO_Port GPIOA
#define PINB_0_Pin GPIO_PIN_0
#define PINB_0_GPIO_Port GPIOB
#define PINB_1_Pin GPIO_PIN_1
#define PINB_1_GPIO_Port GPIOB
#define PINB_2_Pin GPIO_PIN_2
#define PINB_2_GPIO_Port GPIOB
#define PINB_10_Pin GPIO_PIN_10
#define PINB_10_GPIO_Port GPIOB
#define PINB_11_Pin GPIO_PIN_11
#define PINB_11_GPIO_Port GPIOB
#define PINB_12_Pin GPIO_PIN_12
#define PINB_12_GPIO_Port GPIOB
#define PINB_13_Pin GPIO_PIN_13
#define PINB_13_GPIO_Port GPIOB
#define PINA_5_Pin GPIO_PIN_8
#define PINA_5_GPIO_Port GPIOA
#define PINA_6_Pin GPIO_PIN_9
#define PINA_6_GPIO_Port GPIOA
#define PINB_3_Pin GPIO_PIN_3
#define PINB_3_GPIO_Port GPIOB
#define PINB_4_Pin GPIO_PIN_4
#define PINB_4_GPIO_Port GPIOB
#define PINB_5_Pin GPIO_PIN_5
#define PINB_5_GPIO_Port GPIOB
#define PINB_6_Pin GPIO_PIN_6
#define PINB_6_GPIO_Port GPIOB
#define PINB_7_Pin GPIO_PIN_7
#define PINB_7_GPIO_Port GPIOB
#define PINB_8_Pin GPIO_PIN_8
#define PINB_8_GPIO_Port GPIOB
#define PINB_9_Pin GPIO_PIN_9
#define PINB_9_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
