/*
 * fsm_menu.c
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#include "fsm_menu.h"

void resetState(){
	trafState = START;
	man_state = MAN_RED;
}

void fsm_menu_run(){
	switch (status){
	case INIT:
		clearAllLed();
		clear7Seg();
		resetState();
		if (isTimerExpired(0)){
			HAL_GPIO_TogglePin(GPIOA, LED_BLINK_Pin);
			setTimer(0, 1000);
		}
		if (isButtonPressed(0)){
			status = AUTO;
			setTimer(0, 1000);
		}
		if (isButtonPressed(1)){
			status = MANUAL;
			setTimer(0, 1000);
		}
		if (isButtonPressed(2)){
			status = CONFIG;
			setTimer(0, 1000);
		}
		break;
	case AUTO:
		fsm_automatic_run();
		if (isTimerExpired(0)){
			HAL_GPIO_TogglePin(GPIOA, LED_BLINK_Pin);
			setTimer(0, 1000);
		}
		if (isButtonPressed(0)){
			status = MANUAL;
		}
		break;
	case MANUAL:
		fsm_manual_run();
		if (isTimerExpired(0)){
			HAL_GPIO_TogglePin(GPIOA, LED_BLINK_Pin);
			setTimer(0, 1000);
		}
		if (isButtonPressed(0)){
			status = CONFIG;
		}
		break;
	case CONFIG:
		fsm_config_run();
		if (isTimerExpired(0)){
			HAL_GPIO_TogglePin(GPIOA, LED_BLINK_Pin);
			setTimer(0, 1000);
		}
		if (isButtonPressed(0)){
			status = INIT;
		}
		break;
	default:
		break;
	}
}
