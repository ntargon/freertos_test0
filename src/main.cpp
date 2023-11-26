#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

#include <stdio.h>

/*
FreeRTOSのAPIでt-kernelやuITRONのメッセージバッファを模擬するには

## 案1
Queueとmutexを用意する。
書き込み時には、mutexを獲得する。
mutex取得できないならまち。
獲得できたら、書き込む。キューがいっぱいならここでも待ちが発生する。
その後mutexの開放。

デメリットは、タイムアウトの指定が同じようにできないところ
mutexの待ちとキューの待ちがダブルで乗る可能性がある

## 案2
Queueとmutexとcounting semaphoreを用意する
counting semaphoreの獲得。ここで待ちが発生する。
優先度継承のmutexを獲得。ここでの待ち時間はほぼ0とみなせる。
Queueに書き込み。カウンティングセマフォでキューに空きがあることは確定しているので、待ちは発生しない。
mutexの開放。

受信側で、受信後にcounting semaphoreを開放する。

*/

void highPriorityTask( void * parameters );

void exampleTask( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;

    int i = 0;

    for( ; ; )
    {
        /* Example Task Code */
        vTaskDelay( 1000 ); /* delay 1000 ticks */
        printf("low: %d\n", i++);

        if (i == 10) {
            xTaskCreate( highPriorityTask,
                            "high",
                            configMINIMAL_STACK_SIZE,
                            NULL,
                            configMAX_PRIORITIES - 1,
                            NULL);
        }
    }
}


void highPriorityTask( void * paramters )
{
    ( void ) paramters;

    int i = 0;
    for( ; ; )
    {
        vTaskDelay( 500 );
        printf("high: %d\n", i++);
    }
}

int main( void )
{
    printf( "Example FreeRTOS Project\n" );

    xTaskCreate( exampleTask,
                       "example",
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
