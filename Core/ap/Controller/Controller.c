/*
 * Controller.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#include "Controller.h"
#include <string.h>


void Controller_Init()
{
	Model_Controller_Presenter_Init();
}

void Controller_Execute()
{
	if (mode == S_READ_MODE) CNN_Execute();

	else if (mode == S_WRITE_MODE) Switch_Execute();
}








