#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];

	//루트가 아닌 경우, 부모노드의 값보다 작은 경우 swap
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = key;
}

void downHeap(HeapType* h) {
	int temp = h->heap[1];
	int parent = 1, child = 2;
	while (child <= h->heap_size) {//1번
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1])) {//내 오른쪽에도 또 노드가 있다 3번
			child++;
		}

		if (temp <= h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
}
void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);

}

int removeMin(HeapType* h) {
	int key = h->heap[1];
	h->heap[1] = h->heap[h->heap_size]; // 루트에 마지막 넣어줌
	h->heap_size -= 1;
	downHeap(h);
	return key;
}

void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

void heapSort(HeapType* h, int list[]) {
	HeapType heap;
	init(&heap);
	for (int i = 1; i <= h->heap_size; i++) {
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}

	for (int i = 1; i <= h->heap_size; i++)
		list[i] = removeMin(&heap);

}

void printArray(int list[], int n) {
	for (int i = 1; i <= n; i++) {
		printf("[%d] ", list[i]);
	}
	printf("\n");
}

//제자리 정렬
void inPlaceHeapSort(HeapType* h) {
	int size = h->heap_size;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMin(h);
		h->heap[h->heap_size + 1] = key;
	}
}
int main() {
	HeapType heap;
	int list[MAX_ELEMENT] = { 0 };
	srand(time(NULL));
	init(&heap);
	for (int i = 0; i < 15; i++)
		insertItem(&heap, rand() % 100);

	printHeap(&heap);
	getchar();
	inPlaceHeapSort(&heap);
	for (int i = 1; heap.heap[i] > 0; i++)
		printf("[%d] ", heap.heap[i]);
}