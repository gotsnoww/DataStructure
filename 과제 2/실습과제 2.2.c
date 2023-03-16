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

	printf("희소행렬 A \n");
	Print_Sparse_Mat(Sparse_A);
	printf("\n전치행렬 B \n");
	Print_Sparse_Mat(S_b);

	return 0;
}

//수행공간과 수행시간을 고려한 자료구조를 통해 전치행렬을 구하는 함수
Element* Transpose_Triple2(Element S_a[])
{
	int no = S_a[0].value;

	static Element S_b[MAX_ELEMENTS] = { {0} }; //S_b 배열 생성
	S_b[0].row = S_a[0].col; //6
	S_b[0].col = S_a[0].row; //6
	S_b[0].value = no; //7

	if (no > 0) {
		int row[6] = { 0 }; //row 배열 생성
		int pos[6] = { 0 }; //pos 배열 생성

		int i = 0;
		for (i = 1; i <= no; i++) { //원본 행렬에서 col의 숫자 빈도 수 계산
			row[S_a[i].col] += 1;
		}

		pos[0] = 1; //기본 위치
		for (i = 1; i < S_a[0].col; i++) { //pos 배열 연산
			pos[i] = pos[i - 1] + row[i - 1];
		}

		int abs_pos = 0; //pos 배열을 임시 저장하는 변수
		for (i = 1; i <= no; i++) {
			abs_pos = pos[S_a[i].col];
			pos[S_a[i].col] += 1; //숫자가 2개 존재할 경우 다음 for문에서 
			//숫자의 pos위치보다 한 칸 뒤에 저장하는 역할
			S_b[abs_pos].row = S_a[i].col;
			S_b[abs_pos].col = S_a[i].row;      //S_a의 전치행렬 S_b를 구하는 구간
			S_b[abs_pos].value = S_a[i].value;
		}
	}

	return S_b;
}

//인자로 들어간 행렬을 6x6 배열 형태로 출력해주는 함수
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