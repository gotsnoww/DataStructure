#pragma once
#ifndef __MY_GRAPH_SP_H__
#define __MY_GRAPH_SP_H__
#include <stdio.h>
#define MAX_VERTICES 100
//파일에 저장된 데이터로 가중치 그래프 구성
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES]);
//출력함수
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n);
//최단거리 관련 함수
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path);
void PrintPath(int* path, int v, int u);
#endif