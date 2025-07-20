/*
 * Listener.c
 *
 *  Created on: Jul 16, 2025
 *      Author: kccistc
 */


#include "Listener.h"

Button_Handler_t hbtnMode;
Button_Handler_t hbtnStart;

uint8_t mode= S_READ_MODE;
uint8_t read_state = S_READ_STOP;
uint8_t write_state = S_WRITE_STOP;

void Listener_Init()
{
	Button_Init(&hbtnStart, GPIOB, GPIO_PIN_2);
	Button_Init(&hbtnMode, GPIOC, GPIO_PIN_4);
	Model_Listener_Controller_Init();
}

void Listener_Execute()
{
    char msg[64];
	switch(mode)
	{
		case S_READ_MODE:
			switch(read_state)
			{
				case S_READ_STOP:
					if (Button_GetState(&hbtnMode) == ACT_RELEASED){
						mode = S_WRITE_MODE;
					    snprintf(msg, sizeof(msg), "Mode: %s \r\n", "write mode");
					    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);
					}
					else {
						Listener_CNNStop();
						if (Button_GetState(&hbtnStart) == ACT_RELEASED) read_state = S_READ_START;
					}
					break;
				case S_READ_START:
					if (Button_GetState(&hbtnMode) == ACT_RELEASED){
						mode = S_WRITE_MODE;
					    snprintf(msg, sizeof(msg), "Mode: %s ", "write mode");
					    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);
					}
					else {
						Listener_CNNExecute();
						read_state = S_READ_STOP;
					}
					break;
			}
			break;

		case S_WRITE_MODE:
			switch(write_state)
			{
				case S_WRITE_STOP:
					if (Button_GetState(&hbtnMode) == ACT_RELEASED){
						mode = S_READ_MODE;
					    snprintf(msg, sizeof(msg), "Mode: %s \r\n", "read mode");
					    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);
					}
					else {
						Listener_SwitchStop();
						if (Button_GetState(&hbtnStart) == ACT_RELEASED) write_state = S_WRITE_START;
					}
					break;
				case S_WRITE_START:
					if (Button_GetState(&hbtnMode) == ACT_RELEASED){
						mode = S_READ_MODE;
					    snprintf(msg, sizeof(msg), "Mode: %s ", "read mode");
					    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 1000);
					}
					else {
						Listener_SwitchExecute();
						write_state = S_WRITE_STOP;
					}
					break;
			}
			break;
	}
}
