/*
 * Model_WriteBraille.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */


#include "Model_WriteBraille.h"


osMailQId BrailleDataMailBox;
osMailQId BrailleSwitchMailBox;

osMailQDef(BrailleDataQueue, 4, Braille_t);
osMailQDef(BrailleSwitchQueue, 4, Switch_t);

void Model_WriteBrailleInit()
{
	BrailleDataMailBox = osMailCreate(osMailQ(BrailleDataQueue), NULL);
	BrailleSwitchMailBox = osMailCreate(osMailQ(BrailleSwitchQueue), NULL);
}


uint8_t Model_ReceiveSwitchBits()
{
    osEvent evt = osMailGet(BrailleSwitchMailBox, 0);
    if (evt.status == osEventMail) {
        uint8_t *pBits = (uint8_t *)evt.value.p;
        uint8_t bits = *pBits;
        osMailFree(BrailleSwitchMailBox, pBits);
        return bits;
    }

    return 0x00;
}
