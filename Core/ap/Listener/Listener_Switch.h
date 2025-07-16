/*
 * Listener_Switch.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_LISTENER_LISTENER_SWITCH_H_
#define AP_LISTENER_LISTENER_SWITCH_H_

#include "stm32f4xx_hal.h"     // GPIO_TypeDef, HAL_XXX, GPIO_PIN_XXX
#include "cmsis_os.h"         // osMessageQId, osMessagePut
#include <stdint.h>           // uint8_t, uint32_t

extern UART_HandleTypeDef huart2;


extern osMessageQId brailleMsgBox;

void Listener_SwitchStop();
void Listener_SwitchExecute();
uint8_t GetBraillePattern();


#endif /* AP_LISTENER_LISTENER_SWITCH_H_ */
