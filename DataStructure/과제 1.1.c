/* 
�ǻ��ڵ�
Algorithm Transpose_Mat(int A[][MAT_SZIE], int B[][MAT_SIZE])
Input : nxn���� ���� ���� ����� �迭 A, B
for i <- 0 to MAT_SIZE do
	for j <- 0 to MAT_SIZE do
		B[i][j] = A[i][j]

Algorithm Print_MAT(int arr[][MAT_SIZE]);
Input : nxn���� ���� ���� ����� �迭
Output : nxn���� ���� ���� ����� �迭�� ��ġ���
for i <- 0 to MAT_SIZE do
	for j <- 0 to MAT_SIZE do
		arr[i][j]

�ð����⵵ O(n^2)
*/

#include <stdio.h>

#define MAT_SIZE 5 //�⺻ ���� �迭����

void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]);
void Print_MAT(int arr[][MAT_SIZE]);

int main() {
	int A[5][5] = //������ 5x5 ������ ������ �迭 A
	{{3,2,6,4,5},
	{8,3,5,9,1},
	{0,3,2,7,9},
	{2,1,5,2,4},
	{5,0,8,2,3}};

	int B[5][5] = { 0 }; //A�� ��ġ����� ���� �迭 B

	Transpose_Mat(A, B); //A�� ��ġ����� ���ؼ� �迭 B�� ����
	printf("�迭 A \n");
	Print_MAT(A); //�迭 A ���
	printf("\n�迭 A�� ��ġ��� �迭 B \n");
	Print_MAT(B); //�迭 B ���

	return 0;
}

//�迭 A�� ��ġ����� ���ؼ� �迭 B�� �����ϴ� �Լ�
void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++) {
		for (int j = 0; j < MAT_SIZE; j++) {
			B[i][j] = A[j][i];
		}
	}
}

//�迭 arr�� ����ϴ� �Լ�
void Print_MAT(int arr[][MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++) {
		for (int j = 0; j < MAT_SIZE; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}