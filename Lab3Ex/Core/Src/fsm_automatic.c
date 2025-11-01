/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2025
 *      Author: ngoqu
 */

#include "fsm_automatic.h"

//timer(0) blink led PA5
//timer(1) dem thoi gian countdown duong 1
//timer(2) dem thoi gian countdown duong 2
//timer(3) blink led red state START trong AUTO
//timer(4) dieu khien quet led 7 doan
//timer(5) dieu khien update time_buffer


void fsm_automatic_run(){
	switch (trafState){
	case START:
		if (isTimerExpired(3)){
			HAL_GPIO_TogglePin(GPIOA, LED_R_A_Pin|LED_R_B_Pin|LED_R_C_Pin|LED_R_D_Pin);
			setTimer(3, 250);
		}
		if (status == AUTO && isButtonPressed(2)){
			trafState = RED_GREEN;
			setTimer(1, GREEN_TIME + YELLOW_TIME);
			setTimer(2, GREEN_TIME);
			setTimer(4, 10);
			setTimer(5, 10);
		}
		break;
	case RED_GREEN:
		YellowToRed1();
		RedToGreen2();
		if (isTimerExpired(5)){
			updateTimerBuffer(getTimerCounter(1), getTimerCounter(2));
			setTimer(5, 500);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if (isTimerExpired(2)){
			trafState = RED_YELLOW;
			setTimer(2, YELLOW_TIME);
		}
		break;
	case RED_YELLOW:
		GreenToYellow2();
		if (isTimerExpired(5)){
			updateTimerBuffer(getTimerCounter(1), getTimerCounter(2));
			setTimer(5, 500);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if (isTimerExpired(1)){
			trafState = GREEN_RED;
			setTimer(1, GREEN_TIME);
			setTimer(2, GREEN_TIME + YELLOW_TIME);
		}
		break;
	case GREEN_RED:
		RedToGreen1();
		YellowToRed2();
		if (isTimerExpired(5)){
			updateTimerBuffer(getTimerCounter(1), getTimerCounter(2));
			setTimer(5, 500);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if (isTimerExpired(1)){
			trafState = YELLOW_RED;
			setTimer(1, YELLOW_TIME);
		}
		break;
	case YELLOW_RED:
		GreenToYellow1();
		if (isTimerExpired(5)){
			updateTimerBuffer(getTimerCounter(1), getTimerCounter(2));
			setTimer(5, 500);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if (isTimerExpired(1)){
			trafState = RED_GREEN;
			setTimer(1, GREEN_TIME + YELLOW_TIME);
			setTimer(2, GREEN_TIME);
		}
		break;
	default:
		break;
	}
}
