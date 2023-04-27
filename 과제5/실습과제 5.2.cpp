//MyArrayStack.hpp
#pragma once
#ifndef __MY_ARRAY_STACKK_HPP__
#define __MY_ARRAY_STACKK_HPP__
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
template <typename T> //템플릿
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
	void Stack_Init() //스택 초기화
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

//main.c
#include <iostream>
#include <string>
#include "MyArrayStackk.hpp"
using namespace std;

void Infix2Postfix(const char* infix_exp, char* postfix_exp);
int IsDigit(char token);
int IsOperator(char token);
int Priority(char op);
int Eval_Postfix(char* postfix_exp);

int main() {
	char exp[] = "(2+5)*(3+4)-(2+(7-5))"; //중위식
	char* postfix = new char[strlen(exp) + 1]; //후위식 변환 결과
	//1) 중위식에서 후위식으로 변환
	Infix2Postfix(exp, postfix);
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix);
	//2) 변환된 후위식을 계산
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);

	return 0;
}

//중위식 -> 후위식 변환 함수
void Infix2Postfix(const char* infix_exp, char* postfix_exp)
{
	ArrStack<char> stack;

	int len = strlen(infix_exp);
	char token;
	int i = 0;
	for (int j = 0; j < len; j++) {
		token = infix_exp[j];

		if (IsDigit(token) == 1) { //token이 피연산자일 때
			postfix_exp[i] = token;
			i++;
		}
		else if (IsOperator(token) == 2) { //token이 연산자일 때
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek()))
			{
				postfix_exp[i] = stack.Stack_Pop();
				i++;
			}

			stack.Stack_Push(token);
		}
		else if (token == '(') //token이 ( 일 때
			stack.Stack_Push(token);
		else if (token == ')') { //token이 )일 때
			while (stack.Stack_Peek() != '(') {
				postfix_exp[i] = stack.Stack_Pop();
				i++;
			}
			stack.Stack_Pop(); //스택에 저장된 ')' pop
		}
	}

	//stack에 남아 있는 연산자 출력
	while (!stack.Stack_IsEmpty()) {
		postfix_exp[i] = stack.Stack_Pop();
		i++;
	}
	postfix_exp[i] = NULL;
}
int IsDigit(char token) //token이 숫자인지 확인
{
	//token이 0~9사이의 숫자이면 숫자 1 반환
	for (int i = 48; i <= 57; i++) { //ascii 코드 표 이용
		if (token == i)
			return 1;
	}

	return -1;
}
int IsOperator(char token) //token이 연산자인지 확인
{
	//token이 연산자라면 숫자 2 반환
	if (token == 42 || token == 43 || token == 45 || token == 47)
		return 2;

	return -1;
}
int Priority(char op) //연산자의 우선순위 확인
{
	//우선순위 순으로 높은 숫자 할당
	char pri;
	switch (op) {
	case '*':
	case '/':
		pri = 3;
		break;
	case '+':
	case '-':
		pri = 2;
		break;
	case '(':
		pri = 1;
		break;
	default:
		pri = -1; break;
	}

	return pri;
}
int Eval_Postfix(char* postfix_exp) //후위식 계산 및 결과
{
	ArrStack<char> stack;
	
	int len = strlen(postfix_exp);
	char token;
	int op1, op2, result;
	for (int i = 0; i < len; i++) {
		token = postfix_exp[i];
		if (IsDigit(token) == 1) { //token이 피연산자인 경우
			token = token - '0';
			stack.Stack_Push(token);
		}
		else if (IsOperator(token) == 2) { //token이 연산자인 경우
			op2 = stack.Stack_Pop();
			op1 = stack.Stack_Pop();
			switch (token) { //연산자에 따른 연산
			case '+': 
				result = op1 + op2; break;
			case '-':
				result = op1 - op2; break;
			case '/':
				result = op1 / op2; break;
			case '*':
				result = op1 * op2; break;
			}
			stack.Stack_Push(result);
		}
	}

	return stack.Stack_Pop();
}


- 과제에 대한 고찰
이전 과제와 동일한 배열 스택을 사용하여 중위식을 후위식으로 변환하여 계산하는 코드를 구현하였다.
대신 다른점은 구조체가 아닌 c++의 class가 사용되었다.
과제 5.1에서 사용했던 함수는 그대로 class의 public 공간에 멤버 함수로 구현하였다.
메인함수에서는 중위식을 후위식으로 변환하는 함수와 후위식을 계산하고 출력하는 함수가 주가 되어 동작한다.
부가적인 함수로는 연산자의 우선순위 판단, token의 값이 연산자인지 정수인지 판단하는 함수가 존재한다.
이렇게 동작하는 프로그램의 수행공간과 수행시간은 중위식의 길이에 비례한다.
이번 과제 또한 이전 과제와 같이 배열을 이용한 스택 자료구조이기 때문에, 사용자가 직접 중위식의 길이에 따라
배열의 크기를 지정해줘야 한다는 단점이 존재한다.
