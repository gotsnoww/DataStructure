#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

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

int main() {
	srand(time(NULL));
	int stack[SIZE];
	int top = -1, data;

	for (int k = 0; k <= SIZE; k++) {
		PUSH(stack, &top, rand() % 99 + 1);
	}

	for (int k = 0; k <= SIZE; k++) {
		data = POP(stack, &top);
		if (data != -1) {
			printf("POP : %d\n", data);
		}
		Display(stack, top);
	}

	for (int k = 0; k <= SIZE; k++) {
		PUSH(stack, &top, rand() % 99 + 1);
	}

	return 0;
}