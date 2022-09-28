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
#include "software_timer.h"
#include "button.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int MAX_LED = 4;
int led_buffer[4];
int led_index = 0;


int hour =23;
int min = 59;
int sec = 55;

int MAX_LED_MATRIX = 8;
int led_matrix_index = 0;
uint16_t matrix_led_buffer[8];
void display7SEG(int timer){
	switch(timer){
	case 0:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, SET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, SET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, SET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, SET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, SET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, SET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, SET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, SET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, SET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, SET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, SET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, SET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, RESET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin(PIN_B0_GPIO_Port,PIN_B0_Pin, SET);
		HAL_GPIO_WritePin(PIN_B1_GPIO_Port,PIN_B1_Pin, SET);
		HAL_GPIO_WritePin(PIN_B2_GPIO_Port,PIN_B2_Pin, SET);
		HAL_GPIO_WritePin(PIN_B3_GPIO_Port,PIN_B3_Pin, SET);
		HAL_GPIO_WritePin(PIN_B4_GPIO_Port,PIN_B4_Pin, SET);
		HAL_GPIO_WritePin(PIN_B5_GPIO_Port,PIN_B5_Pin, SET);
		HAL_GPIO_WritePin(PIN_B6_GPIO_Port,PIN_B6_Pin, SET);
		break;
	}
}

void update7SEG(int index){
	switch(index){	// check index
	case 0:	// if index = 0 then light up first LED
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,RESET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,SET);
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,SET);
		display7SEG(led_buffer[0]);
		break;
	case 1:	// if index = 1 then light up second LED
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,RESET);
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,SET);
		display7SEG(led_buffer[1]);
		break;
	case 2:	// if index = 2 then light up third LED
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,SET);
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,RESET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,SET);
		display7SEG(led_buffer[2]);
		break;
	case 3:	// if index = 3 then light up fourth LED
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,SET);
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,RESET);
		display7SEG(led_buffer[3]);
		led_index = 0;
		break;
	default: // else then turn off all LEDs
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,SET);
		HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,SET);
		HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,SET);
		break;
	}
}

void updateClockBuffer(){
	led_buffer[0]=hour/10;
	led_buffer[1]=hour%10;
	led_buffer[2]=min/10;
	led_buffer[3]=min%10;
}

void displayMatrix(uint16_t value){
	switch(value){

	case 0x00: // 0b 0 0 0 0 0 0 0 0
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
		break;

	case 0x01: // 0b 0 0 0 0 0 0 0 1
	    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
		break;

	case 0x02: // 0b 0 0 0 0 0 0 1 0
		//..
		break;

	case 0x03: // 0b 0 0 0 0 0 0 1 1
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
		break;

	case 0x04:
		// ...
		break;

	//...

	case 0xcc: // 0b 1 1 0 0 1 1 0 0
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
		break;

	// ...
	case 0xff: // 0b 1 1 1 1 1 1 1 1
		//...
		break;

	default: // turn off all leds in all rows.
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
		break;
	}

}

void updateLEDMatrix(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		led_matrix_index = 0;
		break;
	default:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
		break;
	}
	displayMatrix(matrix_led_buffer[index]);
}

void shiftLeft(){
	int first_value = matrix_led_buffer[0];
	for(int i = 0; i<7; ++i){
		matrix_led_buffer[i] = matrix_led_buffer[i+1];
	}
	matrix_led_buffer[7] = first_value;

}

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

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	setTimer1(25);	// set timer1 to display 4 leds
	setTimer2(98); // set timer2 to display dot and second
	setTimer3(100); // set timer3 to count seconds
	setTimer4(3); // set timer4 to display led_matrix
	setTimer5(3*8); // set timer5 to shift left value.

	// Set all LEDs off
	HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A6_Pin,SET);
	HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A7_Pin,SET);
	HAL_GPIO_WritePin(PIN_A6_GPIO_Port,PIN_A8_Pin,SET);
	HAL_GPIO_WritePin(PIN_A7_GPIO_Port,PIN_A9_Pin,SET);
	HAL_GPIO_WritePin(BOT_GPIO_Port, BOT_Pin,SET);


    // A:
	/*
	 row0: 0 0 0 - - 0 0 0 		col0: 0x00
	 row1: 0 0 - - - - 0 0		col1: 0x03
	 row2: 0 - - 0 0 - - 0 		col2: 0x01
	 row3: 0 - - 0 0 - - 0		col3: 0xcc
	 row4: 0 - - - - - - 0		col4: 0xcc
	 row5: 0 - - - - - - 0		col5: 0x01
	 row6: 0 - - 0 0 - - 0		col6: 0x03
	 row7: 0 - - 0 0 - - 0		col7: 0x00
	*/
    matrix_led_buffer[0]=0x00;
    matrix_led_buffer[1]=0x03;
    matrix_led_buffer[2]=0x01;
    matrix_led_buffer[3]=0xcc;
    matrix_led_buffer[4]=0xcc;
    matrix_led_buffer[5]=0x01;
    matrix_led_buffer[6]=0x03;
    matrix_led_buffer[7]=0x00;

    //disable all columns
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
    HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
    HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
    HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
    HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
    HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
    HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
    HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);

    //disable all rows
    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);

    while (1)
{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    	//timer2: 1 sec
    	if(timer2_flag==1){
    		setTimer2(100);
    		HAL_GPIO_TogglePin(BOT_GPIO_Port, BOT_Pin);
    	}

    	//timer3: 1 sec
    	if(timer3_flag==1){
    		setTimer3(100);
    		if(sec<60){
				sec+=1;
			}

			if(sec>=60){
				sec = 0;
				min+=1;
			}
			if(min>=60){
				min = 0;
				hour+=1;
			}
			if(hour >= 24){
				hour = 0;
			}
			updateClockBuffer();
    	}

    	//timer4: 0.05s
    	if(timer4_flag==1){
    		setTimer4(3);
    		updateLEDMatrix(led_matrix_index++);
    	}

    	//timer5: 0.4s
    	if(timer5_flag==1){
			setTimer5(3*8);
			shiftLeft();
		}

    	//timer1: 0.25 sec
    	if(timer1_flag==1){
    		setTimer1(25);
    		update7SEG(led_index++);
    	}

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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|BOT_Pin|PIN_A5_Pin
                          |PIN_A6_Pin|PIN_A7_Pin|PIN_A8_Pin|PIN_A9_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, PIN_B0_Pin|PIN_B1_Pin|PIN_B2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|PIN_B3_Pin|PIN_B4_Pin|PIN_B5_Pin
                          |PIN_B6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin BOT_Pin PIN_A5_Pin
                           PIN_A6_Pin PIN_A7_Pin PIN_A8_Pin PIN_A9_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|BOT_Pin|PIN_A5_Pin
                          |PIN_A6_Pin|PIN_A7_Pin|PIN_A8_Pin|PIN_A9_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PIN_B0_Pin PIN_B1_Pin PIN_B2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin PIN_B3_Pin PIN_B4_Pin PIN_B5_Pin
                           PIN_B6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = PIN_B0_Pin|PIN_B1_Pin|PIN_B2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|PIN_B3_Pin|PIN_B4_Pin|PIN_B5_Pin
                          |PIN_B6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	// run all timers
	TimeRun();
}


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
