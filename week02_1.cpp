#include <stdio.h>
#include <stdlib.h>

//Àç±Í3
void rPrintDigits(int n) {
	if (n < 10)printf("%d\n", n);
	else {
		rPrintDigits(n / 10);
		printf("%d\n", n % 10);
	}
}
void printDigits() {
	int n;
	printf("Enter a number : ");
	scanf_s("%d", &n);
	if (n < 0) printf("Negative!\n");
	else rPrintDigits(n);
}

int main() {
	printDigits();
}