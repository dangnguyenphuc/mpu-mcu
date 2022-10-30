/*
 * fsm_automatic_2.c
 *
 *  Created on: Oct 29, 2022
 *      Author: phucd
 */

#include "fsm_automatic_2.h"

void fsm_automatic_run_2(){

	switch(status_2){

		case INIT:
			clearAllLights(1);
			status_2 = NORMAL_GREEN_2;
			setTimer2(green_time*100);
			time_2 = green_time;
			break;

		case NORMAL_RED_2:
			calTime();
			setRed(1);
			setLED(1, time_2);
			if(timer2_flag == 1){
				status_2 = NORMAL_GREEN_2;
				setTimer2(green_time*100);
				time_2 = green_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_GREEN_2:
			calTime();
			setGreen(1);
			setLED(1, time_2);
			if(timer2_flag == 1){
				status_2 = NORMAL_YELLOW_2;
				setTimer2(yellow_time*100);
				time_2 = yellow_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_YELLOW_2:
			calTime();
			setYellow(1);
			setLED(1, time_2);

			if(timer2_flag == 1){
				status_2 = NORMAL_RED_2;
				setTimer2(red_time*100);
				time_2 = red_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		default:
			break;
	}
}
