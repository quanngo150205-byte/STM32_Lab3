/*
 * global.h
 *
 *  Created on: Oct 28, 2025
 *      Author: ngoqu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 1
#define MANUAL 2
#define CONFIG 3

typedef enum {
		RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED
}traffic_state;


#include "software_timer.h"
#include "button.h"

extern int status;

#endif /* INC_GLOBAL_H_ */
