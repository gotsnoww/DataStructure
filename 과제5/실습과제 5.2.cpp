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
		else if (token == '(')
			stack.Stack_Push(token);
		else if (token == ')') {
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