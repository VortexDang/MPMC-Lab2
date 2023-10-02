/*
 * software_timer.h
 *
 *  Created on: Oct 1, 2023
 *      Author: Ben Tran
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
void setTimer1(int );
void timer1Run();

extern int timer2_flag;
void setTimer2(int );
void timer2Run();

extern int timer3_flag;
void setTimer3(int );
void timer3Run();

extern int timer4_flag;
void setTimer4(int );
void timer4Run();
#endif /* INC_SOFTWARE_TIMER_H_ */
