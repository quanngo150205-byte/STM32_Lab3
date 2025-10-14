/*
 * software_timer.c
 *
 *  Created on: Sep 28, 2025
 *      Author: ngoqu
 */

#include "software_timer.h"

const int TIMER_SIZE = 1;
int timer_counter[1] = {0};
int timer_flag[1] = {0};
int TIMER_CYCLE = 10;

void setTimers(int duration){
	for(int i = 0; i < TIMER_SIZE; ++i){
		timer_counter[i] = duration / TIMER_CYCLE;
		timer_flag[i] = 0;
	}
}

void setTimer(int index, int duration){
	switch (index){
	case 0:
		timer_counter[0] = duration / TIMER_CYCLE;
		timer_flag[0] = 0;
	default :
		break;
	}
}

void timer_run(){
	for (int i = 0; i < TIMER_SIZE; ++i){
	    if (timer_counter[i] > 0) {
	        timer_counter[i]--;
	        if (timer_counter[i] <= 0) {
	            timer_flag[i] = 1;
	        }
	    }
	}
}
