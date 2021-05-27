#include <stdio.h>
#include<stdlib.h>

#define max(x, y)(x>y? x:y)
#define min(x, y)(x<y? x:y)

int m[8][8];
int A[8][8] = {
	{1,3,7,2,11,17,16,25},
	{6,2,3,4,7,2,12,15},
	{11,4,6,8,8,1,9,14},
	{20,8,8,11,6,3,3,9},
	{0,10,9,8,7,15,17,22},
	{17,12,7,10,3,1,8,13},
	{19,25,10,15,14,11,3,3},
	{21,18,16,20,15,13,19,0}
};

//동적프로그래밍 - 정방향
int minGold(int n) {
	m[0][0] = A[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i ==0&&j == 0)
				continue;
			int minright = 10000; //오른쪽 방향으로 갈 때 최솟값
			for (int k = j - 1; k >= 0; k--) {
				int cost = m[i][k] + A[i][j];
				minright = min(minright, cost);
			}

			int mindown = 10000; //아래 방향으로 갈 때 최솟값
			for (int k = i - 1; k >= 0; k--) {
				int cost = m[k][j] + A[i][j];
				mindown = min(mindown, cost);
			}
			m[i][j] = min(minright, mindown);
		}
	}

	return m[n - 1][n - 1];
}

//동적프로그래밍 - 역방향
int minGold_reverse(int n) {
	m[n - 1][n - 1] = A[n - 1][n - 1];

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == n - 1 && j == n - 1)
				continue;
			int minright = 10000;
			for (int k = j + 1; k < n; k++) {
				int cost = A[i][j] + m[i][k];
				minright = min(cost, minright);
			}

			int mindown = 10000;
			for (int k = i + 1; k < n; k++) {
				int cost = A[i][j] + m[k][j];
				mindown = min(cost, mindown);
			}

			m[i][j] = min(minright, mindown);
		}
	}

	return m[0][0];
}

void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%02d ", m[i][j]);
		printf("\n");
	}
}

int main() {
	int n = 8;
	printf("%d\n", minGold(n));
	print(n);
}