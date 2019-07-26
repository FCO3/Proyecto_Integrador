/*
 * PWM_Thread_entry.c
 *
 *  Created on: 12/07/2019
 *
 * - 12-jul-2019  Francisco Govea
 *   - Create initial file
 */

#include <PWM_Thread.h>
#include "PWM_Thread_entry.h"

/** For further information refer to PWM_Thread_entry.h*/
uint16_t readings = 0;

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Receive_Message(void)
{

    tx_queue_receive(&pwm_queue, &readings, TX_NO_WAIT);
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
uint16_t Generate_Signal(const timer_instance_t * pwm_instance, uint16_t pwm_value)
{
    pwm_instance->p_api->close(pwm_instance->p_ctrl);
    (void)pwm_value;
    return 1;
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Start_Timer(const timer_instance_t * pwm_instance, uint16_t pwm_value)
{
    pwm_instance->p_api->open(pwm_instance->p_ctrl, pwm_instance->p_cfg);
    pwm_instance->p_api->periodSet(pwm_instance->p_ctrl, pwm_value,TIMER_UNIT_PERIOD_USEC);
    pwm_instance->p_api->start(pwm_instance->p_ctrl);
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Stop_Timer(const timer_instance_t * pwm_instance)
{
    pwm_instance->p_api->stop(pwm_instance->p_ctrl);
}
