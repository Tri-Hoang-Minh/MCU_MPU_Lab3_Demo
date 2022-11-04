/*
 * button.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET  // 1: High
#define PRESSED_STATE GPIO_PIN_RESET //0: LOW, khi nhan o pull up

void button_reading();
GPIO_PinState get_button2_value();
unsigned char is_button_pressed_1s();
int is_button1_Press();
int is_button2_Press();
int is_button3_Press();
void subKeyProcess1();

int is_button1_Press_v2();
int is_button2_Press_v2();
int is_button3_Press_v2();
#endif /* INC_BUTTON_H_ */
