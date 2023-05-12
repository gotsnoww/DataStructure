#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct Q
{
	char queue[MAX];
	int front;
	int rear;
} Q;

typedef struct S
{
	char stack[MAX];
	int top;
} S;

void Push(S* s, char data)
{
	if (s->top == MAX - 1) {
		printf("스택 가득!!\n");
		return;
	}
	s->stack[++(s->top)] = data;
}
void Enq(Q* q, char data) {
	if ((q->rear+1) % MAX == q->front) {
		printf("큐 가득!!\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = data;
}
char Pop(S* s) {
	if (s->top == -1) {
		return 0;
	}
	
	return s->stack[(s->top)--];
}
char DeQ(Q* q) {
	if ((q->front+1) % MAX == q->rear) {
		return -1;
	}
	q->front = (q->front + 1) % MAX;

	return q->queue[(q->front)];
}

void main() {
	char str[MAX];

	Q q;
	S s;

	q.front = 0;
	q.rear = 0;
	
	s.top = -1;
	
	printf("문자열 입력 : ");
	scanf("%s", str);
	
	for (int i = 0; i < strlen(str); i++) {
		Push(&s, str[i]);
		Enq(&q, str[i]);
	}

	while (s.top != -1 && q.rear != (q.front + 1)) {
		if (Pop(&s) != DeQ(&q)) {
			printf("회문 아니다!\n");
			return;
		}
	}
	printf("회문!!!\n");
}
