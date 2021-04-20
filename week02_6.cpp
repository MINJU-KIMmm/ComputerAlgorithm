#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

void printArray(int A[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%2d ", A[i][j]);
		printf("\n");
	}
}

void spiral(int A[][SIZE], int n, int m) {
	int left = 0, right = m - 1;
	int top = 0, bottom = n - 1;
	
	int value = 1;

	while (left <= right && top <= bottom) {
		for (int j = left; j <= right; j++) {
			A[top][j] = value;
			value++;
		}
		top++;
		if(top<=bottom)
			for (int i = top; i <= bottom; i++) {
				A[i][right] = value;
				value++;
			}
		right--;
		if(left<=right)
			for (int j = left; j <= right; j++) {
				A[bottom][j] = value;
			}
	}
}