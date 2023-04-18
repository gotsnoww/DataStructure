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
	char exp[] = "(2+5)*(3+4)-(2+(7-5))"; //������
	char* postfix = new char[strlen(exp) + 1]; //������ ��ȯ ���
	//1) �����Ŀ��� ���������� ��ȯ
	Infix2Postfix(exp, postfix);
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix);
	//2) ��ȯ�� �������� ���
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);

	return 0;
}

//������ -> ������ ��ȯ �Լ�
void Infix2Postfix(const char* infix_exp, char* postfix_exp)
{
	ArrStack<char> stack;

	int len = strlen(infix_exp);
	char token;
	int i = 0;
	for (int j = 0; j < len; j++) {
		token = infix_exp[j];

		if (IsDigit(token) == 1) { //token�� �ǿ������� ��
			postfix_exp[i] = token;
			i++;
		}
		else if (IsOperator(token) == 2) { //token�� �������� ��
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
			stack.Stack_Pop(); //���ÿ� ����� ')' pop
		}
	}

	//stack�� ���� �ִ� ������ ���
	while (!stack.Stack_IsEmpty()) {
		postfix_exp[i] = stack.Stack_Pop();
		i++;
	}
	postfix_exp[i] = NULL;
}
int IsDigit(char token) //token�� �������� Ȯ��
{
	//token�� 0~9������ �����̸� ���� 1 ��ȯ
	for (int i = 48; i <= 57; i++) { //ascii �ڵ� ǥ �̿�
		if (token == i)
			return 1;
	}

	return -1;
}
int IsOperator(char token) //token�� ���������� Ȯ��
{
	//token�� �����ڶ�� ���� 2 ��ȯ
	if (token == 42 || token == 43 || token == 45 || token == 47)
		return 2;

	return -1;
}
int Priority(char op) //�������� �켱���� Ȯ��
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
int Eval_Postfix(char* postfix_exp) //������ ��� �� ���
{
	ArrStack<char> stack;
	
	int len = strlen(postfix_exp);
	char token;
	int op1, op2, result;
	for (int i = 0; i < len; i++) {
		token = postfix_exp[i];
		if (IsDigit(token) == 1) { //token�� �ǿ������� ���
			token = token - '0';
			stack.Stack_Push(token);
		}
		else if (IsOperator(token) == 2) { //token�� �������� ���
			op2 = stack.Stack_Pop();
			op1 = stack.Stack_Pop();
			switch (token) { //�����ڿ� ���� ����
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