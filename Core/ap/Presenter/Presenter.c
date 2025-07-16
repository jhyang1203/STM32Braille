///*
// * Presenter.c
// *
// *  Created on: Jul 3, 2025
// *      Author: kccistc
// */
//
//#include "Presenter.h"
//
//
//void Presenter_Init()
//{
//	Presenter_TimeWatchInit();
//	Presenter_StopWatchInit();
//	Presenter_DistanceInit();
//	Presenter_TempHumidInit();
//}
//
//void Presenter_Execute()
//{
//	static eModestate_t prevState = -1;
//	char str[30];
//	eModestate_t state = Model_GetModeState();
//	if(prevState != state){
//		prevState = state;
//		if (state == S_TIME_WATCH_MODE){
//			sprintf(str, "TimeWatch:");
//			FND_WriteDp(FND_DP_1 | FND_DP_10 | FND_DP_100 | FND_DP_1000 ,FND_DP_OFF);
//		}
//		else if (state == S_STOP_WATCH_MODE){
//			sprintf(str, "StopWatch:");
//			FND_WriteDp(FND_DP_1 | FND_DP_10 | FND_DP_100 | FND_DP_1000 ,FND_DP_OFF);
//		}
//		else if (state == S_DISTANCE_MODE){
//			sprintf(str, "Ultrasensor              ");
//			FND_WriteDp(FND_DP_1 | FND_DP_10 | FND_DP_100 | FND_DP_1000 ,FND_DP_OFF);
//		}
//		else if (state == S_TEMP_HUMID_MODE){
//			sprintf(str, "TEMP_HUMID              ");
//			FND_WriteDp(FND_DP_1 | FND_DP_10 | FND_DP_100 | FND_DP_1000 ,FND_DP_OFF);
//		}
//		LCD_writeStringXY(0, 0, str);
//	}
//
//	switch(state)
//	{
//	case S_TIME_WATCH_MODE:
//		Presenter_TimeWatchExcute();
//		break;
//	case S_STOP_WATCH_MODE:
//		Presenter_StopWatchExecute();
//		break;
//
//	case S_DISTANCE_MODE:
//		Presenter_DistanceExecute();
//		break;
//	case S_TEMP_HUMID_MODE:
//		Presenter_TempHumidExecute();
//		break;
//
//	}
//}
