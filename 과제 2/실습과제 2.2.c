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
	{{6,6,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2}};

	Element* S_b = Transpose_Triple2(Sparse_A);

	printf("희소행렬 A \n");
	Print_Sparse_Mat(Sparse_A);
	printf("\n전치행렬 B \n");
	Print_Sparse_Mat(S_b);

	return 0;
}

Element* Transpose_Triple2(Element S_a[])
{
	int no = S_a[0].value;

	static Element S_b[MAX_ELEMENTS] = { {0} };
	S_b[0].row = S_a[0].col;
	S_b[0].col = S_a[0].row;
	S_b[0].value = no;

	int current = 1;
	for (int i = 0; i < S_a[0].col; i++)
	{
		for (int j = 0; j <= no; j++)
		{
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