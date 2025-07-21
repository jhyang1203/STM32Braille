/*
 * Listener_Switch.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "Listener_Switch.h"


typedef struct {
	GPIO_TypeDef *GPIOx;
	uint32_t pinNum;
}Switch_TypeDef;

Switch_TypeDef Switch[6] = {
		{GPIOC, GPIO_PIN_8}, 	// switch 1
		{GPIOC, GPIO_PIN_6}, 	// switch 2
		{GPIOC, GPIO_PIN_5},  	// switch 3
		{GPIOA, GPIO_PIN_12},  	// switch 4
		{GPIOA, GPIO_PIN_11}, 	// switch 5
		{GPIOB, GPIO_PIN_12}, 	// switch 6
};

void Listener_Switch_RxExecute()
{


}

void Listener_Switch_TxExecute()
{
    uint8_t pattern = GetBraillePattern();
    osMessagePut(RFTx_brailleMsgBox, pattern, 0);  // pattern 값을 메시지로 전송
}

uint8_t GetBraillePattern()
{
	uint8_t pattern = 0;

	if (HAL_GPIO_ReadPin(Switch[0].GPIOx, Switch[0].pinNum) == GPIO_PIN_SET) pattern |= (1 << 0);  // ●1 ← Switch 1
	if (HAL_GPIO_ReadPin(Switch[1].GPIOx, Switch[1].pinNum) == GPIO_PIN_SET) pattern |= (1 << 1);  // ●2 ← Switch 2
	if (HAL_GPIO_ReadPin(Switch[2].GPIOx, Switch[2].pinNum) == GPIO_PIN_SET) pattern |= (1 << 2);  // ●3 ← Switch 3
	if (HAL_GPIO_ReadPin(Switch[3].GPIOx, Switch[3].pinNum) == GPIO_PIN_SET) pattern |= (1 << 3); // ●4 ← Switch 4
	if (HAL_GPIO_ReadPin(Switch[4].GPIOx, Switch[4].pinNum) == GPIO_PIN_SET) pattern |= (1 << 4); // ●5 ← Switch 5
	if (HAL_GPIO_ReadPin(Switch[5].GPIOx, Switch[5].pinNum) == GPIO_PIN_SET) pattern |= (1 << 5); // ●6 ← Switch 6

	return pattern;
}


