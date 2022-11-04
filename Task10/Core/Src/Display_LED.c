/*
 * Display_LED.c
 *
 *  Created on: Oct 30, 2022
 *      Author: Hoang Tri
 */

#include "Display_LED.h"

#define TIME_PER_SECOND			250	// time to increase a second
#define TIME_RUN7SEGMENT		18  // SET OF jump to the interrupt service routine 18 time  => 18*2ms = 0.036s real time.
#define TIME_RUN7SEGMENT_EDIT	12  //SET OF jump to the interrupt service routine 12 time  => 12*2ms = 0.024s real time.

int time_RED=5;                 // value first state
int time_GREEN=3;               // value first state
int time_YELLOW=2;              // value first state

int time_RED_TOP_BOTTOM=5;
int time_YELLOW_TOP_BOTTOM=3;
int time_GREEN_TOP_BOTTOM=2;

int time_RED_LEFT_RIGHT=5;
int time_GREEN_LEFT_RIGHT=3;
int time_YELLOW_LEFT_RIGHT=2;

int time7SEG_TRAFFIC_LEFT_RIGHT=5;    // SET 5S FOR FIRST STATE OF LED 7SEG OF TRAFFIC LIGHT LEFT AND RIGHT;
int time7SEG_TRAFFIC_TOP_BOTTOM=3;    // SET 3S FOR FIRST STATE OF LED 7SEG OF TRAFFIC LIGHT TOP AND BOTTOM;
int time_period_run = TIME_PER_SECOND;            // SET OF jump to the interrupt service routine 250 time  => 250*2ms = 0.5s real time.
int timeRUN_LED7SEG_TRAFFICLIGHT=TIME_RUN7SEGMENT;
int timeRUN_LED7SEG_CONTROLLER=TIME_RUN7SEGMENT_EDIT;

void set_Time_RED(int timeRed)
{
    time_RED= timeRed;
}
void set_Time_YELLOW(int timeYellow)
{
   time_YELLOW= timeYellow;
}
void set_Time_GREEN(int timeGreen)
{
  time_GREEN= timeGreen;
}
void setTime_ALL_LED_TRAFFIC()
{
      time_RED_TOP_BOTTOM=time_RED;
      time_RED_LEFT_RIGHT= time_RED;

      time_YELLOW_TOP_BOTTOM=time_YELLOW;
      time_YELLOW_LEFT_RIGHT= time_YELLOW;

      time_GREEN_TOP_BOTTOM=time_GREEN;
      time_GREEN_LEFT_RIGHT= time_GREEN;
}
int get_Time_RED()
{
  return time_RED;
}
int get_Time_YELLOW()
{
 return time_YELLOW;
}
int get_Time_GREEN()
{
 return time_GREEN;
}


