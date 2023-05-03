#include <iostream>
#include "MyMaxHeapTree.h"
using namespace std;

//이진 트리 출력 함수
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

//최대 힙 트리 삽입 함수
void Max_Heap_Insert(int* heap, int* h_size, int key) {
	*h_size = *h_size + 1;
	int index = *h_size;
	
	while (index != 1) { //루트 노드까지 비교
		if (key > heap[index / 2]) { //조상노드보다 값이 클 경우
			heap[index] = heap[index / 2];
			index /= 2;
		}
		else break;
	}
	heap[index] = key;
}
//최대 힙 트리 삭제 함수
int Max_Heap_Remove(int* heap, int* h_size)
{

}
