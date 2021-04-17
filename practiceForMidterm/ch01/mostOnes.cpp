#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15
//��Ʈ��Ŀ��� �ִ� 1 �� ã��
//�ð����⵵ o(n)
//��� : ��ܽ�

int mostOnes(int A[][MAX_SIZE], int n) {
	int row = 0;
	int i = 0, j = 0;

	while (i < n && j < n) {
		if (A[i][j] == 0) {
			i++;
		}
		else {
			row = i;
			j++;
		}
	}
	return row;
	
}

int mostOnes2(int A[][MAX_SIZE], int n) {
	int i = 0, j = 0;
	int row=0;

	while (1) {
		while (A[i][j] == 1) {
			j++;
			if (j == n) return i;
		}
		row = i;

		while (A[i][j] == 0) {
			i++;
			if (i == n)
				return row;
		}
	}
}

int main() {
	int A[MAX_SIZE][MAX_SIZE] = {
		{1,1,1,1,0,0,0,0},
	{1,1,1,1,1,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,1,0,0,0}
	};

	printf("%d", mostOnes(A, 8));
	printf("\n\n%d", mostOnes2(A, 8));
}