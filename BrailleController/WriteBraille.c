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
	case 0b101011: return 'V';
	case 0b011101: return 'W';
	case 0b110011: return 'X';
	case 0b110111: return 'Y';
	case 0b100111: return 'Z';
	default:       return '?';
	}
}


void WriteBraille_Run()
{
	osEvent evt = osMailGet(BrailleSwitchMailBox, 0);
	// 논블로킹으로 메일박스에서 가져옴
	if (evt.status != osEventMail) return;
	// get 이벤트가 발생하지 않으면 함수 종료 (아무것도 안함)
	Switch_t *recv = (Switch_t *)evt.value.p;
	// 메일 박스에서 가져온 데이터의 값을 switch 타입의 recv에 넣음
	uint8_t bits = recv->bits;
	// bits에 해당 데이터 넣음
	char alpha = ConvertBrailleToAlphabet(bits);
	// alpha에 비트 값을 알파벳으로 변환후 넣어줌
	osMailFree(BrailleSwitchMailBox, recv);
	// 가져왔으니 다시 해당 메일박스 비워줌

	BrailleData.brailleBits = bits;
	BrailleData.alphabet = alpha;
	// braille 데이터에 해당 값들 넣어줌


	Braille_t *pBrailleData = osMailAlloc(BrailleDataMailBox, 0);
	// 브레일 데이터 형태 메일박스에 넣을거임 (구조체를 넣기 위해 빈슬롯 할당 요청)

	if (pBrailleData != NULL) {
	// 슬롯 할당 성공했으면
		memcpy(pBrailleData, &BrailleData, sizeof(Braille_t));
		// pbraille 데이터에 Brailledata값 복사함
		osMailPut(BrailleDataMailBox, pBrailleData);
		// 메일박스에 pbrqille데이터 넣어줌
	}
}


