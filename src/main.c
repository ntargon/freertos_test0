#include "ApplicationEntry.h"

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


int main( void )
{
    printf( "Example FreeRTOS Project\n" );

    ApplicationEntry();

    /* Should not reach here. */

    return 0;
}
