#include <stdio.h>
#include <stdlib.h>

#define max(x, y)(x>y? x:y) //최대 비용 구하는 경우 사용(답 : 18)
#define min(x, y)(x<y? x:y)


int A[] = { 0,1,3,6,11,17 }; //비행기값
int H[] = { 0,2,5,1,5,0 }; //호텔비
int m[10];

//동적프로그래밍 - 정방향
int airtel(int n) {
	m[0] = 0;
	int cost;
	for (int d = 1; d < n; d++) {
		m[d] = 10000;
		for (int k = 0; k < d; k++) {
			cost = m[k] + H[k] + A[d - k];
			m[d] = min(m[d], cost);
		}
	}

	return m[n - 1]; //최종목표가 n-1번째 거
}

//분할통치 - 정방향
int rAirtelForward(int d) {
	if (d == 0) return 0;
	int minCost = 10000;
	int cost;

	for (int k = 0; k < d; k++) {
		cost = rAirtelForward(k) + H[k] + A[d - k];
		minCost = min(minCost, cost);
	}

	return minCost;
}

int main() {
	printf("%d\n", rAirtelForward(5));

	return 0;
}