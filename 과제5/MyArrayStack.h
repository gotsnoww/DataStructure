#pragma once
#ifndef __MY_ARRAY_STACK_H__
#define __MY_ARRAY_STACK_H__
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
typedef enum { F, T }Bool; //Bool Ÿ�� ����
typedef int Data; //Data Ÿ�� ����
typedef struct MyArrayStack { //�迭 ������ �ڷᱸ��
	Data arr[STACK_LEN];
	int top;
}ArrStack; //Array Stack ����ü ����
void Stack_Init(ArrStack* pStack); //�迭 ���� �ʱ�ȭ
void Stack_Push(ArrStack* pStack, Data item); //������ ����
Data Stack_Pop(ArrStack* pStack); //������ ����
Data Stack_Peek(ArrStack* pStack); //�ֻ�� ������ Ȯ��
Bool Stack_IsEmpty(ArrStack* pStack); //������ ����ִ��� Ȯ��
Bool Stack_IsFull(ArrStack* pStack); //������ ���� �� �ִ��� Ȯ��
#endif