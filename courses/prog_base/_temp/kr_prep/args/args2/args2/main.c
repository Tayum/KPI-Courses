#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//access to a symbol from argv[i]

	//print symbols that were in argv:

	int t, i;
	for (t = 0; t < argc; t++) {
		i = 0;
		while (argv[t][i]) {
			putchar(argv[t][i]);
			i++;
		}
		puts("");
	}

	getchar();
	return 0;
}