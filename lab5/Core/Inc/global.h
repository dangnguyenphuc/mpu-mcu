/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: phucd
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "led.h"
#include "stdio.h"
#include "stdlib.h"
#include "fsm_command_parser.h"
#include "fsm_uart_communication.h"
#include "software_timer.h"

#define WAIT_HEADER		10
#define RECEIVING		11

#define WAIT_CMD_RST	20
#define SENDING_UART	21

// UART communiation
#define MAX_SIZE_FOR_UART	30
extern uint8_t buffer_rx[MAX_SIZE_FOR_UART];
extern uint8_t buffer_tx[MAX_SIZE_FOR_UART];
extern uint8_t cmd_data[MAX_SIZE_FOR_UART];


extern int status_cmd;
extern int status_UART;
extern uint8_t index_buffer;
extern uint8_t buffer_flag ;

extern uint8_t character;
extern uint8_t ADC_value;

extern char cmd_flag;

#endif /* INC_GLOBAL_H_ */
