#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15
//비트행렬에서 최대 1행 찾기(1.알고리즘분석-1)
//실행시간 o(n^2)

int mostOnesButSlow(int A[][MAX_SIZE], int n){
	int row = 0, max = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < n && A[i][j] == 1)
			j++;
		if (j > max) {
			row = i;
			max = j;
		}
	}

	return row;
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

	printf("%d", mostOnesButSlow(A, 8));
}