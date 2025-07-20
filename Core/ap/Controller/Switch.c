/*
 * Switch.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "Switch.h"

const BrailleChar_t braille_table[] = {
    {0x01, 'A'},  // ●1
    {0x05, 'B'},  // ●1 ●3
    {0x03, 'C'},  // ●1 ●2
    {0x0B, 'D'},  // ●1 ●2 ●4
    {0x09, 'E'},  // ●1 ●4
    {0x07, 'F'},  // ●1 ●2 ●3
    {0x0F, 'G'},  // ●1 ●2 ●3 ●4
    {0x0D, 'H'},  // ●1 ●3 ●4
    {0x06, 'I'},  // ●2 ●3
    {0x0E, 'J'},  // ●2 ●3 ●4
    {0x11, 'K'},  // ●1 ●5
    {0x15, 'L'},  // ●1 ●3 ●5
    {0x13, 'M'},  // ●1 ●2 ●5
    {0x1B, 'N'},  // ●1 ●2 ●4 ●5
    {0x19, 'O'},  // ●1 ●4 ●5
    {0x17, 'P'},  // ●1 ●2 ●3 ●5
    {0x1F, 'Q'},  // ●1 ●2 ●3 ●4 ●5
    {0x1D, 'R'},  // ●1 ●3 ●4 ●5
    {0x16, 'S'},  // ●2 ●3 ●5 //
    {0x1E, 'T'},  // ●2 ●3 ●4 ●5
    {0x31, 'U'},  // ●1 ●5 ●6
    {0x35, 'V'},  // ●1 ●3 ●5 ●6
    {0x2E, 'W'},  // ●2 ●3 ●4 ●6 //
    {0x33, 'X'},  // ●1 ●2 ●5 ●6
    {0x3B, 'Y'},  // ●1 ●2 ●4 ●5 ●6
    {0x39, 'Z'}   // ●1 ●4 ●5 ●6
};

void Switch_Execute()
{
    osEvent evt = osMessageGet(brailleMsgBox, 0); // 패턴 수신
    uint8_t pattern;

    if (evt.status == osEventMessage) {
        pattern = evt.value.v;

        char matchedChar = '?';  // 기본값: 매칭 안 됨 표시
        for (int i = 0; i < sizeof(braille_table)/sizeof(BrailleChar_t); i++) {
            if (braille_table[i].pattern == pattern) {
                matchedChar = braille_table[i].character;
                break;
            }
        }

        // 구조체 생성 및 메일 큐 전송
        BrailleChar_t *pData = osMailAlloc(brailleCharMailBox, 0);
        if (pData != NULL) {
            pData->pattern = pattern;
            pData->character = matchedChar;

            char msg[64];
            snprintf(msg, sizeof(msg), "pattern: 0x%02X, character: %c\r\n", pData->pattern, pData->character);
            HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);

            osMailPut(brailleCharMailBox, pData);
          //  osMailFree(brailleCharMailBox, pData);  // 💡 이거 없으면 8개 제한
        }
    }
}


