/*
 * fsm_automatic.c
 *
 *  Created on: Sep 30, 2022
 *      Author: phucd
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status_1){

		case INIT:
			clearAllLights(0);
			status_1 = NORMAL_RED;
			setTimer1(red_time*100);
			time_1 = red_time;
			break;

		case NORMAL_RED:
			calTime();
			setRed(0);
			setLED(0, time_1);
			if(timer1_flag == 1){
				status_1 = NORMAL_GREEN;
				setTimer1(green_time*100);
				time_1 = green_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_GREEN:
			calTime();
			setGreen(0);
			setLED(0, time_1);
			if(timer1_flag == 1){
				status_1 = NORMAL_YELLOW;
				setTimer1(yellow_time*100);
				time_1 = yellow_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_YELLOW:
			calTime();
			setYellow(0);
			setLED(0, time_1);
			if(timer1_flag == 1){
				status_1 = NORMAL_RED;
				setTimer1(red_time*100);
				time_1 = red_time;
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
