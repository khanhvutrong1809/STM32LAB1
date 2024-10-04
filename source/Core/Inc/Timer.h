/*
 * Timer.h
 *
 *  Created on: Sep 29, 2024
 *      Author: GIGABYTE
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#define MAX_TIMER	4

extern int TIMER_CYCLE;

extern int Timer_Counter[MAX_TIMER];
extern int Timer_Flag[MAX_TIMER];

void setTimer(int index, int duration);

void runTimer(void);



#endif /* INC_TIMER_H_ */
