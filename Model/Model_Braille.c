/*
 * Model_Braille.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */


#include "Model_Braille.h"

osMailQId brailleMailBox;
osMailQDef(brailleQueue, 4, Model_Motor_t);

void Model_BrailleInit()
{
	brailleMailBox = osMailCreate(osMailQ(brailleQueue), NULL);
}

void Model_SendBrailleInput(uint8_t bits6, char alphabet)
{

	Model_Motor_t *pBrailleMsg = osMailAlloc(brailleMailBox, 0);
	if (pBrailleMsg == NULL) return;

	pBrailleMsg->bits6  = bits6;
	pBrailleMsg->alphabet = alphabet;

	osMailPut(brailleMailBox, pBrailleMsg);
}
