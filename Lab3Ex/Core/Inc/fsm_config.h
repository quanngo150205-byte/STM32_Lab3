/*
 * fsm_config.h
 *
 *  Created on: Oct 29, 2025
 *      Author: ngoqu
 */

#ifndef INC_FSM_CONFIG_H_
#define INC_FSM_CONFIG_H_

#define CONF_INIT		20
#define CONF_AMBER		21
#define CONF_TRAFFIC	22

//timer(1) de blink amber mode
//timer(2) de quet led 7 doan

#include "global.h"
#include "7seg.h"
#include "traffic_light.h"

void fsm_config_run();

#endif /* INC_FSM_CONFIG_H_ */
