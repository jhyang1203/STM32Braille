/*
 * Listener.h
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#ifndef AP_LISTENER_LISTENER_H_
#define AP_LISTENER_LISTENER_H_
#include "Listener_Switch.h"
#include "Model_Listener_Controller.h"
#include "Button.h"

void Listener_Init();
void Listener_Execute();

typedef enum {S_BRAILLE_STOP, S_BRAILLE_MEASURE} eModestate_t;

#endif /* AP_LISTENER_LISTENER_H_ */
