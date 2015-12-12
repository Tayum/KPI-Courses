#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>

int main(int argc, char *argv[]) {

	//#1. Simple example!
	/*if (argc != 2) {
		printf("You forgot to set your name\n");
		exit(EXIT_FAILURE);
	}
	printf("Privetik %s\n", argv[1]);*/

	int disp, count;
	if (argc < 3) {
		printf("Pls try enter a number again!");
		exit(EXIT_FAILURE);
	}
	if (argc == 3 && !strcmp(argv[2], "display"))
		disp = 1;
	else disp = 0;

	for (count = atoi(argv[1]); count; --count) {
		if (disp) {
			printf("%d\n", count);
			Sleep(100);
		}
	}

	putchar('\a');
	printf("End!");

	return 0;
}