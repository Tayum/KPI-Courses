#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void) {

	//fflush example!

	FILE *fp;
	int i;
	char *buff = "asdfuck yu";
	if ((fp = fopen("test.txt", "wb")) == NULL) {
		puts("Error opening file.");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; i++) {
		fwrite(buff, sizeof(char), 1, fp);
		fflush(fp);
	}
	if (fclose(fp) == EOF) {
		puts("Error by closing file.");
		exit(EXIT_FAILURE);
	}

	//xD fun
	/*i = 0;
	while (1) {
		printf("\r%i", i);
		fflush(stdout);
		Sleep(1);
		i++;		
	}*/


	return EXIT_SUCCESS;
}