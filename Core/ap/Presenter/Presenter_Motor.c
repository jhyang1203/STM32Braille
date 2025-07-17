/*
 * Presenter_Motor.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */



#include "Presenter_Motor.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "cmsis_os.h"
#include "tim.h"
#include "Motor.h"
//#include "Model_Braille.h"

extern osMailQId brailleCharMailBox;

void Presenter_MotorInit()
{
	Motor_Init(&htim5, TIM_CHANNEL_1);
	Motor_Init(&htim5, TIM_CHANNEL_2);
	Motor_Init(&htim3, TIM_CHANNEL_1);
	Motor_Init(&htim3, TIM_CHANNEL_2);
	Motor_Init(&htim3, TIM_CHANNEL_3);
	Motor_Init(&htim3, TIM_CHANNEL_4);

}

void Presenter_MotorExcute()
{
	osEvent evt = osMailGet(brailleCharMailBox, 0);
	if (evt.status == osEventMail) {
		BrailleChar_t *p = evt.value.p;
		uint8_t bits6 = p->pattern;
		//char alphabet   = p->alphabet;  // 나중에 LCD용

		Motor_DisplayBits(bits6);
		//Motor_DisplayBraille(alphabet);  // 나중에 LCD용
		osMailFree(brailleCharMailBox, p);

	}
}
