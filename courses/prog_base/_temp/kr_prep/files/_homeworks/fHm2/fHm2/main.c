#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	FILE *fp, *fwr;
	char mainStr[100];
	char commaStr[200];
	int i, len, j = 0;
	//Open file stream for reading
	if ((fp = fopen("test.txt", "r")) == NULL) {
		puts("Error opening file");
		exit(EXIT_FAILURE);
	}
	fgets(mainStr, 100, fp);
	len = strlen(mainStr);
	for (i = 0; i < len; i++) {
		commaStr[j] = mainStr[i];
		commaStr[j + 1] = ',';
		j += 2;
	}
	commaStr[j - 1] = '\0';
	//Close file stream for reading.
	if (fclose(fp) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}

	//Open file stream for writing
	if ((fwr = fopen("result.txt", "w+")) == NULL) {
		puts("Error opening file");
		exit(EXIT_FAILURE);
	}
	fputs(commaStr, fwr);
	//Close file stream for writing
	if (fclose(fwr) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}