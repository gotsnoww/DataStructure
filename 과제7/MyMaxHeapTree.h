#pragma once
#ifndef __MY_MAX_HEAP_TREE_HPP__
#define __MY_MAX_HEAP_TREE_HPP__

#include <cstdlib>
#include <cstdio>
#include <cmath>

//����Ʈ�� ��� �Լ�
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height);
void TreePrinter(int* bTree, int size);

//�ִ� �� Ʈ�� ����/���� �Լ�
void Max_Heap_Insert(int* heap, int* h_size, int key);
int Max_Heap_Remove(int* heap, int* h_size);

#endif
