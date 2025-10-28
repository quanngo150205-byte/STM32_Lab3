/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2025
 *      Author: ngoqu
 */

#include "traffic_light.h"


/* Ham chuyen den duong 1*/
void YellowToRed1(){
	HAL_GPIO_WritePin(GPIOA, LED_R_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_R_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_C_Pin, GPIO_PIN_SET);
}
void RedToGreen1(){
	HAL_GPIO_WritePin(GPIOA, LED_R_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_G_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_R_C_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_G_C_Pin, GPIO_PIN_RESET);
}
void GreenToYellow1(){
	HAL_GPIO_WritePin(GPIOA, LED_G_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_G_C_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_C_Pin, GPIO_PIN_RESET);
}

/* Ham chuyen den duong 2*/
void YellowToRed2(){
	HAL_GPIO_WritePin(GPIOA, LED_R_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_R_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_D_Pin, GPIO_PIN_SET);
}
void RedToGreen2(){
	HAL_GPIO_WritePin(GPIOA, LED_R_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_G_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_R_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_G_D_Pin, GPIO_PIN_RESET);
}
void GreenToYellow2(){
	HAL_GPIO_WritePin(GPIOA, LED_G_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_G_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_Y_D_Pin, GPIO_PIN_RESET);
}

//ham hien led 7 doan
void displayDigit(int num) {
    switch (num) {
        case 0: // ABCDEF sáng, G tắt
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
        case 1: // BC sáng
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
        case 2: // ABDEG sáng
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 3: // ABCDG sáng
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 4: // BCFG sáng
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        default: // tắt hết
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
    }
}

void clearAllLed(){
	HAL_GPIO_WritePin(LED_R_A_GPIO_Port,   LED_R_A_Pin,     GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_Y_A_GPIO_Port,   LED_Y_A_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_A_GPIO_Port,   LED_G_A_Pin,   GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_R_B_GPIO_Port,   LED_R_B_Pin,     GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_Y_B_GPIO_Port,   LED_Y_B_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_B_GPIO_Port,   LED_G_B_Pin,   GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_R_C_GPIO_Port,   LED_R_C_Pin,     GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_Y_C_GPIO_Port,   LED_Y_C_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_C_GPIO_Port,   LED_G_C_Pin,   GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_R_D_GPIO_Port,   LED_R_D_Pin,     GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_Y_D_GPIO_Port,   LED_Y_D_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_D_GPIO_Port,   LED_G_D_Pin,   GPIO_PIN_SET);
}
