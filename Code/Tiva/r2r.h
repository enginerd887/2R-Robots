/**
 * @file r2r.h
 * @brief Main R2R library header
 *
 * This file contains all the prototypes for the R2R Project
 *
 * @author Benjamen Lim
 * @author Huan Weng
 *
 */

#ifndef R2R_H_
#define R2R_H_

#include "includes.h"
#include "System.h"
#include "Encoder.h"
#include "Motor.h"
#include "PositionControl.h"
#include "CurrentControl.h"
#include "Adc.h"


/**
 * @brief Initializes the default connections for the R2R project
 *
 * This function initializes all peripherals and GPIO pins.
 * This function only needs to be called in main once.
 *
 * Example:
 *
 *     int main() {
 *			r2rDefaultInit();
 *     }
 *
 * @param Void
 * @return Void
 */
extern void r2rDefaultInit(void);

/**
 * @brief Updates the sensor readings
 *
 * When called this function updates the encoder readings. Other sensor reading functions can also be added here.
 *
 * Example:
 *
 *     int main() {
 *			sensorUpdate();
 *     }
 *
 * @param Void
 * @return Void
 */
extern void sensorUpdate()

/**
 * @brief Initializes custom timers
 *
 * This function initializes timers 6 and 7 at preset frequencies as defined in r2r.c
 *
 *
 * @param Void
 * @return Void
 */
extern void customTimersInit(void);

/**
 * @brief Custom timer 6
 *
 * This function executes at the rate set by TIMER_6_FREQ set in r2r.c
 * This function does not have to be called anywhere. This function does not return any values
 *
 * Example:
 *
 *		 void TIMER6IntHandler() {
 *	
 *			// add custom controller code here
 *
 * 		 }
 *
 *
 *
 * @param Void
 * @return Void
 */

extern void TIMER6IntHandler(void);

/**
 * @brief Custom timer 7
 *
 * This function executes at the rate set by TIMER_6_FREQ set in r2r.c
 * This function does not have to be called anywhere. 
 *
 * @param Void
 * @return Void
 */
extern void TIMER7IntHandler(void);



#endif /* R2R_H_ */
