#ifndef __MY_GRAPH_LL_H__
#define __MY_GRAPH_LL_H__
#include <stdio.h>
#include "MyArrayStack.hpp"

#define MAX_VERTICES 100

typedef struct G_Node { //Node 구조체
	int vertex; //데이터 필드
	struct G_Node* link; // 다음 노드의 주소를 저장
}G_Node;

//0) 파일에 저장된 데이터로 그래프 구성
void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]);
//1) 정점별 차수 출력
void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n);
//2) 인접 행렬 → 인접 리스트 변환
void ADJ_Insert(G_Node** List, int i, int j);
void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List);
//3) 깊이 우선 탐색
void Graph_DFS(G_Node** List, int v);
void Graph_DFS_Recursive(G_Node** List, int v);

//출력함수 모음
void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n);
void ADJ_Print_List(G_Node** List, int n);
#endif