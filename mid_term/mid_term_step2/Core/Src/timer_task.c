/*
 * timer_task.c
 *
 *  Created on: Nov 5, 2022
 *      Author: phucd
 */

#include "timer_task.h"

void blinkLED(){
	if(timer3_flag == 1){
		setTimer3(100);

		// TODO:
			//Blink LED:
		toggleRed();
	}
}

void count_down(){
	if(timer1_flag == 1){
		setTimer1(100);

		// TODO:
		counter -= 1;
		check_counter();
	}
}
