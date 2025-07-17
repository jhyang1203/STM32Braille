/*
 * WriteBraille.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "WriteBraille.h"
#include "stdio.h"

Braille_t BrailleData;

void WriteBraille_Run();
char ConvertBrailleToAlphabet(uint8_t bits);

void WriteBraille_Init()
{
	Model_WriteBrailleInit();
}

void WriteBraille_Excute()
{
	WriteBraille_Run();
}

char ConvertBrailleToAlphabet(uint8_t bits)
{
	switch (bits) {
	case 0b100000: return 'A';
	case 0b101000: return 'B';
	case 0b110000: return 'C';
	case 0b110100: return 'D';
	case 0b100100: return 'E';
	case 0b111000: return 'F';
	case 0b111100: return 'G';
	case 0b101100: return 'H';
	case 0b011000: return 'I';
	case 0b011100: return 'J';
	case 0b100010: return 'K';
	case 0b101010: return 'L';
	case 0b110010: return 'M';
	case 0b110110: return 'N';
	case 0b100110: return 'O';
	case 0b111010: return 'P';
	case 0b111110: return 'Q';
	case 0b101110: return 'R';
	case 0b011010: return 'S';
	case 0b011110: return 'T';
	case 0b100011: return 'U';
	case 0b101001: return 'V';
	case 0b011111: return 'W';
	case 0b110011: return 'X';
	case 0b110111: return 'Y';
	case 0b100111: return 'Z';
	default:       return '?';
	}
}


void WriteBraille_Run()
{
	osEvent evt = osMailGet(BrailleSwitchMailBox, 0);  // non-blocking
	if (evt.status != osEventMail) return;  // ❗ Mail 없으면 아무것도 하지 않음

	Switch_t *recv = (Switch_t *)evt.value.p;
	uint8_t bits = recv->bits;
	char alpha = ConvertBrailleToAlphabet(bits);
	osMailFree(BrailleSwitchMailBox, recv);

	//테스트용
	char msg[64];
	sprintf(msg, "Bits: %02X -> %c\r\n", bits, alpha);
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	//테스트용

	BrailleData.brailleBits = bits;
	BrailleData.alphabet = alpha;

	Braille_t *pBrailleData = osMailAlloc(BrailleDataMailBox, 0);
	if (pBrailleData != NULL) {
		memcpy(pBrailleData, &BrailleData, sizeof(Braille_t));
		osMailPut(BrailleDataMailBox, pBrailleData);
	}
}


