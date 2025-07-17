/*
 * Model_WriteBraille.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */


#include "Model_WriteBraille.h"


osMailQId BrailleDataMailBox;  // (bits, alphabet) 프레젠터와 공유
osMailQId BrailleSwitchMailBox;  // (6비트 스위치 값) 리스너와 공유

osMailQDef(BrailleDataQueue, 4, Braille_t);  // 4개의 braille_t 타입으로 큐 정의
osMailQDef(BrailleSwitchQueue, 4, Switch_t);  // 4개의 switch_t 타입으로 큐 정의
//osMailQDef(name, depth, type): 깊이(depth)만큼 메시지를 버퍼링할 수 있는 메일큐

void Model_WriteBrailleInit()
{
	BrailleDataMailBox = osMailCreate(osMailQ(BrailleDataQueue), NULL);
	BrailleSwitchMailBox = osMailCreate(osMailQ(BrailleSwitchQueue), NULL);
}
// 함수 실행시 한번 호출해서 두 메일큐를 실제 큐 객체로 생성


uint8_t Model_ReceiveSwitchBits()
{
    osEvent evt = osMailGet(BrailleSwitchMailBox, 0);  // non-blocking
    //논 블로킹으로 큐에서 하나를 꺼냄
    if (evt.status == osEventMail) {
    // 꺼내는 데 성공했으면 내부 코드 실행
        uint8_t *pBits = (uint8_t *)evt.value.p;
        uint8_t bits = *pBits;
        osMailFree(BrailleSwitchMailBox, pBits);
        return bits;
    }

    return 0x00;
    // 꺼냈으면 bits값 반환, 없으면 0x00 반환
}
