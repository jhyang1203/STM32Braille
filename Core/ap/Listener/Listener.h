/*
 * Listener.h
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#ifndef AP_LISTENER_LISTENER_H_
#define AP_LISTENER_LISTENER_H_

#include <stdio.h>
#include "string.h"
#include "Listener_Switch.h"
#include "Listener_CNN.h"
#include "Model_Listener_Controller.h"
#include "Button.h"

void Listener_Init();
void Listener_Execute();

typedef enum {S_READ_MODE, S_WRITE_MODE} eModestate_t;
typedef enum {S_WRITE_STOP, S_WRITE_START} eWritestate_t;
typedef enum {S_READ_STOP, S_READ_START} eReadstate_t;

#endif /* AP_LISTENER_LISTENER_H_ */