void ToggleSignal_TOP_BOTTOM_LED(int index)
{
	switch(index)
	{
	    case 0:
	    	HAL_GPIO_WritePin( LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);             // LED RED ON
	    	HAL_GPIO_WritePin( LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
	    	HAL_GPIO_WritePin( LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
		break;
	    case 1:
	    	HAL_GPIO_WritePin( LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
	    	HAL_GPIO_WritePin( LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);      // LED YELLOW ON
	    	HAL_GPIO_WritePin( LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
		break;
	    case 2:
	    	HAL_GPIO_WritePin( LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
	    	HAL_GPIO_WritePin( LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
	    	HAL_GPIO_WritePin( LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);       // LED GREEN ON
		break;
	    default:
	    break;
	}
}
void ToggleSignal_LEFT_RIGHT_LED(int index)
{
	switch(index)
	{
	    case 0:
	    	HAL_GPIO_WritePin( LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);             // LED RED ON
	        HAL_GPIO_WritePin( LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
	        HAL_GPIO_WritePin( LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
		break;
	    case 1:
	    	HAL_GPIO_WritePin( LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
	    	HAL_GPIO_WritePin( LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);      // LED YELLOW ON
	    	HAL_GPIO_WritePin( LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
		break;
	    case 2:
	    	HAL_GPIO_WritePin( LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
	    	HAL_GPIO_WritePin( LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
	    	HAL_GPIO_WritePin( LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);           // LED GREEN ON

		break;
	    default:
	    break;
	}
}
void display7SEG(int num)
{
	switch(num)
	{
	    case 0:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);     //a
	    	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);     //b
	        HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	    	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);     //g
	        HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 1:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);      //a
	 	  	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);     //b
	 	  	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);     //g
	 	  	HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 2:

	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);     //c
	 	  	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	 	  	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	 	 	HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 3:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	        HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	     	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	     	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	     	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	        HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	        HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);

	    break;
	    case 4:
	    	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);          //a
	    	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	    	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	    	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	    	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	        HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 5:
	    	 HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	    	 HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	    	 HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	 HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	 HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	    	 HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	    	 HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    	 HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 6:
	    	 HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	    	 HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	    	 HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	 HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	 HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	    	 HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	    	 HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    	 HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 7:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);    //g
		      HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 8:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	 	      HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    case 9:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	 	  	  HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 0);
	    break;
	    default:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);    //g
	 	  	  HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, 1);
	    break;
	}
}
void clearALLLED_Traffic()
{
	// clear all led 7SEG and LED Red,Green, yellow of Traffic light.
	        HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
	        HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
	        HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
	        HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 0);
            HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
            HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
            HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
            HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
            HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
            HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
}
void clearALLLED7SEG_Control()
{
	// clear ALL LED 7 SEG "MODE" and LED 7 SEG "SET TIMER"
           HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, 0);
           HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 0);
           HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, 0);
           HAL_GPIO_WritePin(EN8_GPIO_Port, EN8_Pin, 0);
}
void display_TRAFFICLIGHT_LEFT_RIGHT()
{
	 if(time_RED_LEFT_RIGHT>=0) // 5
	 {
		 time7SEG_TRAFFIC_LEFT_RIGHT= time_RED_LEFT_RIGHT;
		 time_RED_LEFT_RIGHT--;
		 ToggleSignal_LEFT_RIGHT_LED(0); // Toogle LED RED on.
		 //time7SEG_TRAFFIC_LEFT_RIGHT= time_RED_LEFT_RIGHT;
	 }
	 else if (time_GREEN_LEFT_RIGHT>=0)
	 {
		 time7SEG_TRAFFIC_LEFT_RIGHT= time_GREEN_LEFT_RIGHT;
		 time_GREEN_LEFT_RIGHT--;
		 ToggleSignal_LEFT_RIGHT_LED(2); // Toogle LED GREEN on.
	 }
	 else if(time_YELLOW_LEFT_RIGHT>=0)
	 {
		 time7SEG_TRAFFIC_LEFT_RIGHT= time_YELLOW_LEFT_RIGHT;
		 time_YELLOW_LEFT_RIGHT--;
		 ToggleSignal_LEFT_RIGHT_LED(1); // Toogle LED YELLOW on.
	 }
}
void display_LED7SEG_CONTROLLER(int time_input, int mode)
{
       if(timeRUN_LED7SEG_CONTROLLER>9)   // EN5 , EN6
       {
    	   HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, 1);  // Toggle Signal EN5 to show value "mode/10"
    	   display7SEG(mode/10);
       }
       else if(timeRUN_LED7SEG_CONTROLLER>6)
       {
    	   HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, 0);  // Toggle Signal EN6 to show value "mode%10"
    	   HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 1);
    	   display7SEG(mode%10);
       }
       else if(timeRUN_LED7SEG_CONTROLLER>3)
       {
    	   HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 0);  // Toggle Signal EN7 to show value "mode/10"
    	   HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, 1);
    	   display7SEG(time_input/10);
       }
       else if(timeRUN_LED7SEG_CONTROLLER>0)
       {
    	   HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, 0);  // Toggle Signal EN8 to show value "mode%10"
    	   HAL_GPIO_WritePin(EN8_GPIO_Port, EN8_Pin, 1);
    	   display7SEG(time_input%10);
       }
       else
       {
    	   timeRUN_LED7SEG_CONTROLLER=TIME_RUN7SEGMENT_EDIT; // = 16
    	   HAL_GPIO_WritePin(EN8_GPIO_Port, EN8_Pin, 0);
       }
       timeRUN_LED7SEG_CONTROLLER=timeRUN_LED7SEG_CONTROLLER-1;
}
void Blinking_LED(int mode)                // ALL single led blinking at 2Hz => 250*2.10^-3
{
	switch(mode)
	{
	  case 2:   // Adjust time for LED RED
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);

		  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
	  break;
	  case 3:  // Adjust time for LED YELLOW
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);

		  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
	  break;
	  case 4:  // Adjust time for LED GREEN
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);

		  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
	  break;
	  default:
	  break;
	}
}
void display_TRAFFICLIGHT_TOP_BOTTOM()
{
	// 0.5s will change state
	if(time_period_run<=0)
	{
		if(time_GREEN_TOP_BOTTOM>=0)   // 3 2 1 0
		{
			display_TRAFFICLIGHT_LEFT_RIGHT();
			time7SEG_TRAFFIC_TOP_BOTTOM=time_GREEN_TOP_BOTTOM; //!!!!!!
			time_GREEN_TOP_BOTTOM--;
			ToggleSignal_TOP_BOTTOM_LED(2);
			//time7SEG_TRAFFIC_TOP_BOTTOM=time_GREEN_TOP_BOTTOM; //!!!!!!
		}
		else if(time_YELLOW_TOP_BOTTOM>=0)  // 2 1 0
		{
			display_TRAFFICLIGHT_LEFT_RIGHT();
			time7SEG_TRAFFIC_TOP_BOTTOM=time_YELLOW_TOP_BOTTOM; //!!!!!!
			time_YELLOW_TOP_BOTTOM--;
			ToggleSignal_TOP_BOTTOM_LED(1);
		}
		else if(time_RED_TOP_BOTTOM>=0) // 5 4 3 2 1 0
		{
			display_TRAFFICLIGHT_LEFT_RIGHT();
			time7SEG_TRAFFIC_TOP_BOTTOM=time_RED_TOP_BOTTOM; //!!!!!!
			time_RED_TOP_BOTTOM--;
			ToggleSignal_TOP_BOTTOM_LED(0);
		}
		else
		{
			time_GREEN_TOP_BOTTOM=time_GREEN;   //3
			time_RED_TOP_BOTTOM=time_RED;       //5
			time_YELLOW_TOP_BOTTOM=time_YELLOW;  //2

			time_GREEN_LEFT_RIGHT= time_GREEN;    //3
			time_RED_LEFT_RIGHT= time_RED;        //5
			time_YELLOW_LEFT_RIGHT= time_YELLOW;  //2
		}
		time_period_run=TIME_PER_SECOND;
	}
	time_period_run=time_period_run-1;
}
void display_4LINE_TRAFFICLIGHT()
{
	display_TRAFFICLIGHT_TOP_BOTTOM();
	if(timeRUN_LED7SEG_TRAFFICLIGHT>15)        // display MODE 1
	{
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, 1);
		//HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 0);
		display7SEG(0);
	}
	else if(timeRUN_LED7SEG_TRAFFICLIGHT>12)  // display MODE 1
	{
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, 0);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 1);
		display7SEG(1);
	}
	else if(timeRUN_LED7SEG_TRAFFICLIGHT>9)
	{
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		//HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		display7SEG(time7SEG_TRAFFIC_TOP_BOTTOM/10);
	}
	else if(timeRUN_LED7SEG_TRAFFICLIGHT>6)
	{
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		display7SEG(time7SEG_TRAFFIC_TOP_BOTTOM%10);
	}
	else if(timeRUN_LED7SEG_TRAFFICLIGHT>3)
	{
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
	//	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 0);
		display7SEG(time7SEG_TRAFFIC_LEFT_RIGHT/10);
	}
	else if(timeRUN_LED7SEG_TRAFFICLIGHT>0)
	{
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
		display7SEG(time7SEG_TRAFFIC_LEFT_RIGHT%10);
	}
	else
	{
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 0);
		timeRUN_LED7SEG_TRAFFICLIGHT=TIME_RUN7SEGMENT;
	}
	    timeRUN_LED7SEG_TRAFFICLIGHT--;
}
