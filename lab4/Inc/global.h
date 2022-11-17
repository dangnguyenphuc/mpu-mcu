/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: phucd
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "led.h"

extern int status;

extern int counter;

#define INIT 				1

#define AUTO_COUNT			2

#define RESET_STATE	 		11
#define INCREASE 			12
#define DECREASE 			13

#define AUTO_STATE				30

#define SETTING 				50

#define DURATION_FOR_DOUBLE_CLICK 			100
#define EXPIRED_BUTTON_DURATION				1000

void add_counter();



#endif /* INC_GLOBAL_H_ */
