/*
 ============================================================================
 Name        : Mini_Project4.c
 Data        : 29 - 5 -2022
 Author      : Ahmed_Hossam
 Description : Implement the following system to measure the distance using ultrasonic sensor
			   HC-SR04
 ============================================================================
 */
#include "LCD.h"
#include "ULTRASONIC.h"
#include <avr/interrupt.h>


int main(void)
{
	uint16 distance = 0;

	/*Enable Global interrupt*/
	sei();
	/*Initialize ULTRASONIC Driver */

	Ultrasonic_init();
	/*Initialize LCD Driver*/
	LCD_init();

	LCD_displayString("Distance:  ");

	while(1)
	{
		distance = Ultrasonic_readDistance();

		LCD_setCurser(0,10);

		LCD_intgerToString(distance);

		if(distance >= 100)
		{
			/*Do Nothing*/
		}
		else
		{
			LCD_displayString(" ");
		}
		LCD_displayStringRowColumn(0,13,"cm");


	}
}
