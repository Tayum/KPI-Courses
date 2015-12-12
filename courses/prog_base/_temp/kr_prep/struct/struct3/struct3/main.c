#include <stdio.h>
#include <stdlib.h>

struct struct_type {
	int a, b;
	char ch;
} ;

void f1(struct struct_type parm) {
	printf("%d\n", parm.a);
}

int main(void) {

	struct struct_type arg;
	arg.a = 12345;
	f1(arg);

	return 0;
}