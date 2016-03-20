#pragma once

#include <stdlib.h> // size_t

#define USERINPUT_MAX 2000 // User input buffer size.

// Alert function. Prints an alert.
typedef void (*alertCB)();

// Comparison function. Compares 2 chars and calls alert function.
typedef void (*checkCB)(const char l, const char r);

// Main function. Does something interesting.
void check(const char *str, const size_t size, checkCB checkSample);

// Set of check functions.
void check1(const char l, const char r);
void check2(const char l, const char r);
