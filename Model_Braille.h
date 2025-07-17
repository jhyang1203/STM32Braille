/*
 * Model_Braille.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_BRAILLE_H_
#define AP_MODEL_MODEL_BRAILLE_H_
#include <stdint.h>
#include "cmsis_os.h"


typedef struct{
	uint8_t bits6;   // 스위치 6비트
	char    alphabet;  // 판별된 알파벳
}Model_Motor_t;

extern osMailQId brailleMailBox;

void Model_BrailleInit();
void Model_SendBrailleInput(uint8_t bits6, char alphabet);

#endif /* AP_MODEL_MODEL_BRAILLE_H_ */
