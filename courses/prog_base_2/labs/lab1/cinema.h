#pragma once
#include <stdbool.h> //boolean type
#define MAXPLACES 30000
#define MIN_PER_HR 60.0
#include "queue.h"

typedef struct cinema_s cinema_t;

cinema_t * cinema_new(queue_t * line);
void cinema_delete(cinema_t * self);

bool cinema_isFull(const cinema_t * self);
bool cinema_isEmpty(const cinema_t * self);
bool cinema_newvisitor(double x);
