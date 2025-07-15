/*
 * buzzer.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */
#include "Motor.h"

TIM_HandleTypeDef *hmotorTim;
uint32_t motorTimChannel;

#define arr 	2000-1

void Motor_Init(TIM_HandleTypeDef *htim, uint32_t channel)
{
	hmotorTim = htim;
	motorTimChannel = channel;
}

void Motor_SetAngle(uint32_t degree)
{
    if (degree > 180) degree = 180;

    float pulse_ms = 1.0f + ((float)degree / 90.0f);  // 0도=1.0ms, 90도=2.0ms, 180도=3.0ms
    uint32_t ccr = (uint32_t)(pulse_ms * 100.0f);

    __HAL_TIM_SET_AUTORELOAD(&htim1, arr);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ccr);
}

void Motor_Start()
{
	HAL_TIM_PWM_Start(hmotorTim, motorTimChannel);
}

void Motor_Stop()
{
	HAL_TIM_PWM_Stop(hmotorTim, motorTimChannel);
}
