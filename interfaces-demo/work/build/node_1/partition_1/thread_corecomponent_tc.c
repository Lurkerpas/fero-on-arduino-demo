#include "thread_corecomponent_tc.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"

#include "partition_1_interface.h"

extern rtems_id corecomponent_tc_Global_Queue;

static void update_execution_time_data(const uint64_t thread_execution_time) {
    if(thread_execution_time < threads_info[corecomponent_tc].min_thread_execution_time)
    {
        threads_info[corecomponent_tc].min_thread_execution_time = thread_execution_time;
    }

    if(thread_execution_time > threads_info[corecomponent_tc].max_thread_execution_time)
    {
        threads_info[corecomponent_tc].max_thread_execution_time = thread_execution_time;
    }

    threads_info[corecomponent_tc].mean_thread_execution_time = threads_info[corecomponent_tc].mean_thread_execution_time +
            ((double)thread_execution_time - threads_info[corecomponent_tc].mean_thread_execution_time) /
            ((double)threads_info[corecomponent_tc].execution_time_counter + 1);

    threads_info[corecomponent_tc].execution_time_counter++;
}

rtems_task corecomponent_tc_job(rtems_task_argument unused)
{

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadCorecomponent_TcRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(corecomponent_tc_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            corecomponent_tc_sender_pid = (asn1SccPID)request.m_sender_pid;

            const uint64_t time_before_execution =
                (uint64_t)Timer_Apbctrl1_getCounterValue(&timer_2) << 32 | Timer_Apbctrl1_getCounterValue(&timer_1);

            call_corecomponent_tc((const char*)request.m_data, request.m_length);

            const uint64_t time_after_execution =
                (uint64_t)Timer_Apbctrl1_getCounterValue(&timer_2) << 32 | Timer_Apbctrl1_getCounterValue(&timer_1);
            threads_info[corecomponent_tc].thread_execution_time = time_before_execution - time_after_execution;

            update_execution_time_data(threads_info[corecomponent_tc].thread_execution_time);
        }
    }
}
