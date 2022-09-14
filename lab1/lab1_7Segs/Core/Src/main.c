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
void setled(int timer){
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
//	int led_status = 0;
//	int red_count = 0;
//	int green_count = 0;
//	int yellow_count = 0;
  int timer = 10; //timer 1
//  int timer_2  = timer+5; //timer 2
	//SET ALL Segments off
  HAL_GPIO_WritePin(PIN1_GPIO_Port, PIN1_Pin,SET);
  HAL_GPIO_WritePin(PIN2_GPIO_Port, PIN2_Pin,SET);
  HAL_GPIO_WritePin(PIN3_GPIO_Port, PIN3_Pin,SET);
  HAL_GPIO_WritePin(PIN4_GPIO_Port, PIN4_Pin,SET);
  HAL_GPIO_WritePin(PIN5_GPIO_Port, PIN5_Pin,SET);
  HAL_GPIO_WritePin(PIN6_GPIO_Port, PIN6_Pin,SET);
  HAL_GPIO_WritePin(PIN7_GPIO_Port, PIN7_Pin,SET);
	//START LOOP
  while (1)
  {
	  if(timer>0){
		  setled(timer);
		  timer-=1;
	  }
	  if(timer=<0){
		  timer = 10;
	  }
	  HAL_Delay(1000);
//	  if(led_status==0){
//		  if(red_count<6){
//			  red_count+=1;
//			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin,SET);
//			  HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin,SET);
//		  }
//
//		  if(red_count>=6){
//			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin,RESET);
//			  HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin,RESET);
//			  red_count=0;
//			  led_status = 2;
//		  }
//	  }
//
//	  if(led_status==1){
//		  if(green_count<4){
//			  green_count+=1;
//			  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin,SET);
//			  HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin,SET);
//		  }
//		  if(green_count>=4){
//			  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin,RESET);
//			  HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin,RESET);
//			  green_count=0;
//			  led_status = 2;
//		  }
//	  }
//
//	  if(led_status==2){
//		  if(yellow_count<3){
//			  yellow_count+=1;
//			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin,SET);
//			  HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin,SET);
//		  }
//
//		  if(yellow_count>=3){
//			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin,RESET);
//			  HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin,RESET);
//			  yellow_count=0;
//			  led_status = 0;
//		  }
//	  }
//	  if(timer<11){
//		  timer+=1;
//		  setLed(RED_LED2_Pin, YELLOW_LED2_Pin, GREEN_LED2_Pin,
//		  			 RED_LED2_GPIO_Port, YELLOW_LED2_GPIO_Port, GREEN_LED2_GPIO_Port,
//		  			 timer);
//	  }
//	  if(timer>=11){
//		  timer = 0;
//	  }
//	  if(timer_2<11){
//		  timer_2+=1;
//		  setLed(RED_LED_Pin, YELLOW_LED_Pin, GREEN_LED_Pin,
//				 RED_LED_GPIO_Port, YELLOW_LED_GPIO_Port, GREEN_LED_GPIO_Port,
//				 timer_2);
//	  }
//	  if(timer_2>=11){
//		  timer_2 = 0;
//	  }

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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PIN1_Pin|PIN2_Pin|PIN3_Pin|PIN4_Pin
                          |PIN5_Pin|PIN6_Pin|PIN7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PIN1_Pin PIN2_Pin PIN3_Pin PIN4_Pin
                           PIN5_Pin PIN6_Pin PIN7_Pin */
  GPIO_InitStruct.Pin = PIN1_Pin|PIN2_Pin|PIN3_Pin|PIN4_Pin
                          |PIN5_Pin|PIN6_Pin|PIN7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
