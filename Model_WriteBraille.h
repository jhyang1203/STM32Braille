/*
 * Model_WriteBraille.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_WRITEBRAILLE_H_
#define AP_MODEL_MODEL_WRITEBRAILLE_H_
#include <stdint.h>
#include "cmsis_os.h"

void Model_WriteBrailleInit();
uint8_t Model_ReceiveSwitchBits();

extern osMailQId BrailleDataMailBox;
extern osMailQId BrailleSwitchMailBox;

typedef struct {
	uint8_t brailleBits;
	char alphabet;
}Braille_t;

typedef struct {
    uint8_t bits;
}Switch_t;

//const uint8_t brailleMap[26][6] = {
//    {1,0,0,0,0,0}, // A
//    {1,0,1,0,0,0}, // B
//    {1,1,0,0,0,0}, // C
//    {1,1,0,1,0,0}, // D
//    {1,0,0,1,0,0}, // E
//    {1,1,1,0,0,0}, // F
//    {1,1,1,1,0,0}, // G
//    {1,0,1,1,0,0}, // H
//    {0,1,1,0,0,0}, // I
//    {0,1,1,1,0,0}, // J
//    {1,0,0,0,1,0}, // K
//    {1,0,1,0,1,0}, // L
//    {1,1,0,0,1,0}, // M
//    {1,1,0,1,1,0}, // N
//    {1,0,0,1,1,0}, // O
//    {1,1,1,0,1,0}, // P
//    {1,1,1,1,1,0}, // Q
//    {1,0,1,1,1,0}, // R
//    {0,1,1,0,1,0}, // S
//    {0,1,1,1,1,0}, // T
//    {1,0,0,0,1,1}, // U
//    {1,0,1,0,0,1}, // V
//    {0,1,1,1,1,1}, // W
//    {1,1,0,0,1,1}, // X
//    {1,1,0,1,1,1}, // Y
//    {1,0,0,1,1,1}  // Z
//};


#endif /* AP_MODEL_MODEL_WRITEBRAILLE_H_ */
