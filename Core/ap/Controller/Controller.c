///*
// * Controller.c
// *
// *  Created on: Jul 3, 2025
// *      Author: kccistc
// */
//
//#include "Controller.h"
//#include <string.h>
//
//void Controller_CheckEventMode();
//
//void Controller_Init()
//{
//	TimeWatch_Init();
//	StopWatch_Init();
//	Distance_Init();
//	TempHumid_Init();
//}
//
//void Controller_Execute()
//{
//	eModestate_t state = Model_GetModeState();
//
//	switch(state)
//	{
//	case S_TIME_WATCH_MODE:
//		TimeWatch_Excute();
//		break;
//	case S_STOP_WATCH_MODE:
//		StopWatch_Execute();
//		break;
//
//	case S_DISTANCE_MODE:
//		Distance_Execute();
//		break;
//	case S_TEMP_HUMID_MODE:
//		TempHumid_Execute();
//		break;
//	}
//
//	Controller_CheckEventMode();
//}
//
//
//void Controller_CheckEventMode()
//{
//	osEvent evt = osMessageGet(modeEventMsgBox, 0);	// non-blocking: 들어올때까지 기다리는게 아니라, 있나 없나 체크만 하고 넘어감
//	uint16_t evtState;
//
//	if (evt.status == osEventMessage) {
//		evtState = evt.value.v;
//		if(evtState != EVENT_MODE) {
//			return;
//		}
//		eModestate_t state = Model_GetModeState();
//
//		if (state == S_TIME_WATCH_MODE) {
//			Model_SetModeState(S_STOP_WATCH_MODE);
//			stopWatch_t *pStopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
//			memcpy(pStopWatchData, &stopWatchData, sizeof(stopWatch_t));
//			osMailPut(stopWatchDataMailBox, pStopWatchData);
//		}
//		else if (state == S_STOP_WATCH_MODE) {
//			Model_SetModeState(S_DISTANCE_MODE);
//			timeWatch_t *pTimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
//			memcpy(pTimeWatchData, &timeWatchData, sizeof(timeWatch_t));
//			osMailPut(timeWatchDataMailBox, pTimeWatchData);
//		}
//		else if (state == S_DISTANCE_MODE) {
//			Model_SetModeState(S_TEMP_HUMID_MODE);
//			distance_t *pDistanceData = osMailAlloc(distanceDataMailBox, 0);
//			memcpy(pDistanceData, &distanceData, sizeof(distance_t));
//			osMailPut(distanceDataMailBox, pDistanceData);
//		}
//		else if (state == S_TEMP_HUMID_MODE) {
//			Model_SetModeState(S_TIME_WATCH_MODE);
//			temphumid_t *pTempHumidData = osMailAlloc(temphumidDataMailBox, 0);
//			memcpy(pTempHumidData, &temphumidData, sizeof(temphumid_t));
//			osMailPut(temphumidDataMailBox, pTempHumidData);
//		}
//	}
//
//}
//
//
//
//
//
