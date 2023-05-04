//MyMaxHeapTree.h
#pragma once
#ifndef __MY_MAX_HEAP_TREE_HPP__
#define __MY_MAX_HEAP_TREE_HPP__

#include <cstdlib>
#include <cstdio>
#include <cmath>

//이진트리 출력 함수
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height);
void TreePrinter(int* bTree, int size);

//최대 힙 트리 삽입/삭제 함수
void Max_Heap_Insert(int* heap, int* h_size, int key);
int Max_Heap_Remove(int* heap, int* h_size);

#endif

//MyMaxHeapTree.cpp
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
	int deleted_key = heap[1]; //루트 노드의 key 값 저장
	heap[1] = heap[*h_size]; //루트 노드에 마지막 노드 값 저장
	*h_size = *h_size - 1;
	int parent = 1;
	int index = 2;
	
	int temp;
	while (index <= *h_size) {
		if ((index < *h_size) && (heap[index + 1] > heap[index]))
			index += 1; //오른쪽 자식이 더 클 경우 오른쪽 자식으로 변경
		if (heap[parent] >= heap[index]) break; //부모가 자식보다 클 경우 종료
		temp = heap[parent]; //부모 자식 swap
		heap[parent] = heap[index];
		heap[index] = temp;
		parent = index; //부모 값 업데이트
		index *= 2; //자식으로 이동
	}

	return deleted_key;
}

//main.c
#include "MyMaxHeapTree.h"
#define MAX_HEAP_SIZE 20
int main()
{
	int maxHeap[MAX_HEAP_SIZE] = { 0, 35, 15, 30, 13, 9, 18, 10, 7, 4, 3, };
	int size = 10;

	TreePrinter(maxHeap, size); //기본 최대 힙 트리 출력
	Max_Heap_Insert(maxHeap, &size, 50); //키값 50 삽입
	TreePrinter(maxHeap, size); //삽입 결과 확인
	int tmp = Max_Heap_Remove(maxHeap, &size); //최대 힙 삭제 연산
	TreePrinter(maxHeap, size); //삭제 연산 결과 확인

	printf("Deleted Key: %d\n", tmp); //삭제된 결과 출력

	return 0;
}


- 과제에 대한 고찰
과제로 구현한 최대 힙 트리는 완전 이진 트리로 구성된 트리이며, 부모 노드의 키 값은
자식 노드의 키 값보다 크거나 같다. 왼쪽 자식과 오른쪽 자식의 키 값은 크기 구분 하지 않는다.
그렇기에 노드 추가, 삭제 알고리즘을 구현할 때 부모와 자식의 키 값을 비교하며 노드를 
서로 swap 해주는 방식으로 구현하였다.
구현된 최대 힙 트리는 완전 이진 트리이기 때문에 키 값의 수가 n이라고 하면 수행시간은
O(logn)이 된다. 수행공간은 최대 힙 트리의 크기에 비례한다.
이러한 최대 힙 트리는 노드의 키 값의 최대값이나 최소값을 찾아내는데 있어서 매우 적합한 자료구조인 것 같다.
