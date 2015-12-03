#include "behavior.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int sortfunc(const void * a, const void * b)
{
	return (*(int*)b - *(int*) a);
}

void checkDigitsStr(char * s, int index, int val) {
	while (*s) {
		if (isdigit(*s++) == 0) {
			printf("String num %d is not string with the number only\n", index);
			return;
		}
	}	
	printf("String num %d consists of number %d\n", index, val);
}

void printArray(char *myText [], int len) {
	int i;
	//Print all items in myText array.
	for (i = 0; i < len; i++) {
		printf("%s\n", *(myText + i));
	}
}

void lengthOrder(char *myText[], int len, int arr[10]) {
	int i, myStrLen = 0;
	//Add lengthes of items in myText to arr.
	for (i = 0; i < len; i++) {
		myStrLen = strlen(myText[i]);
		arr[i] = myStrLen;
	}
	qsort(arr, len, sizeof(int), sortfunc);
	////Print lengthes of strings.
	//for (;len--;) {
	//	printf("%d ", arr[len]);
	//}
}

char *getLongest(char *myText[], int len) {
	char *longest = myText[0];
	for (;len--;) {
		if (strlen(longest) <= strlen(myText[len])) {
			longest = myText[len];
		}
	}
	//print longest string
	//puts(longest);
	return longest;
}

char *getShortest(char *myText[], int len) {
	int i;
	char *shortest = myText[0];
	for (i = 0; i < len; i++) {
		if (strlen(myText[i]) <= strlen(shortest)) {
			shortest = myText[i];
		}
	}
	//print shortest string
	//puts(shortest);
	return shortest;
}

void fillRandom(char *myText [], int len, int n) {
	time_t t;
	srand((unsigned) time(&t));
	int i, j;
	char *randChars;

	//Fill an array.
	for (i = 0; i < len; i++) {
		randChars = (char*)malloc(n*sizeof(char));
		for (j = -1; j < n;) {
			j++;
			if (n == j) {
				randChars[j] = '\0';
				break;
			}
			randChars[j] = (char)((rand() % 94) + 33);
		}
		*(myText + i) = randChars;
	}
}

void swapShLn(char * myText [], int len) {
	char *shLine, *lnLine, *temp;
	int i, shIndex, lnIndex;
	shLine = getShortest(myText, len);
	lnLine = getLongest(myText, len);
	temp = shLine;
	for (i = 0; i < len; i++) {
		//Get indexes of the shortest and longest elements.
		if (!strcmp(myText[i], shLine)) {
			shIndex = i;
		}
		if (!strcmp(myText[i], lnLine)) {
			lnIndex = i;
		}
	}
	*(myText + shIndex) = lnLine;
	*(myText + lnIndex) = temp;
}

void lessThan(char * myText [], int len, int value, char *tempStrArrForLessThan[]) {
	int i;
	for (i = 0; i < len; i++) {
		//Copy the string, if it is less than value.
		if (strlen(myText[i]) < (size_t)value) {
			strcpy(tempStrArrForLessThan[i], myText[i]);
		}
	}
}

void moreThan(char * myText [], int len, int value, char *tempStrArrForMoreThan[]) {
	int i;
	for (i = 0; i < len; i++) {
		//Copy the string, if it is bigger than value.
		if (strlen(myText[i]) > (size_t)value) {
			strcpy(tempStrArrForMoreThan[i], myText[i]);
		}
	}
}

void wordsCount(char *myText [], int len, int wordsResult[]) {
	//Invalid characters, that are NOT letters.
	const char *invalid_characters = " 1234567890!@#$%^&*()_+=-{}[];:<>,./?|\\\"'~`";
	int words, i = 0;

	for (i = 0; i < len; i++) {
		char *c = myText[i];
		words = 0;
		//Check character by character in myText[i] string.
		while (*c) {
			if (!strchr(invalid_characters, *c)) {
				words++;
				while (!strchr(invalid_characters, *c)) {
					c++;
				}
			}
			c++;
		}
		//Just for fun :)
		wordsResult[i] = words;
		/*if (words == 1) {
			printf("%d`st line has %d word\n", i, words);
		}
		else {
			printf("%d`st line has %d words\n", i, words);
		}*/
	}
}

void findNumInStr(char * myText [], int len, int index) {
	int val;
	//Check if index is not more then length of array
	if (index >= len) {
		puts("Sorry, index is out of range of array");
		return;
	}
	val = atoi(myText[index]);
	checkDigitsStr(myText[index], index, val);
}

void findNumInAllStrings(char * myText [], int len) {
	int i;
	for (i = 0; i < len; i++) {
		findNumInStr(myText, len, i);
	}
}