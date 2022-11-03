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

void setRed(int index);
void setGreen(int index);
void setYellow(int index);

void toggleRed(int index);
void toggleGreen(int index);
void toggleYellow(int index);

void clearAllLights(int index);

void displayNum1(int num);
void displayNum2(int num);

void setLED(int index, int num);
void clearAllLED(int index);

void calTime();

void blinkRed();
void blinkGreen();
void blinkYellow();

#endif /* INC_LED_H_ */
