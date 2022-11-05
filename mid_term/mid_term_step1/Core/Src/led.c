/*
 * led.c
 *
 *  Created on: Oct 28, 2022
 *      Author: phucd
 */


#include "led.h"


void toggleRed(){
	HAL_GPIO_TogglePin(A5_GPIO_Port, A5_Pin);
}

void displayNum(int num){
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

void clearLED(){
	displayNum(10);
}


