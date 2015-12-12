#include <time.h>
#include <stdio.h>

int main(void) {
	
	time_t rawtime;
	struct tm *info;
	char buff[100];

	time(&rawtime);
	info = localtime(&rawtime);

	strftime(buff, 100, "%x - %I:%M%p", info);
	puts(buff);
	
	getchar();
	return 0;
}