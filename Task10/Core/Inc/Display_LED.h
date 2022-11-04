/*
 * Display_LED.h
 *
 *  Created on: Oct 30, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_
#include"main.h"
#include "button.h"
#include "Finite_State_Machine.h"

extern int time_RED;
extern int time_GREEN;
extern int time_YELLOW;

extern int time_RED_TOP_BOTTOM;
extern int time_YELLOW_TOP_BOTTOM;
extern int time_GREEN_TOP_BOTTOM;

extern int time_RED_LEFT_RIGHT;
extern int time_GREEN_LEFT_RIGHT;
extern int time_YELLOW_LEFT_RIGHT;



void set_Time_RED(int timeRed);
void set_Time_YELLOW(int timeYellow);
void set_Time_GREEN(int timeGreen);
void setTime_ALL_LED_TRAFFIC();


int get_Time_RED();
int get_Time_YELLOW();
int get_Time_GREEN();


void ToggleSignal_TOP_BOTTOM_LED(int index);
void ToggleSignal_LEFT_RIGHT_LED(int index);
void display7SEG(int num);
void clearALLLED_Traffic();
void clearALLLED7SEG_Control();
void display_TRAFFICLIGHT_LEFT_RIGHT();
void display_TRAFFICLIGHT_TOP_BOTTOM();
void display_4LINE_TRAFFICLIGHT();
void display_LED7SEG_CONTROLLER(int input_time, int mode);
void Blinking_LED(int mode);   // ALL Single led blinking at 2Hz.
#endif /* INC_DISPLAY_LED_H_ */
