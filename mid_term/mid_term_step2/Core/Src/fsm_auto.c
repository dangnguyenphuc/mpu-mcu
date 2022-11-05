/*
 * fsm_auto.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phucd
 */

#include "fsm_auto.h"
#include "timer_task.h"

void fsm_auto_run(){
	switch(status){

			case INIT:
				// TODO

				clearLED();
				counter = 0;
				setTimer1(100);

				// Switch State
				status = AUTO_STATE;

				break;

			case AUTO_STATE:
				// TODO

				//display counter;
				displayNum(counter);
				// count counter;
				count_down();



				// Switch State

				// just clicking
					// If 1st button pressed then increasing
				if( is_button_pressed(0) ){
					counter += 1;
					check_counter();
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = INCREASE;
				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed(1) ){
					counter -= 1;
					check_counter();
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = DECREASE;
				}
					// If 3rd button pressed then reset
				if( is_button_pressed(2) ){
					counter = 0;
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = RESET_STATE;
				}

				// hold pressing
					// If 1st button pressed then increasing
				if( is_button_pressed_3s(0) ){
					counter += 1;
					check_counter();
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = INCREASE;

				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed_3s(1) ){
					counter -= 1;
					check_counter();
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = DECREASE;
				}
				if( is_button_pressed_3s(2) ){
					counter = 0;
					setTimer5(EXPIRED_BUTTON_DURAION);

					status = RESET_STATE;
				}

				break;

			default:
				break;
		}
}
