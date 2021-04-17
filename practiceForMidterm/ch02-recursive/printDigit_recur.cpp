#include <stdio.h>
#include <stdlib.h>

//ch2 recursive Àç±Í
void rPrintDigits(int n) {
	if (n < 10) printf("%d\n", n);
	else {
		rPrintDigits(n / 10);
		printf("%d\n", n % 10);
	}
}

void printDigits(int n) {
	if (n < 0) printf("negative\n");
	else rPrintDigits(n);
}

int main() {
	printDigits(3408);

	return 0;
}