/*
 * PWM_Thread_entry.c
 *
 *  Created on: 12/07/2019
 *
 * - 12-jul-2019  Francisco Govea
 *   - Create initial file
 *
 * - 22-jul-2019  Francisco Govea
 *   - Add improvements to PWM
 */

#include <PWM_Thread.h>
#include <ADC_Thread.h>
#include "pwm_thread_handler.h"

/** For further information refer to PWM_Thread_entry.h*/
uint16_t readings = 0;

/** For further information refer to PWM_Thread_entry.h*/
uint16_t duty_cycle = DEFAULT_DUTY_CYCLE;

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Receive_Message(void)
{
    tx_queue_receive(&adc_queue, &readings, TX_NO_WAIT);
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
uint16_t Generate_Signal(const timer_instance_t * pwm_instance)
{
    if(NULL != pwm_instance)
    {
        pwm_instance->p_api->start(pwm_instance->p_ctrl);
        duty_cycle = Parse_PWM_Data(readings);
        pwm_instance->p_api->dutyCycleSet(pwm_instance->p_ctrl, duty_cycle, TIMER_PWM_UNIT_PERCENT, DEFAULT_PIN);
    }
    return 1;
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Start_Timer(const timer_instance_t * pwm_instance)
{
    if(NULL != pwm_instance)
    {
        pwm_instance->p_api->open(pwm_instance->p_ctrl, pwm_instance->p_cfg);
    }
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
void Stop_Timer(const timer_instance_t * pwm_instance)
{
    if(NULL != pwm_instance)
    {
        pwm_instance->p_api->stop(pwm_instance->p_ctrl);
        pwm_instance->p_api->close(pwm_instance->p_ctrl);
    }
}

/**
 * Refer to PWM_Thread_entry.h for further information.
 */
uint16_t Parse_PWM_Data(uint16_t value_read)
{
    static uint16_t parsed_data = 0;

    if(MAX_ADC_VALUE >= value_read)
    {
        parsed_data = (uint16_t)((value_read * MAX_PERCENT) / MAX_ADC_VALUE);
    }
    return parsed_data;
}
