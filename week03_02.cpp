#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
};

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}

	node->data = item;
	node->link = before->link;
	before->link = node;
}


void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	node->data = item;
	node->link = NULL;
	if (L->head == NULL) {
		L->head = node;
	}
	else {
		while (before->link != NULL) {
			before = before->link;
		}
		before->link = node;
	}

	
}


int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

ListNode* getNode(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}
void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}


int size(LinkedListType* L) {
	int count = 0;
	for (ListNode* p = L->head; p != NULL; p = p->link) {
		count++;
	}
	return count;
}

//Ư�� ��� ����(pre ���� ���)
void remove(LinkedListType* L, int pos) {
	
	ListNode* pre = L->head;
	ListNode* del;
	if (pos <= 0 || pos > size(L)) {
		printf("������ ������ϴ�.\n");
		return;
	}
	else if (pos == 1) {
		del = L->head;
		L->head = del->link;
	}
	else {
		for (int i = 1; i < pos - 1; i++)
			pre = pre->link;
		del = pre->link;
		pre->link = del->link;
	}
	free(del);
	return;
}

//ù��° ��� ����
void removeFirst(LinkedListType* L) {
	ListNode* del = L->head;
	L->head = del->link;
	free(del);
	return;
}


//������ ��� ����
void removeLast(LinkedListType* L) {
	ListNode* pre;
	ListNode* delNode;
	if (L->head == NULL)return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else {
		pre = L->head;
		delNode = L->head->link;
		while (delNode->link != NULL) {
			pre = delNode;
			delNode = delNode->link;
		}
		free(delNode);
		pre->link = NULL;
	}
}


int main() {
	LinkedListType list;
	init(&list);
	
	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);

	getchar();
	add(&list, 1, 40); printList(&list); 
	add(&list, 1, 50); printList(&list);
	add(&list, 1, 60); printList(&list);

	printf("\n�������� ��� ����\n");
	addLast(&list, 200); printList(&list);

	int pos;
	printf("\n�� �� ����� ���� ��ȯ�ұ��?(��� ��ȣ�� 1������ ����)");
	scanf_s("%d", &pos);
	printf("%d�� ����� ���� %d\n", pos, get(&list, pos));

	printf("\nù��° ��� ����\n");
	removeFirst(&list); printList(&list);

	printf("\n������ ��� ����\n");
	removeLast(&list); printList(&list);

	printf("\n�� �� ����� ���� �����ұ��?(��� ��ȣ�� 1������ ����)");
	scanf_s("%d", &pos);
	remove(&list,pos); printList(&list);
}
