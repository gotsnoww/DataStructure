#pragma once
#ifndef __MY_GRAPH_MST_H__
#define __MY_GRAPH_MST_H__
#include <stdio.h>

#define MAX_VERTICES 100

//���Ͽ� ����� �����ͷ� ����ġ �׷��� ����
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES]);
//����Լ�
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n);
//���� �˰��� ��� �ּҺ�� ����Ʈ��
void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n);

#endif