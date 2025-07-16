/*
 * Listener.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */


#include "Listener.h"

Button_Handler_t hbtnMode;

uint8_t state = S_BRAILLE_MEASURE;

void Listener_Init()
{
	Button_Init(&hbtnMode, GPIOB, GPIO_PIN_2);
}

void Listener_Execute()
{
	switch(state)
	{
	case S_BRAILLE_STOP:
		Listener_SwitchStop();
		if (Button_GetState(&hbtnMode) == ACT_RELEASED) state = S_BRAILLE_MEASURE;
		break;
	case S_BRAILLE_MEASURE:
		Listener_SwitchExecute();
		state = S_BRAILLE_STOP;
		break;
	}
}
