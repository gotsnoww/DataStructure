#include <stdio.h>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) //배열 스택 초기화
{
	pStack->top = -1;
}

void Stack_Push(ArrStack* pStack, Data item) //데이터 삽입
{
	if (Stack_IsFull(pStack) == F) {
		pStack->top = pStack->top + 1;
		pStack->arr[pStack->top] = item;
	}
	else
		exit(1);
}

Data Stack_Pop(ArrStack* pStack) //데이터 인출
{
	if (Stack_IsEmpty(pStack) == T)
		exit(1);
	else
		pStack->top = pStack->top - 1;
		return pStack->arr[pStack->top + 1];
}

Data Stack_Peek(ArrStack* pStack) //최상단 데이터 확인
{
	if (Stack_IsEmpty(pStack) == T)
		exit(1);
	else
		return pStack->arr[pStack->top];
}

Bool Stack_IsEmpty(ArrStack* pStack) //스택이 비어있는지 확인
{
	if (pStack->top == -1)
		return T;
	else
		return F;
}

Bool Stack_IsFull(ArrStack* pStack) //스택이 가득 차 있는지 확인
{
	if (pStack->top == 99)
		return T;
	else
		return F;
}
