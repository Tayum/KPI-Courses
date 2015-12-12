#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *fp;
	int len;
	fpos_t position;

	fp = fopen("file.txt", "w+");
	if (fp == NULL) {
		puts("Error opening file");
		return EXIT_FAILURE;
	}

	//check how much bytes are in file.txt
	/*
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fclose(fp);
	printf("Total size of file.txt = %d bytes\n", len);
	*/

	//Get the current file position of the stream. 
	//Write it to pos
	fgetpos(fp, &position);
	fputs("HELLO world!", fp);
	//+3 FROM THE START!
	position += 3;
	fsetpos(fp, &position);
	fputs("Oh, fuck you", fp);

	fclose(fp);

	getchar();
	return 0;
}