#include <stdio.h>

#define MAX_ELEMENTS 8

typedef struct Element {
	int row;
	int col;
	int value;
} Element;

Element* Transpose_Triple2(Element S_a[]);
void Print_Sparse_Mat(Element arr[]);

int main()
{
	Element Sparse_A[MAX_ELEMENTS] =
	{ {6,6,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2} };

	Element* S_b = Transpose_Triple2(Sparse_A);

	printf("������ A \n");
	Print_Sparse_Mat(Sparse_A);
	printf("\n��ġ��� B \n");
	Print_Sparse_Mat(S_b);

	return 0;
}

//��������� ����ð��� ����� �ڷᱸ���� ���� ��ġ����� ���ϴ� �Լ�
Element* Transpose_Triple2(Element S_a[])
{
	int no = S_a[0].value;

	static Element S_b[MAX_ELEMENTS] = { {0} }; //S_b �迭 ����
	S_b[0].row = S_a[0].col; //6
	S_b[0].col = S_a[0].row; //6
	S_b[0].value = no; //7

	if (no > 0) {
		int row[6] = { 0 }; //row �迭 ����
		int pos[6] = { 0 }; //pos �迭 ����

		int i = 0;
		for (i = 1; i <= no; i++) { //���� ��Ŀ��� col�� ���� �� �� ���
			row[S_a[i].col] += 1;
		}

		pos[0] = 1; //�⺻ ��ġ
		for (i = 1; i < S_a[0].col; i++) { //pos �迭 ����
			pos[i] = pos[i - 1] + row[i - 1];
		}

		int abs_pos = 0; //pos �迭�� �ӽ� �����ϴ� ����
		for (i = 1; i <= no; i++) {
			abs_pos = pos[S_a[i].col];
			pos[S_a[i].col] += 1; //���ڰ� 2�� ������ ��� ���� for������ 
			//������ pos��ġ���� �� ĭ �ڿ� �����ϴ� ����
			S_b[abs_pos].row = S_a[i].col;
			S_b[abs_pos].col = S_a[i].row;      //S_a�� ��ġ��� S_b�� ���ϴ� ����
			S_b[abs_pos].value = S_a[i].value;
		}
	}

	return S_b;
}

//���ڷ� �� ����� 6x6 �迭 ���·� ������ִ� �Լ�
void Print_Sparse_Mat(Element arr[])
{
	int row = arr[0].row;
	int col = arr[0].col;
	int no = arr[0].value;
	int current = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((arr[current].row == i) && (arr[current].col == j)) {
				printf("%d ", arr[current].value);
				current++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}