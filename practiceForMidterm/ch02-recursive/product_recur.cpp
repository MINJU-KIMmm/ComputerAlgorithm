#include <stdio.h>
#include <stdlib.h>

int product(int a, int b) {
	int result = a;
	if (b==1) return result;
	else {
		return a+product(a, b - 1);
	}
}

int modulo(int a, int b) {
	int result = a;
	if (a<b) return result;
	else {
		return modulo(a - b, b);
	}
}

int quotient(int a, int b) {
	int result = 0;
	if (a < b) return result;
	else return quotient(a - b, b) + 1;
}

int main() {
	int a = 14, b = 3;
	printf("product=%d\n", product(a, b));
	printf("modulo=%d\n", modulo(a, b));
	printf("quotient=%d\n", quotient(a, b));
	return 0;
}