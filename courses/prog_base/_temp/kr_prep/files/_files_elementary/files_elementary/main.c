#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <io.h>

int main(void) {

	FILE *fp, *fp2;
	char ch, userInput[100], *userInputStrings[5];
	char buff[100];
	char *resultBuff[100];
	int i = 0, lines = 0;

	char line[80];

	char newFileName[50];
	char *secondName = "keklolSecondNAme.txt";

	//Open file stream.
	if ((fp = fopen("test.txt", "r+")) == NULL) {
		puts("Error opening file.");
		exit(EXIT_FAILURE);
	}

	//Close a file stream.
	if (fclose(fp) == EOF) {
		puts("Error closing file.");
		exit(EXIT_FAILURE);
	}


	getchar();
	return EXIT_SUCCESS;
}

//#1 Print .txt to console.
/*
while ((ch = fgetc(fp)) != EOF) {
printf("%c", ch);
}
*/

//#2 User inputs *char[]. Write them to the file.
/*puts("please, enter your 5 lines!");
for (i = 0; i < 5; i++) {
userInputStrings[i] = (char *) calloc(50, sizeof(char));
gets_s(userInputStrings[i], 50);
fprintf(fp, "%s\n", userInputStrings[i]);
free(userInputStrings[i]);
}*/

//#3 Read text from the first file and add it to the second.
/*
//Open a stream
if ((fp2 = fopen("test2.txt", "w+")) == NULL) {
puts("Error opening file.");
exit(EXIT_FAILURE);
}
//Add strings from first file to buffer. (STRINGS!)
while (fgets(buff, 100, fp) != NULL) {
resultBuff[i] = strdup(buff);
lines++;
i++;
}
i = 0;
while (i<lines) {
fprintf(fp2, "%s", resultBuff[i]);
i++;
}
//Close a stream
if (fclose(fp2) == EOF) {
puts("Error closing file.");
exit(EXIT_FAILURE);
}
*/

//#4 Read text from the first file and append it to the second.
/*
if ((fp2 = fopen("test2.txt", "a")) == NULL) {
puts("Error opening file.");
exit(EXIT_FAILURE);
}
while (fgets(buff, 100, fp) != NULL) {
resultBuff[i] = strdup(buff);
lines++;
i++;
}
i = 0;
while (i<lines) {
fprintf(fp2, "%s", resultBuff[i]);
i++;
}
if (fclose(fp2) == EOF) {
puts("Error closing file.");
exit(EXIT_FAILURE);
}
*/

//#5 Create a new file (name inputs a user). If this file exists - add error!
/*
puts("Please, enter your filename!");
gets_s(newFileName, 50);
if (!access(newFileName, 0)) {
printf("There is already a file with the same name :)\n");
exit(EXIT_FAILURE);
}
if ((fp = fopen(newFileName, "w")) == NULL) {
puts("Error opening file.");
exit(EXIT_FAILURE);
}
*/

//#6 User inputs line. If this file exists - rename it to tje char*secondName.
/*puts("Please, enter your filename!");
gets_s(newFileName, 50);
if (!access(newFileName, 0)) {
puts("There is already a file with such name.");
puts("Renaming. . .");
rename(newFileName, secondName);
exit(EXIT_SUCCESS);
}
if ((fp = fopen("test.txt", "w")) == NULL) {
puts("Error opening file.");
exit(EXIT_FAILURE);
}*/

//#7 Check if in .txt file is a string, that inputs a user.
/*
puts("Please, enter your string");
gets_s(userInput, 100);
//Open a file stream
if ((fp = fopen("test.txt", "r+")) == NULL) {
puts("Error opening file.");
exit(EXIT_FAILURE);
}

while (fgets(line, 80, fp) != NULL) {
int len = strlen(line);
if (line[len-1] == '\n') {
line[len - 1] = '\0';
}

if (strcmp(line, userInput) == 0) {
puts("Hello!");
}
}
*/