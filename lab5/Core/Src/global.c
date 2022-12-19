/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: phucd
 */

#include "global.h"


 int status_cmd = WAIT_HEADER;
 int status_UART = WAIT_CMD_RST;
 uint8_t index_buffer = 0;
 uint8_t buffer_flag = 0;
 char cmd_flag = 0;
 uint8_t ADC_value = 0;

uint8_t buffer_rx[MAX_SIZE_FOR_UART] = {0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0};

uint8_t buffer_tx[MAX_SIZE_FOR_UART] = {0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0};

uint8_t cmd_data[MAX_SIZE_FOR_UART] = {	0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0};



