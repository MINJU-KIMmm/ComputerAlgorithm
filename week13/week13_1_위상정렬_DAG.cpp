#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
	int vNum1;
	int vNum2;	
	struct Edge* next;
}Edge;

typedef struct IncidentEdge {
	int adjVertex;
	Edge* e;
	struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex {
	int num;
	int isFresh;
	struct Vertex* next;
	IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount;
int eCount;
int in[6];

//큐(배열, 원형큐) => 스택으로도 해보기
#define N 10

typedef struct {
	int element[N];
	int front, rear;
}Queue;

void initQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(Queue* Q) {
	return Q->rear == Q->front;
}

int isFull(Queue *Q) {
	return (Q->rear + 1) % N == Q->front;
}

void enqueue(Queue* Q, char elem) {
	if (isFull(Q)) {
		printf("FULL\n");
		return;
	}
	Q->rear = (Q->rear + 1) % N;
	Q->element[Q->rear] = elem;
}

int dequeue(Queue* Q) {
	if (isEmpty(Q)) {
		printf("Empty\n");
		exit(1);
	}

	Q->front = (Q->front + 1) % N;
	return Q->element[Q->front];
}
//-------큐 끝---------


void makeVertices() {
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->num = ++vCount;
	p->top = NULL;
	p->next = NULL;
	p->isFresh = 0;
	Vertex* q = vHead;
	if (q == NULL)
		vHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

void insertIncidentEdge(Vertex* v, int av, Edge* e) {
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = av;
	p->e = e;
	p->next = NULL;
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

Vertex* findVertex(int v) {
	Vertex* p = vHead;
	while (p->num != v)
		p = p->next;
	return p;
}

void insertEdge(int v1, int v2) {
	Edge* p = (Edge*)malloc(sizeof(Edge));
	p->vNum1 = v1;
	p->vNum2 = v2;
	p->next = NULL;
	Edge* q = eHead;
	if (q == NULL)
		eHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}

	Vertex* v = findVertex(v1);
	insertIncidentEdge(v, v2, p);
}

void inDegree() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next)
		for(q=p->top;q!=NULL;q=q->next)
			in[q->adjVertex - 1]++;
}

void topologicalSort() {
	Queue q;
	initQueue(&q);
	Vertex* p;
	IncidentEdge* r;
	inDegree(); //진입차수 배열에 넣음

	for (int i = 0; i < 6; i++)
		if (in[i] == 0)
			enqueue(&q, i + 1);
	while (!isEmpty(&q)) {
		int w = dequeue(&q);
		printf("[%d] ", w);
		p = findVertex(w);
		r = p->top;
		while (r != NULL) {
			in[r->adjVertex - 1]--;
			if (in[r->adjVertex - 1] == 0)
				enqueue(&q, r->adjVertex);
			r = r->next;
		}
	}
}
void print() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next) {
		printf("정점 %d : ", p->num);
		for (q = p->top; q != NULL; q = q->next)
			printf("[%d] ", q->adjVertex);
		printf("\n");
	}
}

int main() {
	for (int i = 0; i < 6; i++)
		makeVertices();

	insertEdge(1, 2);
	insertEdge(1, 5);
	insertEdge(2, 3);
	insertEdge(4, 5);
	insertEdge(5, 2);
	insertEdge(5, 3);
	insertEdge(5, 6);
	insertEdge(6, 3);

	print();

	topologicalSort();

	return 0;
}