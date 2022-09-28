/*
 * software_timer.h
 *
 *  Created on: Sep 24, 2022
 *      Author: phucd
 */

#ifndef __SOFTWARE_TIMER_
#define __SOFTWARE_TIMER_

/*Timer 1*/
extern int timer1_flag ;
void setTimer1(int duration);


/*Timer 2*/
extern int timer2_flag ;
void setTimer2(int duration);

/*Timer 3*/
extern int timer3_flag ;
void setTimer3(int duration);

/*Timer 4*/
extern int timer4_flag ;
void setTimer4(int duration);

//Count down for all timers
void TimeRun();



#endif /* __SOFTWARE_TIMER_ */
