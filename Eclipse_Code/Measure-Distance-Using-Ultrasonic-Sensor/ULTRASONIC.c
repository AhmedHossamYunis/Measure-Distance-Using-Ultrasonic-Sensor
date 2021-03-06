/*
 ============================================================================
 Name        : ULTRASONIC.c
 Data        : 29 - 5 -2022
 Author      : Ahmed_Hossam
 Description : Ultrasonic Driver
 ============================================================================
 */

#include "ULTRASONIC.h"
#include "ICU.h"
#include "gpio.h"
#include <util/delay.h>
/*******************************************************************************
 *                           Static Variables                                  *
 *******************************************************************************/

static volatile uint8  g_edgeCount   = 0;
static volatile uint16 g_timeHigh    = 0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description:
 * This is the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 * */
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*Clear timer counter register to start measurements. */
		ICU_clearTimerValue();

		/*Detect Falling edge*/
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if(g_edgeCount == 2)
	{
		/*Store period high value. */
		g_timeHigh = ICU_getInputCaptureValue();

		/*Clear Timer counter register*/
		ICU_clearTimerValue();

		/*Detect Rising edge*/
		ICU_setEdgeDetectionType(RISING_EDGE);

		g_edgeCount = 0;
	}
}


/*
 *  Description:
 *	Initialize the ICU driver as required.
 *	Setup the ICU call back function.
 *	Setup the direction for the trigger pin as output pin through the GPIO driver.
 *
 */
void Ultrasonic_init(void)
{
	/* Configure the structure for ICU Driver. */
	ICU_ConfigType config = {F_CPU_8, RISING_EDGE};

	/*Initialize ICU Driver. */
	ICU_init(&config);

	/* Set the Call back function pointer in the ULTRASONIC driver */
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* Setup the direction for the trigger pin as output pin through the GPIO driver.*/
	GPIO_setupPinDirection(ULTRA_TRIG_PORT_ID, ULTRA_TRIG_PIN_ID, PIN_OUTPUT);

}



/*
 * Description:
 * Send the Trigger pulse to the ultrasonic.
 * */
static void Ultrasonic_Trigger(void)
{
	/* Clear trigger pin */
	GPIO_writePin(ULTRA_TRIG_PORT_ID, ULTRA_TRIG_PIN_ID, LOGIC_LOW);
	_delay_us(2);
	/* Set up triger pin as high state for 10 micro second. */
	GPIO_writePin(ULTRA_TRIG_PORT_ID, ULTRA_TRIG_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRA_TRIG_PORT_ID, ULTRA_TRIG_PIN_ID, LOGIC_LOW);
}

/*
 * Description:
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment.
 * */
uint16 Ultrasonic_readDistance(void)
{


	/*Send the trigger pulses*/
	Ultrasonic_Trigger();

	/*Calculate the distance*/
	return ((float)(g_timeHigh/2)/(28.8));

}



