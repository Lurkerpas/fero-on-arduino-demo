#include "thread_function1_trigger.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"

#include "partition_1_interface.h"

extern rtems_id function1_trigger_Global_Queue;


extern rtems_name generate_new_partition_timer_name();

rtems_interval function1_trigger_Timer_NextWakeupTicks = 0;
rtems_interval function1_trigger_Timer_IntervalTicks = 0;
rtems_id function1_trigger_Timer;

void function1_trigger_Timer_Callback(rtems_id unused_id, void* unused_data);

static inline void function1_trigger_Timer_ScheduleNextTick() {
    function1_trigger_Timer_NextWakeupTicks += function1_trigger_Timer_IntervalTicks;
    rtems_interval delta = function1_trigger_Timer_NextWakeupTicks - rtems_clock_get_ticks_since_boot();
    rtems_timer_fire_after(function1_trigger_Timer,
                           delta,
                           function1_trigger_Timer_Callback,
                           NULL);
}

void function1_trigger_Timer_Callback(rtems_id unused_id, void* unused_data)
{
    struct ThreadFunction1_TriggerRequest request = {0};
    rtems_message_queue_send(function1_trigger_Global_Queue,
                             &request,
                             sizeof(struct ThreadFunction1_TriggerRequest ));
    function1_trigger_Timer_ScheduleNextTick();
}

static void update_execution_time_data(const uint64_t thread_execution_time) {
    if(thread_execution_time < threads_info[function1_trigger].min_thread_execution_time)
    {
        threads_info[function1_trigger].min_thread_execution_time = thread_execution_time;
    }

    if(thread_execution_time > threads_info[function1_trigger].max_thread_execution_time)
    {
        threads_info[function1_trigger].max_thread_execution_time = thread_execution_time;
    }

    threads_info[function1_trigger].mean_thread_execution_time = threads_info[function1_trigger].mean_thread_execution_time +
            ((double)thread_execution_time - threads_info[function1_trigger].mean_thread_execution_time) /
            ((double)threads_info[function1_trigger].execution_time_counter + 1);

    threads_info[function1_trigger].execution_time_counter++;
}

rtems_task function1_trigger_job(rtems_task_argument unused)
{
    function1_trigger_Timer_IntervalTicks = RTEMS_MILLISECONDS_TO_TICKS( 1000);
    rtems_name name = generate_new_partition_timer_name();
    const rtems_status_code timerCreationStatus = rtems_timer_create(name, &function1_trigger_Timer);
    assert(timerCreationStatus == RTEMS_SUCCESSFUL);
    function1_trigger_Timer_ScheduleNextTick();

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadFunction1_TriggerRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(function1_trigger_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            function1_trigger_sender_pid = (asn1SccPID)request.m_sender_pid;

            const uint64_t time_before_execution =
                (uint64_t)Timer_Apbctrl1_getCounterValue(&timer_2) << 32 | Timer_Apbctrl1_getCounterValue(&timer_1);

            call_function1_trigger((const char*)request.m_data, request.m_length);

            const uint64_t time_after_execution =
                (uint64_t)Timer_Apbctrl1_getCounterValue(&timer_2) << 32 | Timer_Apbctrl1_getCounterValue(&timer_1);
            threads_info[function1_trigger].thread_execution_time = time_before_execution - time_after_execution;

            update_execution_time_data(threads_info[function1_trigger].thread_execution_time);
        }
    }
}
