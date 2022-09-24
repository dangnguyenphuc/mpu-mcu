/*
 * software_timer.c
 *
 *  Created on: Sep 24, 2022
 *      Author: phucd
 */
#include "software_timer.h"

int timer1_flag = 0;
int timer1_counter = 0;

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag =0;
}

void TimeRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter<=0){
			timer1_flag = 1;
		}
	}
}




