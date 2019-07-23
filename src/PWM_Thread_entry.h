/*
 * PWM_Thread_entry.h
 *
 *  Created on: 12/07/2019
 *
 * - 12-jul-2019  Francisco Govea
 *   - Create initial file
 */

#ifndef PWM_THREAD_ENTRY_H_
#define PWM_THREAD_ENTRY_H_

/**
 * Function: Generate_Signal
 *
 * Function that will generate the signal to be control the motor.
 *
 * @param pwm_instance Instance of the object generated of the timer.
 * @param pwm_value Variable read from the ADC which will modify the signal.
 * @return Returns 0 if the signal was successfully generated or another number if it failed.
 */
uint16_t Generate_Signal(const timer_instance_t * pwm_instance, uint16_t pwm_value);

/**
 * Function: Start_Timer
 *
 * Function to start the timer for the PWM signal.
 * @param pwm_instance Instance of the object generated of the timer.
 */
void Start_Timer(const timer_instance_t * pwm_instance, uint16_t pwm_value);

/**
 * Function:
 *
 * Function to stop the timer that generates the PWM signal.
 * @param pwm_instance Instance of the object generated of the timer.
 */
void Stop_Timer(const timer_instance_t * pwm_instance);

/**
 * Function: Receive_Message
 *
 * Function that will handle the messages received from other threads.
 */
void Receive_Message(void);

/**Variable to store the value read from incoming messages*/
uint16_t readings;

#endif /* PWM_THREAD_ENTRY_H_ */
