#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//THINGS ABOUT POINTERS AND STRUCTURES
//
//struct bal {
//	float balance;
//	char name[80];
//} person;
//
////In main: 
//	struct bal *p = &person;
//	

#define DELAY 128

struct myTime{
	int hours;
	int minutes;
	int seconds;
} ;

void delay() {
	long int t;
	for (t = 1; t < DELAY; ++t) {
	}
}

void display(struct myTime *structPtr) {
	printf("Hours : %02d\n", structPtr->hours);
	printf("Minutes : %02d\n", structPtr->minutes);
	printf("Seconds : %02d\n", structPtr->seconds);
}

void update(struct myTime *structPtr) {
	structPtr->seconds++;
	if (structPtr->seconds == 60) {
		structPtr->seconds = 0;
		structPtr->minutes++;
	}
	if (structPtr->minutes == 60) {
		structPtr->minutes = 0;
		structPtr->hours++;
	}
	if (structPtr->hours == 24) {
		structPtr->hours = 0;
	}
	delay();
}



int main(void) {

	int myX = 0, myY = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { myX, myY };

	struct myTime localTime;
	localTime.hours = 0;
	localTime.minutes = 0;
	localTime.seconds = 0;

	//LOOK AT THE CURSOR POSITION AND TEXT COLOR HERE!!!!!!!
	for (;;) {
		SetConsoleCursorPosition(hConsole, pos);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		update(&localTime);
		display(&localTime);
	}

	return 0;
}