#pragma once
#ifndef __MY_ARRAY_STACKK_HPP__
#define __MY_ARRAY_STACKK_HPP__
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
template <typename T>
class ArrStack { //클래스 선언
private:
	T* arr;
	int length;
	int top;
public:
	ArrStack() { //생성자
		top = -1;
		length = STACK_LEN;
		arr = new T[STACK_LEN];
	}
	ArrStack(int len) {
		top = -1;
		length = len;
		arr = new T[len];
	}
	void Stack_Init() //배열 스택 초기화
	{
		top = -1;
	}
	void Stack_Push(T item) //데이터 삽입
	{
		if (Stack_IsFull() == false) {
			top += 1;
			arr[top] = item;
		}
		else
			exit(1);
	}
	T Stack_Pop() //데이터 인출
	{
		if (Stack_IsEmpty() == true)
			exit(1);
		else
			top -= 1;

		return arr[top + 1];
	}
	T Stack_Peek() //최상단 데이터 확인
	{
		if (Stack_IsEmpty() == true)
			exit(1);
		else
			return arr[top];
	}
	bool Stack_IsEmpty() //스택이 비어있는지 확인
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool Stack_IsFull() //스택이 가득 차 있는지 확인
	{
		if (top == 99)
			return true;
		else
			return false;
	}
}; 
#endif