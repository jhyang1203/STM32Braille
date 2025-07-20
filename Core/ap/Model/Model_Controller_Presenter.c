/*
 * Model_Controller_Presenter.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#include "Model_Controller_Presenter.h"
#include "BrailleTable.h"

osMailQId brailleCharMailBox;
osMailQDef(brailleCharMailQ, 8, BrailleChar_t);

osMailQId CNN_brailleCharMailBox;
osMailQDef(CNN_brailleCharMailQ, 8, BrailleAscii_t);

void Model_Controller_Presenter_Init(){
	brailleCharMailBox = osMailCreate(osMailQ(brailleCharMailQ), NULL);
	CNN_brailleCharMailBox = osMailCreate(osMailQ(CNN_brailleCharMailQ), NULL);
}
