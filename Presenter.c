/*
 * Presenter.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Presenter.h"
#include <stdio.h>

void Presenter_Init()
{
	Presenter_TimeWatchInit();
	Presenter_StopWatchInit();
	Presenter_DistanceInit();
	Presenter_TempHumidInit();
	Presenter_MotorInit();
}

void Presenter_Excute()
{
//	static eModeState_t prevState;
//	eModeState_t state = Model_GetModeState();
//	if (prevState != state) {
//		char str[30];
//		prevState = state;
//
//		if (state == S_TIMEWATCH_MODE) {
//			sprintf(str, "TimeWatch          ");
//			FND_WriteDp(FND_DP_1000|FND_DP_100|FND_DP_10|FND_DP_1, FND_DP_OFF);
//		}
//		else if (state == S_STOPWATCH_MODE) {
//			sprintf(str, "StopWatch: ");
//			FND_WriteDp(FND_DP_1000|FND_DP_100|FND_DP_10|FND_DP_1, FND_DP_OFF);
//		}
//		LCD_writeStringXY(0, 0, str);
//	}
//
//	switch (state)
//	{
//	case S_TIMEWATCH_MODE:
//		Presenter_TimeWatchExcute();
//		break;
//	case S_STOPWATCH_MODE:
//		Presenter_StopWatchExcute();
//		break;
//	case S_DISTANCE_MODE:
//		Presenter_DistanceExcute();
//		break;
//	case S_TEMP_HUMID_MODE:
//		Presenter_TempHumidExcute();
//		break;
//
//	case S_MOTOR_MODE:
//		Presenter_MotorExcute();
//		break;
//	}
	Presenter_MotorExcute();
}
