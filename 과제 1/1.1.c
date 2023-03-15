/* 
의사코드
Algorithm Transpose_Mat(int A[][MAT_SZIE], int B[][MAT_SIZE])
Input : nxn개의 정수 값이 저장된 배열 A, B
for i <- 0 to MAT_SIZE do
	for j <- 0 to MAT_SIZE do
		B[i][j] = A[i][j]

Algorithm Print_MAT(int arr[][MAT_SIZE]);
Input : nxn개의 정수 값이 저장된 배열
Output : nxn개의 정수 값이 저장된 배열의 전치행렬
for i <- 0 to MAT_SIZE do
	for j <- 0 to MAT_SIZE do
		arr[i][j]

시간복잡도 O(n^2)
*/

#include <stdio.h>

#define MAT_SIZE 5 //기본 설정 배열길이

void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]);
void Print_MAT(int arr[][MAT_SIZE]);

int main() {
	int A[5][5] = //임의의 5x5 정수로 설정된 배열 A
	{{3,2,6,4,5},
	{8,3,5,9,1},
	{0,3,2,7,9},
	{2,1,5,2,4},
	{5,0,8,2,3}};

	int B[5][5] = { 0 }; //A의 전치행렬을 담을 배열 B

	Transpose_Mat(A, B); //A의 전치행렬을 구해서 배열 B로 복사
	printf("배열 A \n");
	Print_MAT(A); //배열 A 출력
	printf("\n배열 A의 전치행렬 배열 B \n");
	Print_MAT(B); //배열 B 출력

	return 0;
}

//배열 A의 전치행렬을 구해서 배열 B에 저장하는 함수
void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++) {
		for (int j = 0; j < MAT_SIZE; j++) {
			B[i][j] = A[j][i];
		}
	}
}

//배열 arr을 출력하는 함수
void Print_MAT(int arr[][MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++) {
		for (int j = 0; j < MAT_SIZE; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
