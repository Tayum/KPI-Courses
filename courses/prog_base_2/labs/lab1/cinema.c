#include <stdlib.h>

#include "cinema.h"

struct cinema_s {
    int places;
    queue_t * line;
};

cinema_t * cinema_new(queue_t * line)
{
    cinema_t * out = (cinema_t *) malloc(sizeof(cinema_t));
    out->places = MAXPLACES;
    out->line = line;
    return (out);
}

void cinema_delete(cinema_t * self)
{
    queue_delete(self->line);
    free(self);
}

bool cinema_isFull(const cinema_t * self)
{
    return (self->places == MAXPLACES);
}

bool cinema_isEmpty(const cinema_t * self)
{
    return (0 == self->places);
}
