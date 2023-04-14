#include <stdio.h>
#include <string.h>

#define Max_Size 100
typedef double element;
element stack[Max_Size];
int top = -1;

int isFull() {
	return top == Max_Size - 1;
}
int isEmpty() {
	return top == -1;
}

void PUSH(element item) {
	if (isFull()) {
		printf("������ ����!!!\n");
		return;
	}
	top++;
	stack[top] = item;
}
element POP() {
	if (isEmpty()) {
		printf("������ �����!\n");
		return -1;
	}
	element temp = stack[top];
	top--;
	return temp;
}

void Rp(char* postfix, int* p_index) {
	char temp;
	while (1) {
		temp = POP();
		if (temp != '(') {
			postfix[*p_index] = temp;
			(*p_index)++;
		}
		else {
			break;
		}
	}
}

int E(char temp) {
	switch (temp) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
		break;
	}
}

void Oper(char* postfix, int* p_index, char temp)
{
	while (1) { //�������� �켱���� ����
		if (E(temp) <= E(stack[top])) {
			postfix[*p_index] = POP();
			(*p_index)++;
		}
		else
			break;
	}

	PUSH(temp);
}
void Infix_to_Postfix(char* infix, char* postfix) {
	char temp;
	int p_index = 0;

	for (int k = 0; k < strlen(infix); k++) {
		temp = infix[k];

		switch (temp)
		{
		case '(':
			PUSH(temp);
			break;
		case ')':
			Rp(postfix, &p_index);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			Oper(postfix, &p_index, temp);
			break;
		default:
			postfix[p_index] = temp;
			p_index++;
			break;
		}
	}

	//stack�� �����ִ� ������
	while (top != -1) {
		postfix[p_index] = POP();
		p_index++;
	}
	postfix[p_index] = '\0';
}

double Result(char* postfix) {
	element A, B;
	char temp;

	for (int k = 0; k < strlen(postfix); k++) {
		temp = postfix[k];

		if (temp >= '0' && temp <= '9')
		{
			PUSH(temp - '0');
		}
		else
		{
			//A+B, A*B
			B = POP();
			A = POP();

			switch (temp)
			{
			case '+':
				PUSH(A + B);
				break;
			case '-':
				PUSH(A - B);
				break;
			case '*':
				PUSH(A * B);
				break;
			case '/':
				PUSH(A / B);
				break;
			default:
				break;
			}
		}
	}

	return POP();
}

int main() {
	//   ������             ������
	char infix[Max_Size], postfix[Max_Size];

	while (1) {
		printf("������ �Է�: ");
		scanf("%s", infix);

		Infix_to_Postfix(infix, postfix);
		printf("������ : %s\n", postfix);

		printf("��� : %lf\n", Result(postfix));
	}

	return 0;
}