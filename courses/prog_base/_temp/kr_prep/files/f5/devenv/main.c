#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main(void) {

	//fflush example!
	char buff[1024];
	memset(buff, '\0', 1024);
	fprintf(stdout, "Going to set buff \n");
	setvbuf(stdout, buff, _IOFBF, 1024);

	//After this i guess buff is filled
	fprintf(stdout, "This is tutorialspoint.com\n");
	//append some stuff
	fprintf(stdout, "This output will go into buff\n");
	fflush(stdout);


	//w+ mode! rewrite
	fprintf(stdout, "and this will appear when programm\n");
	//append some text
	fprintf(stdout, "will come after sleeping 5 seconds\n");

	//wtf

	Sleep(5000);



	return EXIT_SUCCESS;
}