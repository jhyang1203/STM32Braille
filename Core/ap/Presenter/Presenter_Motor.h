/*
 * Presenter_Motor.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_PRESENTER_MOTOR_H_
#define AP_PRESENTER_PRESENTER_MOTOR_H_
#include "cmsis_os.h"
//#include "Model_Braille.h"
#include "Motor.h"
#include "Model_Controller_Presenter.h"

extern UART_HandleTypeDef huart2;

void Presenter_MotorInit();
void Presenter_MotorExcute();

#endif /* AP_PRESENTER_PRESENTER_MOTOR_H_ */
