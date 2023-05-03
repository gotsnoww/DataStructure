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
