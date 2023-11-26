#include <FreeRTOS.h>
#include <task.h>

#include "TaskB.h"
#include <stdio.h>

void TaskB( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;

    int i = 0;

    for( ; ; )
    {
        /* Example Task Code */
        vTaskDelay( 1000 ); /* delay 1000 ticks */
        printf("TaskB: %d\n", i++);
    }
}
