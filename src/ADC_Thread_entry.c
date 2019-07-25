/***********************************************************************************************************************
* File Name    : blinky_thread_entry.c
* Description  : This is a very simple example application that blinks all the LEDs on a board.
***********************************************************************************************************************/

#include <adc_thread.h>
#include "adc_thread_handler.h"

uint16_t adc_value = 0;

void adc_thread_entry(void)
{
    Start_ADC(&adc_obj);

    while (1)
    {
        Read_ADC(&adc_obj, &adc_value);
        tx_thread_sleep(DAFAULT_THREAD_SLEEP_MS);
        Send_Readings(adc_value);
    }
}
