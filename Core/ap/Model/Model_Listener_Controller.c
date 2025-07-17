/*
 * Model_Listener_Controller.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "Model_Listener_Controller.h"

osMessageQId brailleMsgBox;  // 메시지 큐 핸들
osMessageQDef(brailleQueue, 8, uint32_t);


void Model_Listener_Controller_Init()
{
	brailleMsgBox = osMessageCreate(osMessageQ(brailleQueue), NULL);	// Listener -> Controller
}
