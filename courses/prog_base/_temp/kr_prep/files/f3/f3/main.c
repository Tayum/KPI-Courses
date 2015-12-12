#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE *fp;
	fpos_t len;
	//Checking for fclose!
	if ((fp = fopen("test.txt", "w+")) == NULL) {
		puts("Error opening file");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "HelloWorld!");

	fgetpos(fp, &len);
	len += 5;
	fsetpos(fp, &len);
	fprintf(fp, "\\n\\n\\n\\n");

	if (fclose(fp) == EOF) {
		printf("Error closing file.");
		exit(EXIT_FAILURE);
	}

	return 0;
}