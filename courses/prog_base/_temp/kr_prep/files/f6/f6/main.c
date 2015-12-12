#include <stdio.h>

int main(void) {

	char name[20];
	char *ptr;
	int i;
	//generate and print out three unique names of temp files!
	tmpnam(name);
	printf("%s", name);
	puts("");
	ptr = tmpnam(NULL);
	printf("%s", ptr);
	puts("");


	getchar();
	return 0;
}