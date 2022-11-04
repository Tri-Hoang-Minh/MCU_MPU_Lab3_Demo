/*
 * Finite_State_Machine.h.c
 *
 *  Created on: Oct 31, 2022
 *      Author: Hoang Tri
 */
#include "Finite_State_Machine.h"

#define TIME_BLINKING               250
#define TIME_AUTO_INCREASES         100          // adjust times to flexible with frequency.

enum ButtonMode {MODE_1,MODE_2,MODE_3,MODE_4} ;
enum ButtonMode button_mode = MODE_1 ;           // button mode of first state.

int time_RED_edit=0;
int time_GREEN_edit=0;
int time_YELLOW_edit=0;

int timeAutoIncreases = TIME_AUTO_INCREASES;
int timeBlinking= TIME_BLINKING;

void fsm_processing()
{
 switch (button_mode)
 {
      case MODE_1:
  		if(is_button1_Press())
  		{
  			time_RED_edit   = get_Time_RED();             // time_RED_edit = time_RED;
  			time_GREEN_edit = get_Time_GREEN();           // time_GREEN_edit = time_GREEN;
  			time_YELLOW_edit = get_Time_YELLOW();         // time_YELLOW_edit = time_YELLOW;
  			clearALLLED_Traffic();                        // clear ALL LED of 4 Line traffic and 4 LED 7SEGMENT show times of traffic light.
  			button_mode = MODE_2;
  		}
  		else
  		{
  			display_4LINE_TRAFFICLIGHT();
  		}
	  break;
      case MODE_2:
    	 if(is_button1_Press())
    	{
                button_mode=MODE_3;
                break;
    	}
  		else if(is_button_pressed_1s())
  		{
  			inscreases_time_after_1s();
  		}
  		else if(is_button2_Press())
  		{
  			inscreases_time();
  		}
  		else if(is_button3_Press())
  		{
  			set_Time_RED(time_RED_edit);      // timeRED= time_RED_edit
  			// break ?????
  		}
  		display_LED7SEG_CONTROLLER(time_RED_edit, 2);
  		blinking_led_2Hz();
	  break;
      case MODE_3:
     	 if(is_button1_Press())
     	{
                 button_mode=MODE_4;
                 break;
     	}
   		else if(is_button_pressed_1s())
   		{
   			inscreases_time_after_1s();
   		}
   		else if(is_button2_Press())
   		{
   			inscreases_time();
   		}
   		else if(is_button3_Press())
   		{
   			 set_Time_YELLOW(time_YELLOW_edit);    // timeYELLOW= time_YELLOW_edit
   			// break ?????
   		}
   		display_LED7SEG_CONTROLLER(time_YELLOW_edit, 3);
   		blinking_led_2Hz();
	  break;
      case MODE_4:
     	 if(is_button1_Press())
      	{
     		 setTime_ALL_LED_TRAFFIC();
     		 clearALLLED7SEG_Control();
             button_mode=MODE_1;
             break;
      	}
        else if(is_button_pressed_1s())
        {
    		 inscreases_time_after_1s();
        }
    	else if(is_button2_Press())
    	{
    		 inscreases_time();
    	}
    	else if(is_button3_Press())
    	{
    		set_Time_GREEN(time_GREEN_edit);  // timeYELLOW= time_YELLOW_edit
    		// break ?????
    	}
    		display_LED7SEG_CONTROLLER(time_GREEN_edit, 4);
    		blinking_led_2Hz();
	  break;
	  default:
	  break;
 }
}
void inscreases_time()
{
switch(button_mode)
{
  case MODE_2:
	time_RED_edit++;
	if(time_RED_edit >= 99)              // start at 0;
	{
		time_RED_edit = 0;
	}
  break;
  case MODE_3:
	time_YELLOW_edit++;
	if(time_YELLOW_edit >= 99)
	{
		time_YELLOW_edit = 0;
	}
  break;
  case MODE_4:
		time_GREEN_edit++;
		if(time_GREEN_edit >= 99)
		{
			time_GREEN_edit = 0;
		}
		break;
  default:
  break;
}
}
void inscreases_time_after_1s()
{
        if(timeAutoIncreases<=0)
        {
        	inscreases_time();
        	timeAutoIncreases=TIME_AUTO_INCREASES;
        }
        timeAutoIncreases--;
}
void blinking_led_2Hz()
{
	// 2Hz => 250*2.10(^-3)
   if(timeBlinking<=0)
   {
	   switch(button_mode)
	   {
	       case MODE_2:
	    	 //  mode = 2;
	    	   Blinking_LED(2);
	       break;
	       case MODE_3:
	    	 //  mode =3;
	    	   Blinking_LED(3);
	       break;
	       case MODE_4:
	    	//   mode = 4;
	    	   Blinking_LED(4);
	       break;
	       default:
	       break;
	   }
	   timeBlinking=TIME_BLINKING;   //250
   }
   timeBlinking--;
}
