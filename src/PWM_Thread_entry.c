/** File: pwm_thread_handler.h
 *
 * - 22-jul-2019  Francisco Govea
 *   - Add improvements to PWM
 */

#include "pwm_thread.h"
#include "pwm_thread_handler.h"

/**
 * PWM_Thread entry function  that will execute periodically.
 */
void pwm_thread_entry(void)
{
    Start_Timer(&pwm_timer);
    while (1)
    {
        Receive_Message();
        Generate_Signal(&pwm_timer);
        tx_thread_sleep (100);
    }
}
