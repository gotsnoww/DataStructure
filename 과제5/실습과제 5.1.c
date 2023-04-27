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
	if (Stack_IsFull(pStack) == F) { //스택이 가득 차 있지 않을 경우에만 수행
		pStack->top = pStack->top + 1;
		pStack->arr[pStack->top] = item;
	}
	else
		exit(1);
}
Data Stack_Pop(ArrStack* pStack) //데이터 인출
{
	if (Stack_IsEmpty(pStack) == T) //스택이 비었으면 종료
		exit(1);
	else
		pStack->top = pStack->top - 1;
		return pStack->arr[pStack->top + 1];
}
Data Stack_Peek(ArrStack* pStack) //최상단 데이터 확인
{
	if (Stack_IsEmpty(pStack) == T) //스택이 비었으면 종료
		exit(1);
	else
		return pStack->arr[pStack->top];
}
Bool Stack_IsEmpty(ArrStack* pStack) //스택이 비어있는지 확인
{
	if (pStack->top == -1) //top의 값이 최초 설정된 -1인지 체크
		return T;
	else
		return F;
}
Bool Stack_IsFull(ArrStack* pStack) //스택이 가득 차 있는지 확인
{
	if (pStack->top == 99) //사용자가 지정한 배열의 크기만큼 top이 증가했는지 체크
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


- 과제를 대한 고찰
스택이라는 자료 구조를 배열을 이용하여 구현하는 과제를 수행해보았다.
임의의 크기인 배열을 미리 만들어두고, 데이터를 push pop 하는 형태의 코드이다.
배열의 최상단인 top에서 항상 데이터의 push와 pop이 이루어지기 때문에, 수행시간은 항상 O(1)이다.
수행공간은 배열의 크기에 따라 결정된다.
하지만 이러한 배열공간을 사용하는 스택 자료구조는 배열이 꽉 찼을 때 새로운 데이터를 push하지 못한다.
이러한 구조를 해결하기 위해서는 이전에 배웠던 연결리스트 자료구조를 통해 스택을 구현해야 한다.
	
