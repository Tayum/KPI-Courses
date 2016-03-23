#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "mutex.h"
#include "thread.h"
#include "logic.h"

int main()
{
    SetConsoleTitleA("Gonchar Maxim KP-51 Threads");
    // Shared data structure.
    sharedObj_t sharedObject = { {0,0,0,0} };
    sharedObject.mu = mutex_new();
    // Create and run primary threads/
    thread_t *producer = thread_create_args(producerFunc, &sharedObject);
    thread_t *draw = thread_create_args(drawInfo, &sharedObject);
    thread_t *consumer = thread_create_args(consumerFunc, &sharedObject);
    // Wait here.
    _getch();
    // Delete threads and free allocated memory.
    thread_free(draw);
    thread_free(producer);
    thread_free(consumer);
    // Delete mutex.
    mutex_free(sharedObject.mu);
    // End of the program
    puts("End of the program.");
    return (0);
}
