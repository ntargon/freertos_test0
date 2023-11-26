#include <FreeRTOS.h>
#include <task.h>

#include "TaskA.h"
#include <stdio.h>

void TaskA( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;

    int i = 0;

    for( ; ; )
    {
        /* Example Task Code */
        vTaskDelay( 1000 ); /* delay 1000 ticks */
        printf("TaskA: %d\n", i++);
    }
}
