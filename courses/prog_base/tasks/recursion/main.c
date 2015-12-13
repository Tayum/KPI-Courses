#include <stdio.h>
#include <string.h>

#define ERROR '0'
#define ARRLEN 100

char checkIfCharContainsInArrElseReturnERROR(char *, size_t, char);
char repSymbol(char *, size_t, char);

int main(void) {

	//Get the string from user.
	char buff[ARRLEN];
	puts("Please, enter your line! :");
	gets_s(buff, ARRLEN * sizeof(char));
	int len = strlen(buff);

	//Find repeatable symbol
	char resultCh = repSymbol(buff, len, ERROR);
	//char resultCh = checkIfCharContainsInArrElseReturnERROR(buff, len, 'w');
	printf("%c\n", resultCh);

	getchar();
	return 0;
}

//I don`t like recursion functions
char checkIfCharContainsInArrElseReturnERROR(char *arr, size_t len, char ch) {
	if (0 == len) {
		return ERROR;
	}
	//If something is similar
	else if (ch == arr[0]) {
		return ch;
	}
	//If something is not similar
	else {
		checkIfCharContainsInArrElseReturnERROR(arr + 1, len - 1, ch);
	}
}

char repSymbol(char *str, size_t len, char ch) {
	//If it cannot be repeatable symbols
	if (1 == len) {
		return ERROR;
	}
	//Go through the str and find if str[0] repeats in this array.
	ch = checkIfCharContainsInArrElseReturnERROR(str + 1, len, str[0]);
	//If in str are no symbols like [0] - do function again,
	//starting from the next symbol.
	if (ch == ERROR) {
		repSymbol(str + 1, len - 1, ch);
	}
}