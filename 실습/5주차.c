#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void Display(int* stack, int top) {
	for (int k = SIZE-1; k >= 0; k--) {
		printf("[%2d ]   ", k);
		if (k <= top) {
			if (k == top) {
				printf("��    %2d     ��<---top\n", stack[k]);
			}
			else
			{
				printf("��    %2d     ��\n", stack[k]);
			}
		}
		else {
			printf("��           ��\n");
		}
	}
	printf("         -------------\n");
}

int isFull(int top)
{
	return top == (SIZE - 1);
}

void PUSH(int* stack, int* top, int data) {
	if (isFull(*top)) {
		printf("������ ����!!\n");
		return;
	}
	++(*top);
	stack[(*top)] = data;

	Display(stack, *top);
}

int isEmpty(int top) {
	return top == -1;
}

int POP(int* stack, int* top) {
	if (isEmpty(*top)) {
		printf("������ �����!\n");
		return - 1;
	}
	int temp = stack[(*top)];
	--(*top);

	return temp;
	//= return stack[(*top)--];
}
//------------------------------------------------
typedef int element;
typedef struct StackNode
{
	element data;
	struct StackNode* link;
} StackNode;

void push(element item, StackNode** top) //push �Լ� 
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = *top;
	*top = temp;
}

element pop(StackNode** top) //pop �Լ�
{
	if (*top == NULL)
		printf("������ ������ϴ�.\n");

	StackNode* temp = *top;
	temp = *top;
	element item = temp->data;
	*top = (*top)->link;
	free(temp);
	return item;
}

element peek(StackNode* top)
{
	if (top != NULL) {
		return top->data;
	}
	else 
		printf("������ ������ϴ�.\n");
}

void StackNode_Display(StackNode* top)
{
	if (top == NULL) {
		printf("������ ������ϴ�.\n");
		return;
	}
	
	StackNode* temp = top;
	while (temp != NULL) {
		printf("��    %2d     ��\n", temp->data);
		temp = temp->link;
	}
	printf(" -------------\n");
}

int main() {
	srand(time(NULL));
	StackNode* top = NULL;
	element data;
	
	//StackNode�� data push
	for (int i = 0; i < 3; i++) {
		element item = rand() % 10 + 1;
		push(item, top);
		StackNode_Display(top);
		data = peek(top);
		printf("top : %d\n\n", data);
	}

	//StackNode�� data pop
	for (int i = 0; i < SIZE; i++) {
		data = pop(top);
		StackNode_Display(top);
		printf("pop : %d", data);
		if (i != SIZE - 1) {
			data = peek(top);
			printf(", top : %d\n\n", peek(top));
		}
	}

	printf("\n");
	
	return 0;
}