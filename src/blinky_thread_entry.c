/*
#include "blinky_thread.h"

void blinky_thread_entry(void)
{
	const uint32_t threadx_tick_rate_Hz = 100;
    const uint32_t freq_in_hz = 2;
    const uint32_t delay = threadx_tick_rate_Hz/freq_in_hz;

    bsp_leds_t leds;

    ioport_level_t level = IOPORT_LEVEL_HIGH;

    R_BSP_LedsGet(&leds);

    if (0 == leds.led_count)
    {
        while(1);
    }

    while (1)
    {
        if(IOPORT_LEVEL_LOW == level)
        {
            level = IOPORT_LEVEL_HIGH;
        }
        else
        {
            level = IOPORT_LEVEL_LOW;
        }
        for(uint32_t i = 0; i < leds.led_count; i++)
        {
            g_ioport.p_api->pinWrite(leds.p_leds[i], level);
        }
        tx_thread_sleep (delay);
    }
}
*/
