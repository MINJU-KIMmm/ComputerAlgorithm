#include <stdio.h>
#include <stdlib.h>

//재귀3 x의 거듭제곱

//반복문
int iter_power(int x, int n) {
	int result = 1;
	for (int i = 0; i < n; i++)
		result *= x;
	return result;
}

//재귀(시간복잡도가 보다 뛰어남 log2n)
int recur_power(int x, int n) {
	if (n == 0)
		return 1;
	else if ((n % 2) == 0)
		return recur_power(x * x, n / 2);
	else
		return x * recur_power(x * x, (n - 1) / 2); //x를 곱해야함
}
int main() {
	printf("2 ^ 10 = %d\n", iter_power(2, 10));
	printf("2 ^ 10 = %d\n", recur_power(2, 10));
}

//피보나치 수열의 경우 재귀적 형태이지만 재귀로 구현시 매우 비효율적(동일한 작업들을 너무 많이 반복하게 됨)-> 동적프로그래밍 => 재귀 알고리즘 사용 시 신중하게 결정
//퀵정렬, 합병정렬 -> 분할정복, 재귀

