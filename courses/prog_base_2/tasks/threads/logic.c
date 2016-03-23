#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "logic.h"

// private:
bool _checkAscending(unsigned *arr)
{
    for(int i = 0; i < SHARED_ARR_SIZE - 1; i++)
    {
        if(arr[i] >= arr[i+1])
            return (false);
    }
    return (true);
}

// public:
void *producerFunc(void *args)
{
    sharedObj_t *shObj = (sharedObj_t *)args;
    time_t t;
    srand((unsigned)time(&t));
    int index = 0;
    while(TRUE)
    {
        mutex_lock(shObj->mu);
        shObj->arr[index] = rand()%10;
        index++;
        index%=4;
        mutex_unlock(shObj->mu);
        Sleep(SLEEP_TIME);
    }
    return (NULL);
}

void *consumerFunc(void *args)
{
    sharedObj_t *shObj = (sharedObj_t *)args;
    while(TRUE)
    {
        mutex_lock(shObj->mu);
        if(_checkAscending(shObj->arr))
        {
            puts("Array in ascending order!\n"
                 "See you later!\n"
                 "Wait ~3 seconds.");
            // Sleep to show user result of consumerFunc.
            // If Sleep will be missing here - "cls" function
            // will clear result of consumerFunc.
            Sleep(SLEEP_TIME + 3000);
        }
        mutex_unlock(shObj->mu);
        Sleep(SLEEP_TIME);
    }
    return (NULL);
}

void *drawInfo(void *args)
{
    sharedObj_t *shObj = (sharedObj_t *)args;
    while(TRUE)
    {
        mutex_lock(shObj->mu);
        system("cls");
        printf("Array: %4i%4i%4i%4i\n", shObj->arr[0], shObj->arr[1], shObj->arr[2], shObj->arr[3]);
        printf("A process can take a while...\n\n");
        fflush(stdout);
        mutex_unlock(shObj->mu);
        Sleep(SLEEP_TIME);
    }
    return (NULL);
}
