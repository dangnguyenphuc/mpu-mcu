/*
 * led.h
 *
 *  Created on: Oct 28, 2022
 *      Author: phucd
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"
#include "global.h"


void toggleRed();
void toggleGreen();
void toggleYellow();
void clearLight();

void displayNum();
void clearLED();

void toggleWhenPressed();

void toggleOneShot();

#endif /* INC_LED_H_ */
