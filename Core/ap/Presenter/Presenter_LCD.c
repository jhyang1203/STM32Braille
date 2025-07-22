/*
 * Presenter_LCD.c
 *
 *  Created on: Jul 22, 2025
 *      Author: kccistc
 */

#include "Presenter_LCD.h"


void LCD_Presenter_TX (char alphabet){

		//ILI9341_FillScreen(ILI9341_WHITE);
		char str[2] = {alphabet, '\0'};
		ILI9341_WriteString(50, 140, str, Font_7x10, ILI9341_BLACK, ILI9341_WHITE);
}


void LCD_Presenter_RX (char character){

		//ILI9341_FillScreen(ILI9341_WHITE);
		char str[2] = {character, '\0'};
		ILI9341_WriteString(50, 140, str, Font_7x10, ILI9341_BLACK, ILI9341_WHITE);
}
