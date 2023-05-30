#pragma once
#ifndef __MY_GRAPH_SP_H__
#define __MY_GRAPH_SP_H__
#include <stdio.h>
#define MAX_VERTICES 100
//���Ͽ� ����� �����ͷ� ����ġ �׷��� ����
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES]);
//����Լ�
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n);
//�ִܰŸ� ���� �Լ�
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path);
void PrintPath(int* path, int v, int u);
#endif