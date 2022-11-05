/*
 * fsm_simple_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phucd
 */


#include "fsm_simple_button.h"

void fsm_simple_button_run(){

	switch(status){

			case RESET_STATE:
				// TODO

				//display counter;
				displayNum(counter);


				// Switch State

				// if just clicking
					// If 1st button pressed then increasing
				if( is_button_pressed(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;

				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
				if( is_button_pressed(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// hold pressing
					// If 1st button pressed then increasing
				if( is_button_pressed_3s(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;

				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed_3s(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
				if( is_button_pressed_3s(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// timer5 expired:
				if(timer5_flag == 1){
					status = AUTO_STATE;
					setTimer1(100);
				}


				break;

			case INCREASE:
				// TODO
				//display counter;
				displayNum(counter);


				// Switch State

				// just clicking
					// If 1st button pressed then increasing
				if( is_button_pressed(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;
				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
					// If 3rd button pressed then reset
				if( is_button_pressed(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// hold pressing
					// If 1st button pressed then increasing
				if( is_button_pressed_3s(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;

				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed_3s(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
				if( is_button_pressed_3s(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// timer5 expired:
				if(timer5_flag == 1){
					status = AUTO_STATE;
					setTimer1(100);
				}


				break;

			case DECREASE:
				// TODO
				//display counter;
				displayNum(counter);


				// Switch State

				// just clicking
					// If 1st button pressed then increasing
				if( is_button_pressed(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;
				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
					// If 3rd button pressed then reset
				if( is_button_pressed(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// hold pressing
					// If 1st button pressed then increasing
				if( is_button_pressed_3s(0) ){
					counter += 1;
					check_counter();

					status = INCREASE;

				}
					// If 2nd button pressed then decreasing
				if( is_button_pressed_3s(1) ){
					counter -= 1;
					check_counter();

					status = DECREASE;
				}
				if( is_button_pressed_3s(2) ){
					counter = 0;

					status = RESET_STATE;
				}

				// timer5 expired:
				if(timer5_flag == 1){
					status = AUTO_STATE;
					setTimer1(100);
				}


				break;

			default:
				break;
		}

}
