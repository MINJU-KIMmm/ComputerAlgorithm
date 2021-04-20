#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void makeArray(int A[]) {
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand() % 50 + 50;
	}
}

void printArray(int A[]) {
	for (int i = 0; i < SIZE; i++) 
			printf("[%d] ", A[i]);
		printf("\n");
}

//��ø�� �ݺ���
void prefixAvg1(int A[]) {
	int X[SIZE];
	int sum;
	for (int i = 0; i < SIZE; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += A[j];
		}
		X[i] = sum / (i + 1);
	}
	printArray(X);
}

void prefixAvg2(int A[]) {
	int X[SIZE];
	int sum=0;
	for (int i = 0; i < SIZE; i++) {
		sum += A[i];
		X[i] = sum / (i + 1);
	}
	printArray(X);
}

int main() {
	int A[SIZE];
	srand(time(NULL));
	makeArray(A);
	printArray(A);

	getchar(); //ȭ�� ����
	
	prefixAvg2(A);
}