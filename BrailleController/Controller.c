/*
 * Controller.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Controller.h"


void Controller_CheckEventMode();

void Controller_Init()
{
	WriteBraille_Init();
	Model_SetModeState(S_STOP_MODE);

	// uart 테스트용
//	Switch_t *p = osMailAlloc(BrailleSwitchMailBox, 0);
//	if (p != NULL) {
//		p->bits = 0b100100;  // e
//		osMailPut(BrailleSwitchMailBox, p);

//		char msg[64];
//		sprintf(msg, "Bits: %02X -> %c\r\n", p->bits, ConvertBrailleToAlphabet(p->bits));
//		HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
//	}

//	osEvent evt = osMailGet(BrailleSwitchMailBox, 0);
//	if (evt.status == osEventMail) {
//		Switch_t *recv = (Switch_t *)evt.value.p;
//
//	char msg[64];
//	sprintf(msg, "Bits: %02X -> %c\r\n", recv->bits, ConvertBrailleToAlphabet(recv->bits));
//	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
//
//	osMailFree(BrailleSwitchMailBox, recv);
//	}

}

void Controller_Excute()
{
	eModeState_t state = Model_GetModeState();

	switch (state)
	{
	case S_MOTOR_MODE:
		WriteBraille_Excute();
		Model_SetModeState(S_STOP_MODE);
		break;
	case S_STOP_MODE:
		//WriteBraille_Excute();
		//Model_SetModeState(S_MOTOR_MODE);
		break;
	}

//    char msg[64];
//    sprintf(msg, "Bits: %02X -> %c\r\n", bits, alpha);
//    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

//	char testMsg[] = "UART test\r\n";
//	HAL_UART_Transmit(&huart2, (uint8_t*)testMsg, strlen(testMsg), HAL_MAX_DELAY);

	Controller_CheckEventMode();
}

void Controller_CheckEventMode()
{
	osEvent evt = osMessageGet(modeEventMsgBox, 0);
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		evtState = evt.value.v;
		if (evtState != EVENT_MODE) {
			return;
		}

		eModeState_t state = Model_GetModeState();

		if (state == S_STOP_MODE){
			Model_SetModeState(S_MOTOR_MODE);
		}

	}

}
