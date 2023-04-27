#include <stdio.h>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) //�迭 ���� �ʱ�ȭ
{
	pStack->top = -1;
}

void Stack_Push(ArrStack* pStack, Data item) //������ ����
{
	if (Stack_IsFull(pStack) == F) {
		pStack->top = pStack->top + 1;
		pStack->arr[pStack->top] = item;
	}
	else
		exit(1);
}

Data Stack_Pop(ArrStack* pStack) //������ ����
{
	if (Stack_IsEmpty(pStack) == T)
		exit(1);
	else
		pStack->top = pStack->top - 1;
		return pStack->arr[pStack->top + 1];
}

Data Stack_Peek(ArrStack* pStack) //�ֻ�� ������ Ȯ��
{
	if (Stack_IsEmpty(pStack) == T)
		exit(1);
	else
		return pStack->arr[pStack->top];
}

Bool Stack_IsEmpty(ArrStack* pStack) //������ ����ִ��� Ȯ��
{
	if (pStack->top == -1)
		return T;
	else
		return F;
}

Bool Stack_IsFull(ArrStack* pStack) //������ ���� �� �ִ��� Ȯ��
{
	if (pStack->top == 99)
		return T;
	else
		return F;
}
