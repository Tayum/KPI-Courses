#include <stdio.h>
#include <time.h>

int main(void) {

	struct tm *ptr;

	time_t rawTime;
	time(&rawTime);

	//That`s how we print current date!
	//printf("Current time is = %s", ctime(&rawTime));

	//Do the same with asctime()
	//ptr = localtime(&rawTime);
	//printf(asctime(ptr));

	//Print GMT and local time. How to use gmtime() karoch
	/*
	struct tm *local, *gm;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	printf("local time & date: %s\n", asctime(local));
	gm = gmtime(&t);
	printf("GMT time & date: %s", asctime(gm));
	*/

	//mktime example - if we will to merge our stuff
	/*time_t tempTime_T;
	struct tm timeStruct;
	timeStruct.tm_year = 2005 - 1900;
	timeStruct.tm_mon = 0;
	timeStruct.tm_mday = 3;
	timeStruct.tm_hour = 0; 
	timeStruct.tm_min = 0;  
	timeStruct.tm_sec = 1;  
	timeStruct.tm_isdst = 0;
	tempTime_T = mktime(&timeStruct);
	puts(ctime(&tempTime_T));
	*/

	//usage of localtime
	//This program will print local time and GMT
	/*struct tm *local;
	time_t t = time(&t);
	local = localtime(&t);
	puts(asctime(local));*/

	//usage of difftime
	//returns !!! TIME2-TIME1(@see parameters)
	//time_t start, end;
	//volatile long unsigned t;
	//start = time(&start);
	//for (t = 0; t<5000000; t++);
	//end = time(&end);
	//printf("A loop lasted %.20f seconds.\n", difftime(end, start));

	//Application runtime!
	//printf("Passed %u seconds", clock()/CLOCKS_PER_SEC);

	//Add some shit to the buffer!
	struct tm *timePtr;
	time_t lt = time(&lt);
	char str[80];

	timePtr = localtime(&lt);
	strftime(str, 80 * sizeof(char), "It is %H %p now.", timePtr);
	puts(str);


	getchar();
	return 0;
}