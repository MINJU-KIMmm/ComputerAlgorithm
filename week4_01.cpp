#include <stdio.h>

#define SIZE 6

//왜 교수님이랑 결과가 다르게 나오지...
//4. 기본추상자료형-6
void spans(int X[], int S[]) {
	int s;
	for (int i = 0; i < SIZE; i++) {
		s = 1;
		while ((s <= i) && (X[i - s] <= X[i]))
			s++;
		S[i] = s;
	}
}

int main() {
	int X[SIZE] = { 6.3,4,2,5,3 };
	int S[SIZE] = { 0 };

	spans(X, S);

	for (int i = 0; i < SIZE; i++)
		printf("[%d] ",S[i]);
	printf("\n");
}