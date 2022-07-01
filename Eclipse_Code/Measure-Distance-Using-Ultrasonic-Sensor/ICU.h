/*
 ============================================================================
 Name        : ICU.h
 Data        : 26 - 5 -2022
 Author      : Ahmed_Hossam
 Description : Input Capture Unit Driver
 ============================================================================
 */


#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ICU_PORT_ID   PORTD_ID
#define ICU_PIN_ID    PIN6_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	NO_CLOCK, F_CPU_1, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024, EX_CLOCK_T1_FALLING, EX_CLOCK_T1_RISING
}ICU_Clock;

typedef enum{
	FALLING_EDGE, RISING_EDGE
}ICU_EdgeType;

typedef struct{
	ICU_Clock clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */

void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_DeInit(void);





#endif /* ICU_H_ */
