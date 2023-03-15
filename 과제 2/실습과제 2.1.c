
희소행렬 A의 전치행렬 B를 구하는 알고리즘.
Element 구조체를 이용한 새로운 자료구조를 통해서 기존 6x6 배열을 만들어내도록 동작한다.
전치행렬로 변환하는 함수와 6x6 배열을 출력하는 함수로 구성되어 있다.

#include <stdio.h>

#define MAX_ELEMENTS 8  //자료구조 길이 설정

typedef struct Element { //Element 구조체
	int row;
	int col;
	int value;
} Element;

Element* Transpose_Triple1(Element S_a[]);
void Print_Sparse_Mat(Element arr[]);

int main()
{
	Element Sparse_A[MAX_ELEMENTS] = //희소행렬 A
	{{6,6,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2}};

	Element* S_b = Transpose_Triple1(Sparse_A); //반환된 S_b 배열 저장

	printf("희소행렬 A \n");
	Print_Sparse_Mat(Sparse_A); //희소행렬 A 출력
	printf("\n전치행렬 B \n");
	Print_Sparse_Mat(S_b); //전치행렬 B 출력

	return 0;
}

Element* Transpose_Triple1(Element S_a[]) //희소행렬 A를 전치행렬 B로 변환하는 함수
{
	int no = S_a[0].value;
	
	static Element S_b[MAX_ELEMENTS] = { {0} }; //static 또는 메모리 동적할당 사용
	S_b[0].row = S_a[0].col;
	S_b[0].col = S_a[0].row;
	S_b[0].value = no;

	int current = 1;
	for (int i = 0; i < S_a[0].col; i++)
	{
		for (int j = 0; j <= no; j++)
		{
			//전치행렬로 변환하는 과정
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

void Print_Sparse_Mat(Element arr[]) //자료구조를 기존 6x6 배열로 출력하는 함수
{
	int row = arr[0].row;
	int col = arr[0].col;
	int no = arr[0].value;
	int current = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//자료구조의 알맞은 row, col 값에 위치할 때 value값 출력
			if ((arr[current].row == i) && (arr[current].col == j)) {
				printf("%d ", arr[current].value);
				current++;
			}
			//빈 칸은 0을 출력
			else
				printf("0 ");
		}
		printf("\n");
	}
}
	

과제에 대한 고찰 
