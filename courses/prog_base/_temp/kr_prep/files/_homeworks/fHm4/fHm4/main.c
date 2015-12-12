#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	FILE *fp;
	int counter = 0;
	char srcString [] = "OMG         THIS IS A SOURCE STRING OH WAIT FUCK YOU ";
	char *token = strtok(srcString, " ");
	//Open file stream
	if ((fp = fopen("test.txt", "w+")) == NULL) {
		puts("Error opening file");
		exit(EXIT_SUCCESS);
	}

	while (token != NULL) {
		counter++;
		token = strtok(NULL, " ");
	}
	fprintf(fp, "%i", counter);

	//Close file stream
	if (fclose(fp) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}