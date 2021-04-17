#include <stdio.h>
#include <stdlib.h>

//ch2 recursive

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("move from %c to %c\n", from, to);
		return;
	}
	else {
		rHanoi(n - 1, from, to, aux);
		printf("move from %c to %c\n", from, to);
		rHanoi(n - 1, aux, from, to);
		return;
	}
}

int main() {
	rHanoi(4, 'A', 'B', 'C');
	return 0;
}