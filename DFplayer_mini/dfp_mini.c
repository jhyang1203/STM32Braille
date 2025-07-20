/*
 * dfp_mini.c
 *
 *  Created on: Jul 20, 2025
 *      Author: kccistc
 */

#include "dfp_mini.h"

#define FRAME_LEN      10
#define START_BYTE     0x7E
#define VERSION_BYTE   0xFF
#define LENGTH_BYTE    0x06
#define NO_FEEDBACK    0x00
#define END_BYTE       0xEF

static uint8_t frame[FRAME_LEN];

static uint16_t make_checksum(void) {
    uint16_t sum = 0;
    // VERSION ~ PARAM_LSB (바이트 1 ~ 6)
    for (int i = 1; i <= 6; i++) sum += frame[i];
    return 0xFFFF - sum + 1;
}

static void send_cmd(uint8_t cmd, uint16_t param) {
    frame[0] = START_BYTE;
    frame[1] = VERSION_BYTE;
    frame[2] = LENGTH_BYTE;
    frame[3] = cmd;
    frame[4] = NO_FEEDBACK;
    frame[5] = (param >> 8) & 0xFF;
    frame[6] = param & 0xFF;

    uint16_t chk = make_checksum();
    frame[7] = (chk >> 8) & 0xFF;
    frame[8] = chk & 0xFF;
    frame[9] = END_BYTE;

    // 한번에 10바이트 전송
    HAL_UART_Transmit_IT(&huart1, frame, FRAME_LEN);
}

void dfp_init(void) {
    // 전원 안정화 대기 (최소 500ms 권장)
    osDelay(500);
    // 리셋 명령 보내기 (모듈 내부 초기화)
    send_cmd(0x0C, 0);
    osDelay(200);
    // 볼륨 초기화 (옵션)
    dfp_setVolume(10);
}

void dfp_playTrack(uint16_t track) {
    // track: 1~3000 (001.mp3 → track=1)
    send_cmd(0x03, track);
}

void dfp_setVolume(uint8_t vol) {
    if (vol > 30) vol = 30;
    send_cmd(0x06, vol);
}

void dfp_pause()	// 일시정지
{
	send_cmd(0x0e, 0);
}

void dfp_stop()
{
	send_cmd(0x16, 0);
}
