/*
 * fsm_manual.h
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#define MAN_RED  		11
#define MAN_YELLOW		12
#define MAN_GREEN		13
#define MAN_RUN			14

//timer(0) blink led PA5
//timer(1) dem thoi gian countdown duong 1
//timer(2) dem thoi gian countdown duong 2
//timer(3) blink led red state START trong AUTO
//timer(4) dieu khien quet led 7 doan
//timer(5) dieu khien update time_buffer

#include "global.h"
#include "7seg.h"
#include "traffic_light.h"

int red_time;
int yellow_time;
int green_time;
int man_state;

void fsm_manual_run();

#endif /* INC_FSM_MANUAL_H_ */
