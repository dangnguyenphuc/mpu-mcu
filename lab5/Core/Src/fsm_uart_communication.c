/*
 * fsm_uart_communication.c
 *
 *  Created on: Dec 19, 2022
 *      Author: phucd
 */
#include "fsm_uart_communication.h"



unsigned char Receiving_RESET(){
	if(cmd_data[0] == "R" && cmd_data[1] == "S" && cmd_data[2] == "T"){
		return 1;
	}
	return 0;
}

unsigned char Receiving_OK(){
	if(cmd_data[0] == "O" && cmd_data[1] == "K"){
		return 1;
	}
	return 0;
}


void uart_communication(){
	switch (status_UART) {
		case WAIT_CMD_RST:
			if(cmd_flag){
				cmd_flag = 0;
				if(Receiving_RESET()){
					status_UART = SENDING_UART;
					setTimer1(3000);
					ADC_value = HAL_ADC_GetValue(&hadc1);
				}
			}
			break;
		case SENDING_UART:
			if(timer1_flag){
				setTimer1(3000);
				HAL_UART_Transmit(&huart2, (void *) buffer_tx, sprintf(buffer_tx, "!ADC=%.4d#", ADC_value), 3000);
			}

			if(cmd_flag){
				cmd_flag = 0;
				if(Receiving_OK()){
					status_UART = WAIT_CMD_RST;
				}
			}

			break;
		default:
			break;
	}
}
