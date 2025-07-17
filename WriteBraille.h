/*
 * WriteBraille.h
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_WRITEBRAILLE_H_
#define AP_CONTROLLER_WRITEBRAILLE_H_

#include <stdint.h>
#include <string.h>
#include "Model_WriteBraille.h"
#include "cmsis_os.h"
#include "usart.h"

void WriteBraille_Init();
void WriteBraille_Excute();
void WriteBraille_Run();


#endif /* AP_CONTROLLER_WRITEBRAILLE_H_ */
