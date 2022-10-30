/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: phucd
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status_3){
		case INIT:
			clearAllLights(0);
			clearAllLights(1);
			status_3 = SET_RED;
			setTimer4( LED_BLINK*100 );
		case SET_RED:
			// TODO:
			blinkRed();

			if(is_button_pressed(1)==1){
				red_time = red_time + 1;
				if(red_time>99) red_time = 1;
			}

			displayNum1(red_time);

			displayNum2(status_3-SET_RED+2);


			//CHANGE STATE

			if(is_button_pressed(0)==1){
				status_3 = SET_YELLOW;
				setTimer4( LED_BLINK*100);
			}

			if(is_button_pressed(2)==1){
				status_1 = INIT;
				status_2 = INIT;
				status_3 = -1;
			}

			break;

		case SET_YELLOW:
			blinkYellow();
			displayNum1(yellow_time);
			displayNum2(status_3-SET_RED+2);

			if(is_button_pressed(1)==1){
				yellow_time = yellow_time + 1;
				if(yellow_time>99) yellow_time = 1;
			}


			// CHANGE STATE

			if(is_button_pressed(0)==1){
				status_3 = SET_GREEN;
				setTimer4( LED_BLINK*100);
			}

			if(is_button_pressed(2)==1){
				status_1 = INIT;
				status_2 = INIT;
				status_3 = -1;
			}

			break;

		case SET_GREEN:
			blinkGreen();
			displayNum1(green_time);
			displayNum2(status_3-SET_RED+2);

			if(is_button_pressed(1)==1){
				green_time+=1;
				if(green_time>99) green_time = 1;
			}


			// CHANGE STATE

			if(is_button_pressed(0)==1){
				status_1 = INIT;
				status_2 = INIT;
				status_3 = -1;
			}

			if(is_button_pressed(2)==1){
				status_1 = INIT;
				status_2 = INIT;
				status_3 = -1;
			}

			break;

		default:
			break;
	}
}
