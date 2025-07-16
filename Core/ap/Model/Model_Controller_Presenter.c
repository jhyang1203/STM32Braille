/*
 * Model_Controller_Presenter.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "Model_Controller_Presenter.h"

osMailQId brailleCharMailBox;
osMailQDef(brailleCharMailQ, 8, BrailleChar_t);

void Model_Controller_Presenter_Init(){
	brailleCharMailBox = osMailCreate(osMailQ(brailleCharMailQ), NULL);
}
