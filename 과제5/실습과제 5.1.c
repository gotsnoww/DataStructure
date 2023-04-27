//MyArrayStack.h
#pragma once
#ifndef __MY_ARRAY_STACK_H__
#define __MY_ARRAY_STACK_H__
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
typedef enum { F, T }Bool; //Bool 타입 정의
typedef int Data; //Data 타입 정의
typedef struct MyArrayStack { //배열 스택의 자료구조
	Data arr[STACK_LEN];
	int top;
}ArrStack; //Array Stack 구조체 선언
void Stack_Init(ArrStack* pStack); //배열 스택 초기화
void Stack_Push(ArrStack* pStack, Data item); //데이터 삽입
Data Stack_Pop(ArrStack* pStack); //데이터 인출
Data Stack_Peek(ArrStack* pStack); //최상단 데이터 확인
Bool Stack_IsEmpty(ArrStack* pStack); //스택이 비어있는지 확인
Bool Stack_IsFull(ArrStack* pStack); //스택이 가득 차 있는지 확인
#endif

//MyArrayStack.c
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

//main.c
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
