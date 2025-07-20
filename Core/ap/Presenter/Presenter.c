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
	Presenter_MotorInit();
}

void Presenter_Excute()
{
	if (mode == S_READ_MODE) Presenter_MotorExcute();

	else if (mode == S_WRITE_MODE) Presenter_RFExcute();

}
