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