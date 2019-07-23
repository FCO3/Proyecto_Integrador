/*
 * ADC_Thread_entry.h
 *
 *  Created on: 12/07/2019
 *
 * - 12-jul-2019  Francisco Govea
 *   - Create initial file.
 *
 */

#include <ADC_Thread.h>
#include "ADC_Thread_entry.h"

/**
 * Refer to ADC_Thread_entry.h for further information.
 */
uint16_t adc_value = 0;

/**
 * Function: ADC_Thread_entry
 *
 * Main function where the thread will start running.
 */
void ADC_Thread_entry(void)
{
    Start_ADC(&adc_obj);
    Read_ADC(&adc_obj, &adc_value);
    Close_ADC(&adc_obj);
    tx_thread_sleep(DAFAULT_THREAD_SLEEP_MS);
    Send_Readings(adc_value);
}

/**
 * Refer to ADC_Thread_entry.h for further information.
 */
void Start_ADC(const adc_instance_t * adc_instance)
{
    adc_instance->p_api->open(adc_instance->p_ctrl, adc_instance->p_cfg);
}

/**
 * Refer to ADC_Thread_entry.h for further information.
 */
void Close_ADC(const adc_instance_t * adc_instance)
{
    adc_instance->p_api->close(adc_instance->p_ctrl);
}

/**
 * Refer to ADC_Thread_entry.h for further information.
 */
uint16_t Send_Readings(uint16_t value)
{
    return (uint16_t)tx_queue_send(&adc_queue, &value, TX_NO_WAIT);
}

/**
 * Refer to ADC_Thread_entry.h for further information.
 */
void Read_ADC(const adc_instance_t * adc_instance, uint16_t * adc_val)
{
    adc_instance->p_api->read(adc_instance->p_ctrl, ADC_REG_CHANNEL_0, adc_val);
}
