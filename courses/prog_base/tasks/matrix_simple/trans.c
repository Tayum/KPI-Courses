#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This method fills a matrix 4x4 with random numbers */
void fillRand(int mat[4][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mat[i][j] = 1000 - rand()%2000;
		}
	}
}
/* This method rotates a matrix 4x4 counter clockwise by 180 degrees */
void rotateCCW180(int mat[4][4]) {
	int i, j;
	int myTempArray[4][4];
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			myTempArray[i][j] = mat[3 - i][3- j];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mat[i][j] = myTempArray[i][j];
		}
	}
}

/* This method makes a horizontal flip with a 4x4 matrix */
void flipH(int mat[4][4]) {
	int i, j;
	int myTempArray[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			myTempArray[i][j] = mat[i][3 - j];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mat[i][j] = myTempArray[i][j];
		}
	}
}

/* This method makes a main diagonal transposition with a 4x4 matrix*/
void transposeMain(int mat[4][4]) {
	int i, j;
	int myTempArray[4][4];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			myTempArray[i][j] = mat[j][i];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mat[i][j] = myTempArray[i][j];
		}
	}
}