#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

#define max(x, y) (x>y? x:y)

//최고 선호도 찾아주는 경로 찾는 방법도 생각해보기

int map[M][N];
int joy[M][N];

void calc_joy(int m, int n) {
	int i, j;
	joy[0][0] = map[0][0];

	for (i = 1; i < m; i++)
		joy[i][0] = joy[i - 1][0] + map[i][0];
	for (j = 1; j < n; j++)
		joy[0][j] = joy[0][j - 1] + map[0][j];
	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++)
			joy[i][j] = max(joy[i-1][j], joy[i][j-1])+map[i][j];
}

void print(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%02d ", joy[i][j]);
		printf("\n");
	}
}

int main() {
	int m, n;
	scanf_s("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf_s("%d", &map[i][j]);
	}
	calc_joy(m, n);
	printf("\n");
	print(m, n);
	return 0;
}