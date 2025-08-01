/*
 * RF_Transfer.c
 *
 *  Created on: Jul 17, 2025
 *      Author: kccistc
 */


#include "Presenter_RF_Transfer.h"

void Presenter_RF_TxExcute()
{
	osEvent evt = osMailGet(RFTx_brailleCharMailBox, 0);
	if (evt.status == osEventMail) {
		BrailleAscii_t *p = evt.value.p;
		uint8_t bits6 = p->bits6;
		//char alphabet   = p->alphabet;  // 나중에 LCD용

		RF_Transfer(bits6);
		//Motor_DisplayBraille(alphabet);  // 나중에 LCD용
		osMailFree(RFTx_brailleCharMailBox, p);

	}
}

void Presenter_RF_RxExcute()
{
	osEvent evt = osMailGet(RFRx_brailleCharMailBox, 0);

	if (evt.status == osEventMail) {
		BrailleChar_t *p = evt.value.p;
		uint8_t bits6 = p->pattern;
		//char alphabet   = p->alphabet;  // 나중에 LCD용

        char msg[64];
        snprintf(msg, sizeof(msg), "Presenter bit6: 0x%02X\r\n", bits6);
        HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);

		Motor_DisplayBits(bits6);
		//Motor_DisplayBraille(alphabet);  // 나중에 LCD용
		osMailFree(RFRx_brailleCharMailBox, p);

	}

}

void RF_Transfer(uint8_t bits6){
//	uint8_t rx_data[NRF24L01P_PAYLOAD_LENGTH] = {0};
	uint8_t tx_data[NRF24L01P_PAYLOAD_LENGTH] = {bits6};

    char msg[64];
    snprintf(msg, sizeof(msg), "RF TX Data: 0x%02X\r\n", tx_data[0]);
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);

	nrf24l01p_tx_transmit(tx_data);

	HAL_Delay(100);

}
