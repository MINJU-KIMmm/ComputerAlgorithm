#include <stdio.h>
#include <stdlib.h>

int c[15][150];

void calculate_subset_sum(int s[], int n, int m) {
	int i, j;

	for (i = 0; i <= n; i++)
		c[i][0] = 1;
	for (i = 1; i <= m; i++)
		c[0][i] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			c[i][j] = 0;

			if (j >= s[i - 1])
				if (c[i - 1][j - s[i - 1]] == 1)
					c[i][j] = 1;

			if (c[i - 1][j] == 1)
				c[i][j] = 1;
		}
	}
}

int main() {
	printf("input m,n : ");
	int m, n;

	scanf_s("%d %d", &m, &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	calculate_subset_sum(arr, n, m);

	if (c[n ][m ] == 1) printf("possible\n");

	for (int i = 1; i < m; i++) {
		if (c[n][i] == 1)
			printf("%d ", i);
	}

	//dp 과정 출력
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}


//-> 응용하면 도둑의 배낭문제 동적프로그래밍으로 해결 가능