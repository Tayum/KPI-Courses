#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

	int i;
	FILE *fRead, *fWrite;

	//Open file stream.
	if ((fRead = fopen("test.txt", "r")) == NULL) {
		puts("error opening file");
		exit(EXIT_FAILURE);
	}
	char *sentence = (char *) malloc(100 * sizeof(char));

	//Get to the 4th string.
	for (i = 0; i < 4; i++) {
		fgets(sentence, 100, fRead);
	}

	//Find the longest word
	char *word, *maxWord;
	size_t maxLength = 0;
	maxWord = (char *) calloc(40, sizeof(char));
	word = (char *) calloc(40, sizeof(char));
	word = strtok(sentence, " ");
	while (word != NULL) {
		if (strlen(word) > maxLength) {
			maxLength = strlen(word);
			strcpy(maxWord, word);
		}
		word = strtok(NULL, " ");
	}

	//Close file stream.
	if (fclose(fRead) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}

	//Open new stream for writing.
	if ((fWrite = fopen("result.txt", "w+")) == NULL) {
		puts("error opening file");
		exit(EXIT_FAILURE);
	}
	//Write result to result.txt
	fputs(maxWord, fWrite);
	//Close file stream
	if (fclose(fWrite) == EOF) {
		puts("Error closing file");
		exit(EXIT_FAILURE);
	}	

	return EXIT_SUCCESS;
}