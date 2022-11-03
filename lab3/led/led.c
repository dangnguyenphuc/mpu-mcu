/*
 * led.c
 *
 *  Created on: Oct 28, 2022
 *      Author: phucd
 */


#include "led.h"

void setRed(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	default:
		break;
	}
}

void setGreen(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		default:
			break;
		}
}

void setYellow(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			break;
		default:
			break;
		}
}

void toggleRed(int index){
	switch(index){
	case 0:
		HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	default:
		break;
	}
}

void toggleGreen(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		break;
	default:
		break;
	}
}

void toggleYellow(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
		break;
	case 1:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
		break;
	default:
		break;
	}
}

void clearAllLights(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	default:
		break;
	}
}

void displayNum1(int num){
	switch(num%10){
	case 0:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, RESET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, SET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, SET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, SET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, SET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, RESET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, SET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, SET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, SET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, SET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, SET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, SET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, RESET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, SET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, SET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, RESET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, RESET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, RESET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, RESET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, RESET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, RESET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin(B0_GPIO_Port,B0_Pin, SET);
		HAL_GPIO_WritePin(B1_GPIO_Port,B1_Pin, SET);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin, SET);
		HAL_GPIO_WritePin(B3_GPIO_Port,B3_Pin, SET);
		HAL_GPIO_WritePin(B4_GPIO_Port,B4_Pin, SET);
		HAL_GPIO_WritePin(B5_GPIO_Port,B5_Pin, SET);
		HAL_GPIO_WritePin(B6_GPIO_Port,B6_Pin, SET);
		break;
	}
}

void displayNum2(int num){
	switch(num){
	case 0:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, RESET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, SET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, SET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, SET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, SET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, RESET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, SET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, SET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, SET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, SET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, SET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, SET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, RESET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, SET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, SET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, RESET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, RESET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, RESET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, RESET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, RESET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, RESET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, RESET);
			break;
		default:
			HAL_GPIO_WritePin(B7_GPIO_Port,B7_Pin, SET);
			HAL_GPIO_WritePin(B8_GPIO_Port,B8_Pin, SET);
			HAL_GPIO_WritePin(B9_GPIO_Port,B9_Pin, SET);
			HAL_GPIO_WritePin(B10_GPIO_Port,B10_Pin, SET);
			HAL_GPIO_WritePin(B11_GPIO_Port,B11_Pin, SET);
			HAL_GPIO_WritePin(B12_GPIO_Port,B12_Pin, SET);
			HAL_GPIO_WritePin(B13_GPIO_Port,B13_Pin, SET);
			break;
		}
}

void setLED(int index, int num){
	switch(index){
	case 0:
		displayNum1(num);
		break;
	case 1:
		displayNum2(num);
		break;
	default:
		break;
	}
}

void clearAllLED(int index){
	setLED(index,10);
}

void calTime(){
	if(timer3_flag == 1){
		setTimer3(100);
		time_1 -= 1;
		time_2 -= 1;
	}
}

void blinkRed(){
	if(timer4_flag == 1){
		setTimer4(LED_BLINK*100);
		toggleRed(0);
		toggleRed(1);
	}
}

void blinkGreen(){
	if(timer4_flag == 1){
		setTimer4(LED_BLINK*100);
		toggleGreen(0);
		toggleGreen(1);
	}
}

void blinkYellow(){
	if(timer4_flag == 1){
		setTimer4(LED_BLINK*100);
		toggleYellow(0);
		toggleYellow(1);
	}
}
