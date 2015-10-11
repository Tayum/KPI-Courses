#include <math.h>

double long2double(long long myLong)
{
	double finalResult;
	int numsArr[64]; //Array, which will contain digits of "long long myLong".
	double stepen = 0; //i hate this variable and how i use it. i`m sorry
	double fractDecNum = 0.0; // fraction number
	double expDecNum = 0; // exponent number
	double signDecNum = 0; //sign number
	int i, j; //counters

	double signArr[1]; //signArr - digits of sign character
	double expArr[11]; //expArr - digits of exponent number
	double fractArr[52]; //fractArr = digits of fraction number

	for (i = 0; i < 64; i++) {
		numsArr[i] = (1LL << (63 - i)) == (myLong & (1LL << (63 - i))) ? 1 : 0;
	}
	//This solution is also correct:	
	/*for (i = 0; i < 64; i++) {
	numsArr[i] = (myLong & (1LL << i)) ? 1 : 0;
	}*/

	signArr[0] = numsArr[0];
	for (j = 12; j < 64; j++) {
		fractArr[j - 9] = numsArr[j];
	}
	for (i = 1; i < 12; i++) {
		expArr[i - 1] = numsArr[i];
	}

	signDecNum = signArr[0];
	for (i = 10; i >= 0; --i) {
		expDecNum += (expArr[i] * (int)pow(2.0, stepen));
		stepen++;
	}
	for (i = 0; i <= 51; i++) {
		fractDecNum += (fractArr[i] * pow(2.0, stepen));
		stepen--;
	}

	if (expDecNum > 0 && expDecNum < 2047) {
		finalResult = (pow(-1, signDecNum) * pow(2, expDecNum - 1023) * (fractDecNum + 1));
	}
	if (expDecNum != 0 && fractDecNum != 0) {
		finalResult = (pow(-1, signDecNum) * pow(2, -1022) * (fractDecNum - 1));
	}
	else if (expDecNum == 0 && fractDecNum == 0)
	{
		return pow(-1, signDecNum) * 0;
	}
	else if (expDecNum == 2047 && fractDecNum == 0 && signDecNum == 1) {
		return pow(-1, signDecNum)*INFINITY;
	}
	else if (expDecNum == 2047 && fractDecNum != 0) {
		return pow(-1, signDecNum) * NAN;
	}

}