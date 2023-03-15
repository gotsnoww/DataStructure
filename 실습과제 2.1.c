#include <stdio.h>

#define MAX_ELEMENTS 8  //�ڷᱸ�� ���� ����

typedef struct Element { //Element ����ü
	int row;
	int col;
	int value;
} Element;

Element* Transpose_Triple1(Element S_a[]);
void Print_Sparse_Mat(Element arr[]);

int main()
{
	Element Sparse_A[MAX_ELEMENTS] = //������ A
	{{6,6,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2}};

	Element* S_b = Transpose_Triple1(Sparse_A); //��ȯ�� S_b �迭 ����

	printf("������ A \n");
	Print_Sparse_Mat(Sparse_A); //������ A ���
	printf("\n��ġ��� B \n");
	Print_Sparse_Mat(S_b); //��ġ��� B ���

	return 0;
}

Element* Transpose_Triple1(Element S_a[]) //������ A�� ��ġ��� B�� ��ȯ�ϴ� �Լ�
{
	int no = S_a[0].value;
	
	static Element S_b[MAX_ELEMENTS] = { {0} }; //static �Ǵ� �޸� �����Ҵ� ���
	S_b[0].row = S_a[0].col;
	S_b[0].col = S_a[0].row;
	S_b[0].value = no;

	int current = 1;
	for (int i = 0; i < S_a[0].col; i++)
	{
		for (int j = 0; j <= no; j++)
		{
			//��ġ��ķ� ��ȯ�ϴ� ����
			if (S_a[j].col == i) {
				S_b[current].row = S_a[j].col;
				S_b[current].col = S_a[j].row;
				S_b[current].value = S_a[j].value;
				current++;
			}
		}
	}

	return S_b;
}

void Print_Sparse_Mat(Element arr[]) //�ڷᱸ���� ���� 6x6 �迭�� ����ϴ� �Լ�
{
	int row = arr[0].row;
	int col = arr[0].col;
	int no = arr[0].value;
	int current = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//�ڷᱸ���� �˸��� row, col ���� ��ġ�� �� value�� ���
			if ((arr[current].row == i) && (arr[current].col == j)) {
				printf("%d ", arr[current].value);
				current++;
			}
			//�� ĭ�� 0�� ���
			else
				printf("0 ");
		}
		printf("\n");
	}
}