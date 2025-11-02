/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#include "fsm_manual.h"

int red_time = 0;
int yellow_time = 0;
int green_time = 0;
int man_state = MAN_RED;

void trafficLight_run(){
	switch (trafState){
		case START:
			if (status == MANUAL){
				trafState = RED_GREEN;
				setTimer(1, red_time * 1000);
				setTimer(2, green_time * 1000);
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
				setTimer(2, yellow_time * 1000);
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
				setTimer(1, green_time * 1000);
				setTimer(2, red_time * 1000);
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
				setTimer(1, yellow_time * 1000);
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
				setTimer(1, red_time * 1000);
				setTimer(2, green_time * 1000);
			}
			break;
		default:
			break;
		}
}

void fsm_manual_run(){
	switch (man_state){
	case MAN_RED:
		if (isTimerExpired(3)){
			HAL_GPIO_TogglePin(GPIOA, LED_R_A_Pin|LED_R_B_Pin|LED_R_C_Pin|LED_R_D_Pin);
			setTimer(3, 250);
		}
		if (isTimerExpired(5)){
			updateTimerBuffer(red_time * 100, (MAN_RED - 10) * 100);
			setTimer(5, 300);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if (isButtonPressed(1) || isButtonLongPressed(1)){
			red_time+=1;
		}
		if (isButtonPressed(2) || isButtonLongPressed(2)){
			red_time-=1;
		}
		if (isButtonDoubleClicked(2)){
			HAL_GPIO_WritePin(GPIOA, LED_R_A_Pin|LED_R_B_Pin|LED_R_C_Pin|LED_R_D_Pin, GPIO_PIN_SET);
			man_state = MAN_YELLOW;
			setTimer(3, 250);
		}
		break;
	case MAN_YELLOW:
		if (isTimerExpired(3)){
			HAL_GPIO_TogglePin(GPIOA, LED_Y_A_Pin|LED_Y_B_Pin|LED_Y_C_Pin|LED_Y_D_Pin);
			setTimer(3, 250);
		}
		if (isTimerExpired(5)){
			updateTimerBuffer(yellow_time * 100, (MAN_YELLOW - 10) * 100);
			setTimer(5, 300);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if ((isButtonPressed(1) || isButtonLongPressed(1)) && yellow_time <= red_time){
			yellow_time+=1;
		}
		if ((isButtonPressed(2) || isButtonLongPressed(2)) && (yellow_time > 0)){
			yellow_time-=1;
		}
		if (isButtonDoubleClicked(2)){
			HAL_GPIO_WritePin(GPIOA, LED_Y_A_Pin|LED_Y_B_Pin|LED_Y_C_Pin|LED_Y_D_Pin, GPIO_PIN_SET);
			man_state = MAN_GREEN;
			setTimer(3, 250);
		}
		break;
	case MAN_GREEN:
		if (isTimerExpired(3)){
			HAL_GPIO_TogglePin(GPIOA, LED_G_A_Pin|LED_G_B_Pin|LED_G_C_Pin|LED_G_D_Pin);
			setTimer(3, 250);
		}
		if (isTimerExpired(5)){
			updateTimerBuffer(green_time * 100, (MAN_GREEN - 10) * 100);
			setTimer(5, 300);
		}
		if (isTimerExpired(4)){
			display7SegLed();
			setTimer(4, 80);
		}
		if ((isButtonPressed(1) || isButtonLongPressed(1)) && (green_time < red_time - yellow_time)){
			green_time+=1;
		}
		if ((isButtonPressed(2) || isButtonLongPressed(2)) && (green_time > 0)){
			green_time-=1;
		}
		if (isButtonDoubleClicked(2)){
			HAL_GPIO_WritePin(GPIOA, LED_G_A_Pin|LED_G_B_Pin|LED_G_C_Pin|LED_G_D_Pin, GPIO_PIN_SET);
			man_state = MAN_RUN;
			trafState = START;
		}
		break;
	case MAN_RUN:
		trafficLight_run();
		break;
	default:
		break;
	}
}
