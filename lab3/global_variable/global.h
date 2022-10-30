/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: phucd
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "led.h"

extern int status_1;
extern int status_2;
extern int status_3;

extern int time_1;
extern int time_2;

extern int red_time;
extern int green_time;
extern int yellow_time;

#define INIT 			1

#define NORMAL_RED 		2
#define NORMAL_GREEN 	3
#define NORMAL_YELLOW 	4

#define SET_RED 		42
#define SET_YELLOW 		43
#define SET_GREEN 		44

#define MAN_RED 		12
#define MAN_GREEN 		13
#define MAN_YELLOW 		14

#define NORMAL_RED_2 	22
#define NORMAL_GREEN_2 	23
#define NORMAL_YELLOW_2 25

#define MAN_RED_2 		32
#define MAN_GREEN_2 	33
#define MAN_YELLOW_2 	34

#define LED_BLINK 		0.5



#endif /* INC_GLOBAL_H_ */
