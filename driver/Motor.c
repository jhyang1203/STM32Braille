/*
 * Motor.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */
#include "Motor.h"

TIM_HandleTypeDef *hmotorTim;
uint32_t motorTimChannel;

#define arr 	2000-1

// dot 번호
// 1 2
// 3 4
// 5 6

static const uint8_t brailleMap[26][6] = {
		{1,0,0,0,0,0}, // A
		{1,0,1,0,0,0}, // B
		{1,1,0,0,0,0}, // C
		{1,1,0,1,0,0}, // D
		{1,0,0,1,0,0}, // E
		{1,1,1,0,0,0}, // F
		{1,1,1,1,0,0}, // G
		{1,0,1,1,0,0}, // H
		{0,1,1,0,0,0}, // I
		{0,1,1,1,0,0}, // J
		{1,0,0,0,1,0}, // K
		{1,0,1,0,1,0}, // L
		{1,1,0,0,1,0}, // M
		{1,1,0,1,1,0}, // N
		{1,0,0,1,1,0}, // O
		{1,1,1,0,1,0}, // P
		{1,1,1,1,1,0}, // Q
		{1,0,1,1,1,0}, // R
		{0,1,1,0,1,0}, // S
		{0,1,1,1,1,0}, // T
		{1,0,0,0,1,1}, // U
		{1,0,1,0,1,1}, // V
		{0,1,1,1,0,1}, // W
		{1,1,0,0,1,1}, // X
		{1,1,0,1,1,1}, // Y
		{1,0,0,1,1,1}  // Z
};

static TIM_HandleTypeDef* motorTim[6] = {
		&htim5, &htim3, &htim5, &htim3, &htim3, &htim3
};

static uint32_t motorCh[6] = {
		TIM_CHANNEL_1, TIM_CHANNEL_1, TIM_CHANNEL_2,
		TIM_CHANNEL_2, TIM_CHANNEL_3, TIM_CHANNEL_4
};

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

	//	__HAL_TIM_SET_AUTORELOAD(&htim5, arr);
	//	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, ccr);
	__HAL_TIM_SET_AUTORELOAD(hmotorTim, arr);
	__HAL_TIM_SET_COMPARE(hmotorTim, motorTimChannel, ccr);
}

void Motor_Start()
{
	HAL_TIM_PWM_Start(hmotorTim, motorTimChannel);
}

void Motor_Stop()
{
	HAL_TIM_PWM_Stop(hmotorTim, motorTimChannel);
}

void Motor_DisplayBits(uint8_t bits6)
{

	for (uint8_t dot = 0; dot < 6; dot++) {
		Motor_Init(motorTim[dot], motorCh[dot]);
		if (bits6 & (1 << (5 - dot))) {
			Motor_SetAngle(90);
		} else {
			Motor_SetAngle(0);
		}
		Motor_Start();
	}

}

void Motor_DisplayBraille(char data)
{
	if (data < 'A' || data > 'Z') return;
	uint8_t idx = data - 'A';

	for (uint8_t dot = 0; dot < 6; dot++) {
		Motor_Init(motorTim[dot], motorCh[dot]);

		if (brailleMap[idx][dot]) {
			Motor_SetAngle(90);
		}
		else {
			Motor_SetAngle(0);
		}
		Motor_Start();
	}
}
