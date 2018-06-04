/**
 * @file Motor.h
 *
 * This file contains all motor-related functions, such as initialization and setting speeds
 *
 * @author Benjamen Lim
 * @author Huan Weng
 * @author Blake Strebel
 *
 */

#ifndef MOTOR_H_
#define MOTOR_H_

// error messages
#define MOTOR_SPINNING_TOO_FAST 10
#define MOTOR_TOO_HOT 11

// limits
#define TEMP_LIMIT 50 // in degrees C
#define MAX_SPEED 10 // in rev/s


#define PWMPERIOD 4000


/* MOTOR 1 HALL SENSOR PINS */
#define M1H_PERIPH SYSCTL_PERIPH_GPIOL
#define M1H_PORT GPIO_PORTL_BASE // IF YOU CHANGE THIS PORT YOU MUST CHANGE THE INT HANDLER IN tm4c1294ncpdt_startup_css.c
#define M1H_PIN_A GPIO_PIN_5
#define M1H_PIN_B GPIO_PIN_6
#define M1H_PIN_C GPIO_PIN_7
#define M1H_PINS (M1H_PIN_A | M1H_PIN_B | M1H_PIN_C)

/* MOTOR 1 CONTROL PINS */
#define M1_INL_PERIPH_A SYSCTL_PERIPH_GPIOP
#define M1_INL_PORT_A GPIO_PORTP_BASE
#define M1_INL_PIN_A GPIO_PIN_1
#define M1_INL_PERIPH_B SYSCTL_PERIPH_GPIOD
#define M1_INL_PORT_B GPIO_PORTD_BASE
#define M1_INL_PIN_B GPIO_PIN_5
#define M1_INL_PERIPH_C SYSCTL_PERIPH_GPIOD
#define M1_INL_PORT_C GPIO_PORTD_BASE
#define M1_INL_PIN_C GPIO_PIN_6

/* MOTOR 1 COMMUTATION DATA */
#define M1_HALLSTATE_0 (M1H_PIN_A | M1H_PIN_B)
#define M1_HALLSTATE_1 M1H_PIN_A
#define M1_HALLSTATE_2 (M1H_PIN_A | M1H_PIN_C)
#define M1_HALLSTATE_3 M1H_PIN_C
#define M1_HALLSTATE_4 (M1H_PIN_B | M1H_PIN_C)
#define M1_HALLSTATE_5 M1H_PIN_B

/* MOTOR 2 HALL SENSOR PINS */
#define M2H_PERIPH SYSCTL_PERIPH_GPION
#define M2H_PORT GPIO_PORTN_BASE // IF YOU CHANGE THIS PORT YOU MUST CHANGE THE INT HANDLER IN tm4c1294ncpdt_startup_css.c
#define M2H_PIN_A GPIO_PIN_0
#define M2H_PIN_B GPIO_PIN_1
#define M2H_PIN_C GPIO_PIN_2
#define M2H_PINS (M2H_PIN_A | M2H_PIN_B | M2H_PIN_C)

/* MOTOR 2 CONTROL PINS */
#define M2_INL_PERIPH_A SYSCTL_PERIPH_GPIOP
#define M2_INL_PORT_A GPIO_PORTP_BASE
#define M2_INL_PIN_A GPIO_PIN_2
#define M2_INL_PERIPH_B SYSCTL_PERIPH_GPIOP
#define M2_INL_PORT_B GPIO_PORTP_BASE
#define M2_INL_PIN_B GPIO_PIN_3
#define M2_INL_PERIPH_C SYSCTL_PERIPH_GPIOP
#define M2_INL_PORT_C GPIO_PORTP_BASE
#define M2_INL_PIN_C GPIO_PIN_0

/* MOTOR 2 COMMUTATION DATA */
#define M2_HALLSTATE_0 (M2H_PIN_A | M2H_PIN_B)
#define M2_HALLSTATE_1 M2H_PIN_A
#define M2_HALLSTATE_2 (M2H_PIN_A | M2H_PIN_C)
#define M2_HALLSTATE_3 M2H_PIN_C
#define M2_HALLSTATE_4 (M2H_PIN_B | M2H_PIN_C)
#define M2_HALLSTATE_5 M2H_PIN_B


extern void M1HIntHandler(void);
extern void M2HIntHandler(void);

/**
 * @brief Sets the PWM value to motor 1
 *
 * @param pwmValue The pwmValue ranges from 0 to the pwm period. 
 * @return Void
 *
 */
extern void motor1PWM(int pwm1, int pwm2, int pwm3);

/**
 * @brief Sets the PWM value to motor 2
 *
 * @param pwmValue The pwmValue ranges from 0 to the pwm period. 
 * @return Void
 *
 */
extern void motor2PWM(int pwm1, int pwm2, int pwm3);


/**
 * @brief Sets the PWM value and direction to motor 1
 *
 * @param control The pwmValue ranges from -maximum pwm period to the positive period. The default pwm period is 320 SysClk cycles
 * @return Void
 *
 */
extern void motor1ControlPWM(int control);

/**
 * @brief Sets the PWM value and direction to motor 2
 *
 * @param control The pwmValue ranges from -maximum pwm period to the positive period. The default pwm period is 320 SysClk cycles
 * @return Void
 *
 */
extern void motor2ControlPWM(int control);


/**
* @brief Initializes the GPIO pins for the motor
* 
* Initializes the direction, brake, and halt pins for the motor in 1x PWM mode
* 
* @param Void
* @return Void
*/
extern void motorInit(void);

void M1_INL_WRITE(int a, int b, int c);
void M2_INL_WRITE(int a, int b, int c);

int getmotor1PWM(void);
int getmotor2PWM(void);

int32_t getmotor1HALLS(void);
int32_t getmotor2HALLS(void);



/**
 * Brakes the motor and kills the pwm signal by pulling down the enable line.
 *
 *
 * @param Void
 * @return Void
 */
extern void shutdownNow(void);

/**
 * Function to check for all safety limits and kills the motors if a fault is detected. 
 * Function must be called each time
 *
 *
 * @param Void
 * @return Void
 */
extern void motorSafetyCheck(void);

/**
 * @brief Initializes the SPI channels for the motor drivers
 *
 * Initializes SSI1~2 and their corresponding GPIO pins
 *
 * @param Void
 * @return Void
 */
extern void MotorSPIInit(void);



/**
 * @brief Initializes the SPI commands to set the motor's configuration for 1x PWM mode.
 * @param Void
 * @return Void
 */
extern void motorDriverInit(void);


/**
 * @brief Initializes PWM
 *
 * Initialize PWM on PF0 (motor 1) and PG0 (motor 2), and the default period if 9600 SysClk
 * cycles or 12500Hz
 *
 * @param Void
 * @return Void
 */
extern void pwmInit(void);




/**
 * @brief Brakes motor 1
 *
 * @param Void
 * @return Void
 */
extern void motor1Brake(void);

/**
 * @brief Brakes motor 2
 *
 * @param Void
 * @return Void
 */
extern void motor2Brake(void);



/**
 * @brief Checks the error pins and returns a value based on the state of the pin
 *
 * Returns 0 on no error, 1 on motor 1 error, and 2 on motor 2 error
 *
 * @param Void 
 * @return Void
 *
 */
extern int motorError(void); 



#endif /* MOTOR_H_ */
