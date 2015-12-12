#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_info, binfo, cinfo;

int main(void) {

	addr_info.zip = 12345;
	printf("%d\n", addr_info.zip);
	gets(addr_info.name);
	puts(addr_info.name);

	//Access to symbols in struct member
	int t;
	for (t = 0; addr_info.name[t]; t++) {
		putchar(addr_info.name[t]);
		Sleep(100);
	}

	//Assignement structures!
	struct {
		int a;
		int b;
	}x, y;
	x.a = 10;
	x.b = 20;
	y = x; //Assignement is here
	printf("\n%d\t%d\n", y.a, y.b);


	getchar();
	return 0;
}