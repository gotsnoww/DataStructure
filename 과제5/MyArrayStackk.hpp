#pragma once
#ifndef __MY_ARRAY_STACKK_HPP__
#define __MY_ARRAY_STACKK_HPP__
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
template <typename T>
class ArrStack { //Ŭ���� ����
private:
	T* arr;
	int length;
	int top;
public:
	ArrStack() { //������
		top = -1;
		length = STACK_LEN;
		arr = new T[STACK_LEN];
	}
	ArrStack(int len) {
		top = -1;
		length = len;
		arr = new T[len];
	}
	void Stack_Init() //�迭 ���� �ʱ�ȭ
	{
		top = -1;
	}
	void Stack_Push(T item) //������ ����
	{
		if (Stack_IsFull() == false) {
			top += 1;
			arr[top] = item;
		}
		else
			exit(1);
	}
	T Stack_Pop() //������ ����
	{
		if (Stack_IsEmpty() == true)
			exit(1);
		else
			top -= 1;

		return arr[top + 1];
	}
	T Stack_Peek() //�ֻ�� ������ Ȯ��
	{
		if (Stack_IsEmpty() == true)
			exit(1);
		else
			return arr[top];
	}
	bool Stack_IsEmpty() //������ ����ִ��� Ȯ��
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool Stack_IsFull() //������ ���� �� �ִ��� Ȯ��
	{
		if (top == 99)
			return true;
		else
			return false;
	}
}; 
#endif