/* generated thread source file - do not edit */
#include "PWM_Thread.h"

TX_THREAD PWM_Thread;
void PWM_Thread_create(void);
static void PWM_Thread_func(ULONG thread_input);
static uint8_t PWM_Thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.PWM_Thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_PWM_Timer) && !defined(SSP_SUPPRESS_ISR_AGT0)
SSP_VECTOR_DEFINE_CHAN(agt_int_isr, AGT, INT, 0);
#endif
#endif
static agt_instance_ctrl_t PWM_Timer_ctrl;
static const timer_on_agt_cfg_t PWM_Timer_extend =
{ .count_source = AGT_CLOCK_PCLKB,
  .agto_output_enabled = false,
  .agtio_output_enabled = false,
  .output_inverted = false,
  .agtoa_output_enable = false,
  .agtob_output_enable = false, };
static const timer_cfg_t PWM_Timer_cfg =
{ .mode = TIMER_MODE_PERIODIC,
  .period = 1000,
  .unit = TIMER_UNIT_PERIOD_USEC,
  .channel = 0,
  .autostart = true,
  .p_callback = NULL,
  .p_context = &PWM_Timer,
  .p_extend = &PWM_Timer_extend,
  .irq_ipl = (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t PWM_Timer =
{ .p_ctrl = &PWM_Timer_ctrl, .p_cfg = &PWM_Timer_cfg, .p_api = &g_timer_on_agt };
TX_QUEUE pwm_queue;
static uint8_t queue_memory_pwm_queue[20];
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void PWM_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_pwm_queue;
    err_pwm_queue = tx_queue_create (&pwm_queue, (CHAR *) "PWM_Queue", 1, &queue_memory_pwm_queue,
                                     sizeof(queue_memory_pwm_queue));
    if (TX_SUCCESS != err_pwm_queue)
    {
        tx_startup_err_callback (&pwm_queue, 0);
    }

    UINT err;
    err = tx_thread_create (&PWM_Thread, (CHAR *) "PWM_Thrd", PWM_Thread_func, (ULONG) NULL, &PWM_Thread_stack, 1024, 2,
                            2, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&PWM_Thread, 0);
    }
}

static void PWM_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    PWM_Thread_entry ();
}
