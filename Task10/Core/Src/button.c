/*
 * button.c
 *
 *  Created on: Oct 31, 2022
 *      Author: Hoang Tri
 */
#include "button.h"


#define NO_OF_BUTTONS		1
#define DURATION_FOR_AUTO_INCREASING	254

#define BUTTON_IS_PRESSED           GPIO_PIN_RESET   //0
#define BUTTON_IS_RELEASED          GPIO_PIN_SET     //1

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

int button1_State = 0;
int button3_State = 0;
int button2_State = 0;

void button_reading(void)
{
	for(int i = 0; i < NO_OF_BUTTONS; i++){
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
			if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			{
				buttonBuffer[i] = debounceButtonBuffer1[i];
			}
			if(buttonBuffer[i] ==  BUTTON_IS_PRESSED )
			{
				if(counterForButtonPress1s[i]< DURATION_FOR_AUTO_INCREASING)
				{
					counterForButtonPress1s[i]++;
				}
				else
				{
					flagForButtonPress1s[i] = 1;
				}
			}
			else
			{
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
}

GPIO_PinState get_button2_value()
{
	return buttonBuffer[0];
}

unsigned char is_button_pressed_1s()
{
	return flagForButtonPress1s[0];
}

int is_button1_Press(){
	if(HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin)==BUTTON_IS_PRESSED)
	{
		button1_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button1_State = 0;
		return 1;
	}
	return 0;
}
int is_button2_Press()
{
	if(HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin)==BUTTON_IS_RELEASED)
	{
		button2_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button2_State = 0;
		return 1;
	}
	return 0;
}
int is_button3_Press()
{
	if(HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin)==BUTTON_IS_PRESSED)
	{
		button3_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button3_State = 0;
		return 1;
	}
	return 0;
}










