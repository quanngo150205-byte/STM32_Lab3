/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2025
 *      Author: ngoqu
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch (trafState){
	case START:
		setTimer(0, 250);
		if (isTimerExpired(0)){
			HAL_GPIO_TogglePin(GPIOA, LED_R_A_Pin|LED_R_B_Pin|LED_R_C_Pin|LED_R_D_Pin);
			setTimer(0, 250);
		}
		if (status == AUTO && isButtonPressed(2)){
			trafState = RED_GREEN;
			setTimer(0, GREEN_TIME);
		}
		break;
	case RED_GREEN:
		YellowToRed1();
		RedToGreen2();
		if (isTimerExpired(0)){
			trafState = RED_YELLOW;
			setTimer(0, YELLOW_TIME);
		}
		break;
	case RED_YELLOW:
		GreenToYellow2();
		if (isTimerExpired(0)){
			trafState = GREEN_RED;
			setTimer(0, GREEN_TIME);
		}
		break;
	case GREEN_RED:
		RedToGreen1();
		YellowToRed2();
		if (isTimerExpired(0)){
			trafState = YELLOW_RED;
			setTimer(0, YELLOW_TIME);
		}
		break;
	case YELLOW_RED:
		GreenToYellow1();
		if (isTimerExpired(0)){
			trafState = RED_GREEN;
			setTimer(0, GREEN_TIME);
		}
		break;
	default:
		break;
	}
}
