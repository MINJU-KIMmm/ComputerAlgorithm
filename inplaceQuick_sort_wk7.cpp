#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t)=(x),(x)=(y), (y)=(t))
//퀵 정렬
//제자리 퀵 정렬 추가

int partition(int list[], int left, int right, int k) {
	int pivot, temp, low, high;
	pivot = list[k];
	SWAP(list[k], list[right], temp);

	printf("Pivot = %d\n", pivot);
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
	low = left-1;
	high = right; //right+1에는 pivot이 들어감

	do {
		do
			low++;
		while (list[low] < pivot);

		do
			high--;
		while (list[high] > pivot);

		//정렬과정 출력
		/*for (int i = 0; i < MAX_SIZE; i++)
			printf("[%d] ", list[i]);
		printf("\nlow=%d, high=%d\n", low, high); getchar();*/

		if (low < high)
			SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[low], list[right], temp); //list[high]=pivot보다 작은 것 중 가장 오른쪽 값
	return low;
}
void quick_sort(int list[], int left, int right) {
	if (left < right) {
		//제자리 퀵정렬 위한 추가 부분
		int k = rand() % (right - left) + left + 1;
		int q = partition(list, left, right, k);
		quick_sort(list, left, q - 1); //q는 이미 정렬이 된 것-> 이제 정렬에서 빠져야 함
		quick_sort(list, q + 1, right);
	}
}

int main() {
	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getchar();

	quick_sort(list, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
}
