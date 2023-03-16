
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
	

- 과제에 대한 고찰 
이번 과제 2.1에서는 새로운 형태의 코드들이 많이 사용됐다.
Element 구조체를 사용한 배열이라던지, 희소행렬을 전치행렬로 변환하는 과정에서 사용된 것들이 지금까지는 잘 보지 못했던 형태였던 것 같다.
하지만 내용자체는 분석이 쉽게 되었기 때문에 금방 해결할 수 있었다.
Transpose_Triple 함수에서 S_b 배열을 생성할 때는 조금 까다로운 부분이 있었다.
static함수를 사용하거나 메모리 동적할당을 사용해야 했는데 동적할당을 하는 것으로는 잘 해결되지 않아서 static함수를 사용했다.
반환한 S_b 배열을 main함수에서 받는 과정에서도 element 구조체 포인터를 사용해서 받는 것을 검색해보아서 알게 되었다.
과제 하나를 해결해가면서도 얻어가는 것이 많아 되게 도움이 된 것 같다.
