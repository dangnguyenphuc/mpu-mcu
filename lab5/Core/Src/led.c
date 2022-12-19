/*
 * led.c
 *
 *  Created on: Oct 28, 2022
 *      Author: phucd
 */


#include "led.h"


void toggleRed(){
	HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin,RESET);
	HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin,SET);
	HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin,SET);

}
void toggleGreen(){
	HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin,SET);
	HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin,SET);
	HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin,RESET);
}
void toggleYellow(){
	HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin,SET);
	HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin,RESET);
	HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin,SET);
}

void clearLight(){
	HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin,SET);
	HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin,SET);
	HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin,SET);
}
