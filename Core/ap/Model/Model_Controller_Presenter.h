/*
 * Model_Controller_Presenter.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_CONTROLLER_PRESENTER_H_
#define AP_MODEL_MODEL_CONTROLLER_PRESENTER_H_

#include <stdint.h>
#include "cmsis_os.h"

typedef struct {
    uint8_t pattern;
    char character;
} BrailleChar_t;

extern osMailQId brailleCharMailBox;

void Model_Controller_Presenter_Init();

#endif /* AP_MODEL_MODEL_CONTROLLER_PRESENTER_H_ */
