#pragma once
#include <stdbool.h> //boolean type
#define MAXPLACES 500

#include "queue.h"

typedef struct cinema_s cinema_t;

cinema_t * cinema_new(queue_t * line);
void cinema_delete(cinema_t * self);

bool cinema_isFull(const cinema_t * self);
bool cinema_isEmpty(const cinema_t * self);
