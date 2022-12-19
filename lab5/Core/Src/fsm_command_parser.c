/*
 * fsm_command_parser.c
 *
 *  Created on: Dec 19, 2022
 *      Author: phucd
 */

#include "fsm_command_parser.h"

int len = 0;

void cmd_parser(){
	switch(status_cmd){

		case WAIT_HEADER:
			if(character == "!"){
				status_cmd = RECEIVING;
				len = 0;
			}
			break;

		case RECEIVING:
			if(character!= "#"){
				cmd_data[len++] = character;
			}

			if(character == "!"){
				len = 0;
			}

			if(character == "#"){
				status_cmd = WAIT_HEADER;
				cmd_flag = 1;
			}
			break;

		default:
			break;
	}
}
