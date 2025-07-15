/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: rhoblack
 */

#include "ap_main.h"
#include <stdio.h>
#include <string.h>

int ap_main()
{
    while (1)
    {
        Motor_SetAngle(150);
        HAL_Delay(1000);

        Motor_SetAngle(50);
        HAL_Delay(1000);

        Motor_SetAngle(90);
        HAL_Delay(1000);

        Motor_SetAngle(30);
        HAL_Delay(1000);
    }

	return 0;
}

void ap_init()
{
	Motor_Init(&htim1, TIM_CHANNEL_1);
	Motor_SetAngle(0);
	Motor_Start();
}




