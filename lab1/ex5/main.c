/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void setLed(uint16_t PIN1_Pin,uint16_t PIN2_Pin,uint16_t PIN3_Pin,uint16_t PIN4_Pin,uint16_t PIN5_Pin,uint16_t PIN6_Pin,uint16_t PIN7_Pin
		,GPIO_TypeDef* PIN1_GPIO_Port,GPIO_TypeDef* PIN2_GPIO_Port,GPIO_TypeDef* PIN3_GPIO_Port
		,GPIO_TypeDef* PIN4_GPIO_Port,GPIO_TypeDef* PIN5_GPIO_Port,GPIO_TypeDef* PIN6_GPIO_Port,GPIO_TypeDef* PIN7_GPIO_Port
		,int timer);

void setLight(uint16_t redPin, uint16_t yellowPin, uint16_t greenPin,		// Light's Pins
			GPIO_TypeDef* redGPIO, GPIO_TypeDef* yellowGPIO, GPIO_TypeDef* greenGPIO,	// Light's GPIO
			uint16_t PIN1_Pin,uint16_t PIN2_Pin,uint16_t PIN3_Pin,uint16_t PIN4_Pin,uint16_t PIN5_Pin,uint16_t PIN6_Pin,uint16_t PIN7_Pin	// 7SEG's Pin
			,GPIO_TypeDef* PIN1_GPIO_Port,GPIO_TypeDef* PIN2_GPIO_Port,GPIO_TypeDef* PIN3_GPIO_Port	// 7SEG 's GPIO
			,GPIO_TypeDef* PIN4_GPIO_Port,GPIO_TypeDef* PIN5_GPIO_Port,GPIO_TypeDef* PIN6_GPIO_Port,GPIO_TypeDef* PIN7_GPIO_Port, // 7SEG 's GPIO
			int timer)
{
	if(timer<6){	//Yellow off RED on
		HAL_GPIO_WritePin(yellowGPIO, yellowPin,RESET);
		HAL_GPIO_WritePin(redGPIO, redPin,SET);
		setLed(PIN1_Pin, PIN2_Pin, PIN3_Pin, PIN4_Pin, PIN5_Pin, PIN6_Pin, PIN7_Pin,
				  PIN1_GPIO_Port, PIN2_GPIO_Port, PIN3_GPIO_Port, PIN4_GPIO_Port, PIN5_GPIO_Port, PIN6_GPIO_Port, PIN7_GPIO_Port,
				  5 - timer);
	}
	if(timer>=6){	//RED off GREEN on
		HAL_GPIO_WritePin(redGPIO, redPin,RESET);
		HAL_GPIO_WritePin(greenGPIO, greenPin,SET);
		setLed(PIN1_Pin, PIN2_Pin, PIN3_Pin, PIN4_Pin, PIN5_Pin, PIN6_Pin, PIN7_Pin,
				  PIN1_GPIO_Port, PIN2_GPIO_Port, PIN3_GPIO_Port, PIN4_GPIO_Port, PIN5_GPIO_Port, PIN6_GPIO_Port, PIN7_GPIO_Port,
				  8 - timer);
	}
	if(timer>=9){	//GREEN off YELLOW on
		HAL_GPIO_WritePin(greenGPIO, greenPin,RESET);
		HAL_GPIO_WritePin(yellowGPIO, yellowPin,SET);
		setLed(PIN1_Pin, PIN2_Pin, PIN3_Pin, PIN4_Pin, PIN5_Pin, PIN6_Pin, PIN7_Pin,
				  PIN1_GPIO_Port, PIN2_GPIO_Port, PIN3_GPIO_Port, PIN4_GPIO_Port, PIN5_GPIO_Port, PIN6_GPIO_Port, PIN7_GPIO_Port,
				  10 - timer);
	}
}
void setLed(uint16_t PIN1_Pin,uint16_t PIN2_Pin,uint16_t PIN3_Pin,uint16_t PIN4_Pin,uint16_t PIN5_Pin,uint16_t PIN6_Pin,uint16_t PIN7_Pin
		,GPIO_TypeDef* PIN1_GPIO_Port,GPIO_TypeDef* PIN2_GPIO_Port,GPIO_TypeDef* PIN3_GPIO_Port
		,GPIO_TypeDef* PIN4_GPIO_Port,GPIO_TypeDef* PIN5_GPIO_Port,GPIO_TypeDef* PIN6_GPIO_Port,GPIO_TypeDef* PIN7_GPIO_Port
		,int timer)
{
	switch(timer){
	case 0:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, RESET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, SET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, SET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, SET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, SET);
			break;
	case 2:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, SET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, RESET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, SET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, SET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, SET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, SET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, SET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, SET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, RESET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, SET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, SET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, RESET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, RESET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, RESET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, RESET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, RESET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, RESET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin(PIN1_GPIO_Port,PIN1_Pin, SET);
		HAL_GPIO_WritePin(PIN2_GPIO_Port,PIN2_Pin, SET);
		HAL_GPIO_WritePin(PIN3_GPIO_Port,PIN3_Pin, SET);
		HAL_GPIO_WritePin(PIN4_GPIO_Port,PIN4_Pin, SET);
		HAL_GPIO_WritePin(PIN5_GPIO_Port,PIN5_Pin, SET);
		HAL_GPIO_WritePin(PIN6_GPIO_Port,PIN6_Pin, SET);
		HAL_GPIO_WritePin(PIN7_GPIO_Port,PIN7_Pin, SET);
		break;
	}
}
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

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  // VARs:
  /*
    1. timer_1 using for counting time of each light on trafic light 1,3.
    2. timer_2 using for counting time of each light on trafic light 2,4.
  */
  int timer_1 = 10;
  int timer_2 = 10;

	//SET ALL Segments off

  setLed(PINB_7_Pin, PINB_8_Pin, PINB_9_Pin, PINB_10_Pin, PINB_11_Pin, PINB_12_Pin, PINB_13_Pin,
  		  PINB_7_GPIO_Port, PINB_8_GPIO_Port, PINB_9_GPIO_Port, PINB_10_GPIO_Port, PINB_11_GPIO_Port, PINB_12_GPIO_Port, PINB_13_GPIO_Port,
  		  timer_2);


  	// SET ALL Lights off
	HAL_GPIO_WritePin(PINA_1_GPIO_Port, PINA_1_Pin,RESET);
	HAL_GPIO_WritePin(PINA_2_GPIO_Port, PINA_2_Pin,RESET);
	HAL_GPIO_WritePin(PINA_3_GPIO_Port, PINA_3_Pin,RESET);

	HAL_GPIO_WritePin(PINA_4_GPIO_Port, PINA_4_Pin,RESET);
	HAL_GPIO_WritePin(PINA_5_GPIO_Port, PINA_5_Pin,RESET);
	HAL_GPIO_WritePin(PINA_6_GPIO_Port, PINA_6_Pin,RESET);


  // SET INITIAL VALUE of timer
  timer_1 = 0;
  timer_2 = timer_1 + 5;


