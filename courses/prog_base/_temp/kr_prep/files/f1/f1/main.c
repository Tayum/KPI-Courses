#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_type {
	float balance;
	char name[80];
} cust;

int main(void) {

	FILE *fp;
	char ch, *tempStr = "Hello world!";
	char buffer[100], buffer2[100], tempBuff[] = "FUCK YOU_____________";
	double d = 12.23;
	int j = 101;
	long l = 123023L;
	int i;
	if ((fp = fopen("test.txt", "wb+")) == NULL) {
		puts("Sorry you cannot open this file.");
		exit(EXIT_FAILURE);
	}

	cust.balance = 1234.04F;


	//reading file char by char using fgetc()
	/*
	while ((ch = fgetc(fp)) != EOF)  {
		printf("%c", ch);
	}
	*/

	//put some chars to the file using putc()
	/*
	for (i = 0; i < 20; i++) {
		fputc('0', fp);
		fputc('1', fp);
	}
	*/

	//scan words by backspaces using fscanf()
	/*
	fscanf(fp, "%s %s", buffer, buffer2);	
	puts(buffer);
	puts(buffer2);
	*/

	//Add lines to the file using fprintf(). You can use formatting as well
	/*fprintf(fp, "%s\n%s", "Allah akbar", "New line");*/

	//Add lines using fputs(). Just puts something from buffer.
	/*fputs(tempBuff, fp);*/

	//How to print and read types, more than 1 byte?
	//We use fread() and fwrite() for it
	/*
	fwrite(&d, sizeof(double), 1, fp);
	fwrite(&j, sizeof(int), 1, fp);
	fwrite(&l, sizeof(long), 1, fp);

	rewind(fp);

	fread(&d, sizeof(double), 1, fp);
	fread(&j, sizeof(int), 1, fp);
	fread(&l, sizeof(long), 1, fp);
	printf("%f %d %ld", d, j, l);
	*/
	//We can also use this shit for structures
	//fwrite(&cust, sizeof(struct struct_type), 1, fp);
	

	fclose(fp);

	//getchar();
	return 0;
}