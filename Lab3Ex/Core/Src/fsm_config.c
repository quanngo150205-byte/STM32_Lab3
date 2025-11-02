/*
 * fsm_config.c
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#include "fsm_config.h"

int conf_state = CONF_INIT;
int toggle = 0;
int currEN = 0;

void amberBlink(){
	if (toggle == 0){
		HAL_GPIO_WritePin(GPIOA, LED_Y_A_Pin|LED_Y_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_Y_B_Pin|LED_Y_D_Pin, GPIO_PIN_SET);
		toggle = 1;
	} else {
		HAL_GPIO_WritePin(GPIOA, LED_Y_A_Pin|LED_Y_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_Y_B_Pin|LED_Y_D_Pin, GPIO_PIN_RESET);
		toggle = 0;
	}
}

void display7SegConfigMode(){
	if (currEN == 0){
		displayDigit1(9);
		displayDigit2(9);
		HAL_GPIO_WritePin(GPIOB, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, GPIO_PIN_SET);
		currEN = 1;
	}
	else {
		displayDigit1(9);
		displayDigit2(9);
		HAL_GPIO_WritePin(GPIOB, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, GPIO_PIN_RESET);
		currEN = 0;
	}
}

void confTraffic_run(){
	switch (trafState){
	case START:
		if (isTimerExpired(1)){
			HAL_GPIO_TogglePin(GPIOA, LED_R_A_Pin|LED_R_B_Pin|LED_R_C_Pin|LED_R_D_Pin);
			setTimer(1, 250);
		}
		if (status == CONFIG && isButtonPressed(1)){
			trafState = RED_GREEN;
			setTimer(2, 80);
			setTimer(1, 250);
		}
		break;
	case RED_GREEN:
		YellowToRed1();
		RedToGreen2();
		if (isButtonPressed(1)){
			trafState = RED_GREENBLINK;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	case RED_GREENBLINK:
		if (isTimerExpired(1)){
			HAL_GPIO_TogglePin(GPIOA, LED_G_B_Pin|LED_G_D_Pin);
			setTimer(1, 250);
		}
		if (isButtonPressed(1)){
			trafState = RED_YELLOW;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	case RED_YELLOW:
		GreenToYellow2();
		if (isButtonPressed(1)){
			trafState = GREEN_RED;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	case GREEN_RED:
		YellowToRed2();
		RedToGreen1();
		if (isButtonPressed(1)){
			trafState = GREENBLINK_RED;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	case GREENBLINK_RED:
		if (isTimerExpired(1)){
			HAL_GPIO_TogglePin(GPIOA, LED_G_A_Pin|LED_G_C_Pin);
			setTimer(1, 250);
		}
		if (isButtonPressed(1)){
			trafState = YELLOW_RED;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	case YELLOW_RED:
		GreenToYellow1();
		if (isButtonPressed(1)){
			trafState = RED_GREEN;
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		break;
	default:
		break;
	}
}

void fsm_config_run(){
	switch (conf_state){
	case CONF_INIT:
		if (status == CONFIG && isButtonDoubleClicked(1)){
			conf_state = CONF_AMBER;
			setTimer(1, 250);
			setTimer(2, 80);
		}
		if (status == CONFIG && isButtonDoubleClicked(2)){
			conf_state = CONF_TRAFFIC;
			trafState = START;
		}
		break;
	case CONF_AMBER:
		if (isTimerExpired(1)){
			amberBlink();
			setTimer(1, 250);
		}
		if (isTimerExpired(2)){
			display7SegConfigMode();
			setTimer(2, 80);
		}
		if (isButtonDoubleClicked(2)){
			clearAllLed();
			clear7Seg();
			conf_state = CONF_TRAFFIC;
			trafState = START;
			setTimer(1, 250);
			setTimer(2, 80);
		}
		break;
	case CONF_TRAFFIC:
		confTraffic_run();
		if (isButtonDoubleClicked(1)){
			clear7Seg();
			clearAllLed();
			conf_state = CONF_AMBER;
			setTimer(1, 250);
			setTimer(2, 80);
		}
		break;
	default:
		break;
	}
}
