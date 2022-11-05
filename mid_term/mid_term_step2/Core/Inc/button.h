/*
 * button.h
 *
 *  Created on: Sep 24, 2022
 *      Author: phucd
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

void getKeyInput();
unsigned char is_button_pressed(unsigned char button_number);
unsigned char is_button_pressed_1s(unsigned char button_number);
unsigned char is_button_pressed_3s(unsigned char button_number);
unsigned char is_button_double_click(unsigned char button_number);

void check_counter();

#endif /* INC_BUTTON_H_ */
