/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2025
 *      Author: ngoqu
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch (status){
	case INIT:
		clearAllLed();
		displayDigit(10);
		if (isButtonPressed(0)){
			status = AUTO;
		}
		break;
	case AUTO:
		switch (trafState){
		case RED_GREEN:
			break;
		case RED_YELLOW:
			break;
		case GREEN_RED:
			break;
		case YELLOW_RED:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
