#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	FILE *fp;
	//Open file stream for writing
	if ((fp = fopen("test.txt", "w+")) == NULL) {
		puts("Error writing file");
		exit(EXIT_FAILURE);
	}

	char mainStr[] = "Hello world and fuck you bitches";
	char *token = strtok(mainStr, " ");
	while (token != NULL)
	{
		fprintf(fp, "%s\n", token);
		token = strtok(NULL, " ");
	}

	//Close file stream
	if (fclose(fp) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}