//START LOOP

  while (1)
  {
	  if(timer_1<10){
		  timer_1 += 1;
		  setLight(PINA_1_Pin, PINA_2_Pin, PINA_3_Pin,
				PINA_1_GPIO_Port, PINA_2_GPIO_Port, PINA_3_GPIO_Port,
				PINB_0_Pin, PINB_1_Pin, PINB_2_Pin, PINB_3_Pin, PINB_4_Pin, PINB_5_Pin, PINB_6_Pin,
				PINB_0_GPIO_Port, PINB_1_GPIO_Port, PINB_2_GPIO_Port, PINB_3_GPIO_Port, PINB_4_GPIO_Port, PINB_5_GPIO_Port, PINB_6_GPIO_Port,
				timer_1);
	  }

	  if(timer_1>=10){
		  timer_1 = 0;
	  }

	  if(timer_2<10){
		  timer_2+=1;
		  setLight(	PINA_4_Pin, PINA_5_Pin, PINA_6_Pin,
				PINA_4_GPIO_Port, PINA_5_GPIO_Port, PINA_6_GPIO_Port,
				PINB_7_Pin, PINB_8_Pin, PINB_9_Pin, PINB_10_Pin, PINB_11_Pin, PINB_12_Pin, PINB_13_Pin,
				PINB_7_GPIO_Port, PINB_8_GPIO_Port, PINB_9_GPIO_Port, PINB_10_GPIO_Port, PINB_11_GPIO_Port, PINB_12_GPIO_Port, PINB_13_GPIO_Port,
				timer_2);
	  }

	  if(timer_2>=10){
		  timer_2 = 0;
	  }

	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PINA_1_Pin|PINA_2_Pin|PINA_3_Pin|PINA_4_Pin
                          |PINA_5_Pin|PINA_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, PINB_0_Pin|PINB_1_Pin|PINB_2_Pin|PINB_10_Pin
                          |PINB_11_Pin|PINB_12_Pin|PINB_13_Pin|PINB_3_Pin
                          |PINB_4_Pin|PINB_5_Pin|PINB_6_Pin|PINB_7_Pin
                          |PINB_8_Pin|PINB_9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PINA_1_Pin PINA_2_Pin PINA_3_Pin PINA_4_Pin
                           PINA_5_Pin PINA_6_Pin */
  GPIO_InitStruct.Pin = PINA_1_Pin|PINA_2_Pin|PINA_3_Pin|PINA_4_Pin
                          |PINA_5_Pin|PINA_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PINB_0_Pin PINB_1_Pin PINB_2_Pin PINB_10_Pin
                           PINB_11_Pin PINB_12_Pin PINB_13_Pin PINB_3_Pin
                           PINB_4_Pin PINB_5_Pin PINB_6_Pin PINB_7_Pin
                           PINB_8_Pin PINB_9_Pin */
  GPIO_InitStruct.Pin = PINB_0_Pin|PINB_1_Pin|PINB_2_Pin|PINB_10_Pin
                          |PINB_11_Pin|PINB_12_Pin|PINB_13_Pin|PINB_3_Pin
                          |PINB_4_Pin|PINB_5_Pin|PINB_6_Pin|PINB_7_Pin
                          |PINB_8_Pin|PINB_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
