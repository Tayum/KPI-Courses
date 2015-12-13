#include <stdio.h>
#include <string.h>

#define ERROR '0'
#define ARRLEN 100

char repSymbol(char *str, size_t len, char ch) {
	int i;
	//If it cannot be repeatable symbols
	if (1 == len) {
		return ERROR;
	}
	//Go through the str.
	//If [0] and some symbol are equal - return [0].
	for (i = 1; i < len; i++) {
		if (str[0] == str[i]) {
			ch = str[0];
			return ch;
		}
	}
	//If in str are no symbols like [0] - do function again,
	//starting from the next symbol.
	if (ch == ERROR) {
		repSymbol(str + 1, len - 1, ch);
	}
}

int main(void) {

	//Get the string from user.
	char buff[ARRLEN];
	puts("Please, enter 10 characters :");
	gets_s(buff, ARRLEN * sizeof(char));
	int len = strlen(buff);

	//Find repeatable symbol
	char resultCh = repSymbol(buff, len, ERROR);
	printf("%c\n", resultCh);

	getchar();
	return 0;
}
