/*
 * LCD16x2.h
 */

#ifndef LCD16X2_H_
#define LCD16X2_H_

#include "stm32f4xx_hal.h"

#define LCD_DB7_PORT GPIOE
#define LCD_DB7_PIN GPIO_PIN_15

#define LCD_DB6_PORT GPIOE
#define LCD_DB6_PIN GPIO_PIN_14

#define LCD_DB5_PORT GPIOF
#define LCD_DB5_PIN GPIO_PIN_3

#define LCD_DB4_PORT GPIOF
#define LCD_DB4_PIN GPIO_PIN_4

#define LCD_EN_PORT GPIOF
#define LCD_EN_PIN GPIO_PIN_13

#define LCD_RS_PORT GPIOF
#define LCD_RS_PIN GPIO_PIN_14

#define LCD_EN_DELAY 1


//-----[ Prototypes For All Functions ]-----

void LCD_Init();                  // Initialize The LCD For 4-Bit Interface
void LCD_Clear();                 // Clear The LCD Display
void LCD_SL();                    // Shift The Entire Display To The Left
void LCD_SR();                    // Shift The Entire Display To The Right
void LCD_CMD(unsigned char);      // Send Command To LCD
void LCD_DATA(unsigned char);     // Send 4-Bit Data To LCD
void LCD_Set_Cursor(unsigned char, unsigned char);  // Set Cursor Position
void LCD_Write_Char(char);        // Write Character To LCD At Current Position
void LCD_Write_String(char*);     // Write A String To LCD


#endif /* LCD16X2_H_ */
