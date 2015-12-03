#ifndef __PROJ_LAB6_BEHAVIOR
#define __PROJ_LAB6_BEHAVIOR

void printArray(char *[], int);

void lengthOrder(char * [], int , int arr[10]); //lengthorder
char *getLongest(char * [], int); //longest
char *getShortest(char * [], int); //shortest
void fillRandom(char * [], int, int); //random
void swapShLn(char * [], int); //swap
void lessThan(char * [], int, int, char *tempStrArrForLessThan []); //lessthan
void moreThan(char * [], int, int, char *tempStrArrForMoreThan []); //morethan
void wordsCount(char * [], int, int []); //words
void findNumInStr(char * [], int, int); //findnum
void findNumInAllStrings(char * [], int); //findAll

#endif