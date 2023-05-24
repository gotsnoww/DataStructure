#pragma once
#ifndef __MY_GRAPH_MST_H__
#define __MY_GRAPH_MST_H__
#include <stdio.h>

#define MAX_VERTICES 100

//파일에 저장된 데이터로 가중치 그래프 구성
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES]);
//출력함수
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n);
//프림 알고리즘 기반 최소비용 신장트리
void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n);

#endif