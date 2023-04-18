#include <stdio.h>
#include "MyArrayStack.h"

int main(void) {
	ArrStack stack;

	//스택 초기화
	Stack_Init(&stack);

	//데이터 삽입
	Stack_Push(&stack, 5);
	Stack_Push(&stack, 7);
	Stack_Push(&stack, 8);
	Stack_Push(&stack, 9);
	Stack_Push(&stack, 2);

	//top 데이터 확인
	printf("top: %d\n", Stack_Peek(&stack));

	//데이터 인출
	while (!Stack_IsEmpty(&stack)) {
		printf("%d\n", Stack_Pop(&stack));
	}

	return 0;
}