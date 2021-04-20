#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t){t=x, x=y, y=t;}

/*
<1단계>

5 3 8 1 2 7
3 5 8 1 2 7
3 5 1 8 2 7
3 5 1 2 8 7
3 5 1 2 7 8
*/

void bubble_sort(int list[], int n) {
	int temp;
	
	printf("정렬할 원소: ");
	for (int t = 0; t < n; t++) {
		printf("%d ", list[t]);
	}
	printf("\n\n<<<<<<<<<<버블정렬 수행>>>>>>>>>>");

	for (int i = n - 1; i >= 0; i--) {
		printf("\n %d 단계>>", n - i);
		for (int j = 0; j < i; j++) { 
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
		for (int t = 0; t < n; t++)
			printf("%3d ", list[t]);
	}
}

int main() {
	int list[6] = { 5, 3, 8, 1, 2, 7 };
	bubble_sort(list, 6);
}