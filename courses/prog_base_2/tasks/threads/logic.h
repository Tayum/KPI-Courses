#pragma once

#include "mutex.h"

#define SHARED_ARR_SIZE 4
#define SLEEP_TIME 80
#ifndef TRUE
    #define TRUE 1
#endif

typedef struct sharedObj_s
{
    unsigned arr[SHARED_ARR_SIZE];
    mutex_t *mu;
} sharedObj_t;

void *producerFunc(void *args);
void *consumerFunc(void *args);
void *drawInfo(void *args);
