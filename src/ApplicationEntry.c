#include <FreeRTOS.h>
#include <task.h>

#include "ApplicationEntry.h"
#include <stdio.h>
#include <TaskA.h>
#include <TaskB.h>

void ApplicationEntry(void)
{
    printf("Application Entry\n");

    xTaskCreate( TaskA,
                       "TaskA",
                       configMINIMAL_STACK_SIZE,
                       NULL,
                       configMAX_PRIORITIES - 2,
                       NULL);
    xTaskCreate( TaskB,
                       "TaskB",
                       configMINIMAL_STACK_SIZE,
                       NULL,
                       configMAX_PRIORITIES - 2,
                       NULL);

    /* Start the scheduler. */
    vTaskStartScheduler();

    for( ; ; )
    {
        /* Should not reach here. */
    }
}

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
     * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;
}
