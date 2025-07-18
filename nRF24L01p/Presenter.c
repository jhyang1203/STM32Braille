/*
 * Presenter.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Presenter.h"
#include <stdio.h>

void Presenter_Init()
{
	Presenter_TimeWatchInit();
	Presenter_StopWatchInit();
	Motor_Init(&htim5, TIM_CHANNEL_1);
	Motor_Start();
	Motor_SetAngle(0);
}

void Presenter_Excute()
{
	static eModeState_t prevState;
	eModeState_t state = Model_GetModeState();
	if (prevState != state) {
		char str[30];
		prevState = state;

		if (state == S_TIMEWATCH_MODE) {
			sprintf(str, "TimeWatch          ");
			FND_WriteDp(FND_DP_1000|FND_DP_100|FND_DP_10|FND_DP_1, FND_DP_OFF);
		}
		else if (state == S_STOPWATCH_MODE) {
			sprintf(str, "StopWatch: ");
			FND_WriteDp(FND_DP_1000|FND_DP_100|FND_DP_10|FND_DP_1, FND_DP_OFF);
		}
		LCD_writeStringXY(0, 0, str);
	}

	switch (state)
	{
	case S_TIMEWATCH_MODE:
		Presenter_TimeWatchExcute();
		break;
	case S_STOPWATCH_MODE:
		Presenter_StopWatchExcute();
		break;
	}

//	uint8_t rx_data[NRF24L01P_PAYLOAD_LENGTH] = {0};
	uint8_t tx_data[NRF24L01P_PAYLOAD_LENGTH] = {57, 1, 2, 3, 4, 5, 6, 7};

	nrf24l01p_tx_transmit(tx_data);

	//테스트용 ㅜno-ack
//	uint8_t tx_data[NRF24L01P_PAYLOAD_LENGTH] = {0,1,2,3,4,5,6,7};
//	    for(int i = 0; i < NRF24L01P_PAYLOAD_LENGTH; i++)
//	        tx_data[i]++;
//
//	    // 1) UART로 페이로드 덤프
//	    char buf[64];
//	    int len = snprintf(buf, sizeof(buf), "TX Payload:");
//	    for(int i = 0; i < NRF24L01P_PAYLOAD_LENGTH; i++)
//	        len += snprintf(buf + len, sizeof(buf) - len, " %02X", tx_data[i]);
//	    len += snprintf(buf + len, sizeof(buf) - len, "\r\n");
//	    HAL_UART_Transmit(&huart2, (uint8_t*)buf, len, HAL_MAX_DELAY);
//
//	    // 2) No-ACK 전송
//	    nrf24l01p_tx_noack(tx_data);
	//테스트용 ㅜno-ack

//	static int flag = 0;
//
//	if (flag == 0) {
//		Motor_SetAngle(90);
//		osDelay(2000);
//		Motor_SetAngle(0);
//		flag = 1;
//		}

}
