#include <iostream>
#include "MyMaxHeapTree.h"
using namespace std;

//���� Ʈ�� ��� �Լ�
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) {
	if (idx > size) return;
	M[row][col] = bTree[idx];
	PrintTree2Matrix(M, bTree, size, idx * 2, col - pow(2, height - 2), row + 1, height - 1);
	PrintTree2Matrix(M, bTree, size, idx * 2 + 1, col + pow(2, height - 2), row + 1, height - 1);
}
void TreePrinter(int* bTree, int size) {
	int h = (int)ceil(log2(size + 1));
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	PrintTree2Matrix(M, bTree, size, 1, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");
			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col ; j++) {
		printf("==");
	}
	printf("\n");
}

//�ִ� �� Ʈ�� ���� �Լ�
void Max_Heap_Insert(int* heap, int* h_size, int key) {
	*h_size = *h_size + 1;
	int index = *h_size;
	
	while (index != 1) { //��Ʈ ������ ��
		if (key > heap[index / 2]) { //�����庸�� ���� Ŭ ���
			heap[index] = heap[index / 2];
			index /= 2;
		}
		else break;
	}
	heap[index] = key;
}
//�ִ� �� Ʈ�� ���� �Լ�
int Max_Heap_Remove(int* heap, int* h_size)
{

}
