/*
 * fsm_menu.c
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#include "fsm_menu.h"

void fsm_menu_run(){
	switch (status){
	case INIT:
		clearAllLed();
		displayDigit(10);
		if (isButtonPressed(0)){
			status = AUTO;
		}
		if (isButtonPressed(1)){
			status = MANUAL;
		}
		if (isButtonPressed(2)){
			status = CONFIG;
		}
		break;
	case AUTO:
		fsm_automatic_run();
		if (isButtonPressed(0)){
			status = MANUAL;
		}
		break;
	case MANUAL:
		fsm_manual_run();
		if (isButtonPressed(0)){
			status = CONFIG;
		}
		break;
	case CONFIG:
		fsm_config_run();
		if (isButtonPressed(0)){
			status = INIT;
		}
		break;
	default:
		break;
	}
}
