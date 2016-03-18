#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "cinema.h"

int main(void)
{
    queue_t * line = queue_new();
    cinema_t * cinema = cinema_new(line);

    printf("Is cinema full? Answer: %d\n", cinema_isFull(cinema));
    printf("Is cinema empty? Answer: %d\n", cinema_isEmpty(cinema));
    puts("-----------------");
    puts("Let`s begin testing things!");
    puts("-----------------");

    for(int i = 0; i < 30; i++) {

    }

    return (0);
}
