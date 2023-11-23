#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

#include <stdio.h>

static StaticTask_t exampleTaskTCB;
static StackType_t exampleTaskStack[ configMINIMAL_STACK_SIZE ];

void exampleTask( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;

    for( ; ; )
    {
        /* Example Task Code */
        vTaskDelay( 100 ); /* delay 100 ticks */
    }
}

int main( void )
{
    printf( "Example FreeRTOS Project\n" );

    xTaskCreateStatic( exampleTask,
                       "example",
                       configMINIMAL_STACK_SIZE,
                       NULL,
                       configMAX_PRIORITIES - 1,
                       exampleTaskStack,
                       &exampleTaskTCB );

    /* Start the scheduler. */
    vTaskStartScheduler();

    for( ; ; )
    {
        /* Should not reach here. */
    }

    return 0;
}

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
     * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;
}
