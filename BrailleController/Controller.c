#include "Controller.h"


void Controller_CheckEventMode();

void Controller_Init()
{
	WriteBraille_Init();
	Model_SetModeState(S_STOP_MODE);
}

void Controller_Excute()
{
	eModeState_t state = Model_GetModeState();

	switch (state)
	{
	case S_MOTOR_MODE:
		WriteBraille_Excute();
		Model_SetModeState(S_STOP_MODE);
		break;
	case S_STOP_MODE:
		break;
	}


	Controller_CheckEventMode();
}

void Controller_CheckEventMode()
{
	osEvent evt = osMessageGet(modeEventMsgBox, 0);
	// 논블로킹으로 가져옴 (버튼 상태)
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		//메일 박스에 있는걸 가저요면
		evtState = evt.value.v;
		// 메시지 값(v)으로 button 이벤트 종류(EVENT_MODE)를 읽음
		if (evtState != EVENT_MODE) {
		// 버튼 눌린게 아니면 함수 종료
			return;
		}

		eModeState_t state = Model_GetModeState();
		// 상태 가져옴 (현재 모드 조회)

		if (state == S_STOP_MODE){
			Model_SetModeState(S_MOTOR_MODE);
		// 스탑 모드에서 버튼 눌렸을 떄만 모터 모드로 바꿈
		}

	}

}
