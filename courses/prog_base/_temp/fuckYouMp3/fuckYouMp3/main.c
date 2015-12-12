#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {

	printf("Hello whatsUP??\n");
	Sleep(1000);
	puts("Wanna have some fun?");

	system("start /MIN sound.mp3");
	Sleep(1000);
	puts("Fuck you!");

	getchar();
	return 0;
}