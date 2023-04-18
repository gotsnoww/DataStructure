#include <stdio.h>
#include "MyArrayStack.h"

int main(void) {
	ArrStack stack;

	//���� �ʱ�ȭ
	Stack_Init(&stack);

	//������ ����
	Stack_Push(&stack, 5);
	Stack_Push(&stack, 7);
	Stack_Push(&stack, 8);
	Stack_Push(&stack, 9);
	Stack_Push(&stack, 2);

	//top ������ Ȯ��
	printf("top: %d\n", Stack_Peek(&stack));

	//������ ����
	while (!Stack_IsEmpty(&stack)) {
		printf("%d\n", Stack_Pop(&stack));
	}

	return 0;
}