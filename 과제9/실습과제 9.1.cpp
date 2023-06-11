//MyGraphLL.h
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

//MyGraphLL.h
#include <iostream>
#include "MyGraphLL.h"

//그래프 각 정점의 차수 계산 함수
void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n) {
	for (int i = 0; i < n; i++) {
		int degree = 0;
		for (int j = 0; j < n; j++)
			degree = degree + adj_mat[i][j];
		printf("정점 %2d의 차수: %2d\n", i, degree);
	}
}
//인접 행렬로 표현된 그래프를 인접 리스트로 변환 함수
void ADJ_Insert(G_Node** List, int i, int j) {
	G_Node* newNode = (G_Node*)malloc(sizeof(G_Node));
	newNode->vertex = j;
	newNode->link = List[i];
	List[i] = newNode;
}
void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj_mat[i][j] == 1)
				ADJ_Insert(List, i, j);
		}
	}
}
//인접 리스트로 표현된 그래프를 순회하여 각 정점 방문
//깊이 우선 탐색
void Graph_DFS(G_Node** List, int v) {
	ArrStack <int> stack;
	int current = v;
	int visited[MAX_VERTICES] = { 0 };
	visited[current] = 1;
	printf("%2d", current);
	do{
		bool vFlag = false; //방문 여부 저장
		if (visited[current] == 0) { //방문 한적 없는 정점
			printf("%2d", current);
			visited[current] = 1;
			vFlag = true;
		}
		else { //방문 한적 있는 정점
			G_Node* iter = List[current];
			while (iter != NULL) {
				if (visited[iter->vertex] == 0) {
					stack.Stack_Push(current);
					current = iter->vertex;
					vFlag = true;
					break;
				}
				iter = iter->link;
			}
		}
		if (vFlag == false) {
			if (stack.Stack_IsEmpty())
				break;
			else
				current = stack.Stack_Pop();
		}
	} while (!stack.Stack_IsEmpty());
	printf("\n");
}
void Graph_DFS_Recursive(G_Node** List, int v) {
	static int visited[MAX_VERTICES] = { 0 };
	G_Node* iter = List[v];
	visited[v] = 1;
	printf("%2d", v);
	while (iter != NULL) {
		int temp = iter->vertex;
		if (visited[temp] == 0) 
			Graph_DFS_Recursive(List, temp);
		iter = iter->link;
	}
} 

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES])
{
	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return;
	}
	while (1) {
		int i, j;
		int result = fscanf_s(file, "%d, %d", &i, &j);
		if (result == EOF) break;
		adj_mat[i][j] = 1;
		adj_mat[j][i] = 1;
	}
	fclose(file);
}
void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n)
{
	for (int i = -1; i < n; i++) {
		for (int j = -1; j < n; j++) {
			if (i == -1) {
				if (j != -1) printf("%2d ", j);
				else printf(" ");
			}
			else {
				if (j == -1) printf("%2d ", i);
				else printf("%2d ", adj_mat[i][j]);
			}
		}
		printf("\n");
	}
}
void ADJ_Print_List(G_Node** List, int n)
{
	for (int i = 0; i < n; i++) {
		G_Node* iter = List[i];
		printf("Vertex %2d: ", i);
		while (iter != NULL) {
			printf("%2d ", iter->vertex);
			iter = iter->link;
		}
		printf("\n");
	}
}

//main.c
#include <iostream>
#include "MyGraphLL.h"

int main()
{
	const char* file = "g_file.txt";
	int adj_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	G_Node** List = new G_Node * [num_of_ver]; //인접 리스트 헤더 포인터 배열 생성

	for (int i = 0; i < num_of_ver; i++) 
		List[i] = NULL; //NULL로 초기화

	ADJ_Create(file, adj_mat); //0) 그래프를 인접 행렬로 생성
	ADJ_Print_Array(adj_mat, num_of_ver); //인접 행렬 출력
	ADJ_Degree(adj_mat, num_of_ver); //1) 그래프의 각 정점의 차수 계산
	ADJ_Mat2List(adj_mat, num_of_ver, List); //2) 인접 행렬 → 인접 리스트로 변환
	ADJ_Print_List(List, num_of_ver); //인접 리스트 출력
	Graph_DFS(List, 1); //3) 깊이 우선 탐색 (반복문)
	Graph_DFS_Recursive(List, 1); //3) 깊이 우선 탐색 (재귀문)

	delete[] List;

	return 0;
}


- 과제에 대한 고찰
그래프의 인접행렬을 생성하고, 이를 인접리스트로 변환 후 그래프를 순회하여 각 정점을 방문하는
코드를 구현하였다. 그래프를 순회하며 정점을 방문하는 탐색 기법은 깊이 우선 탐색(DFS)과 너비 우선 탐색
(BFS)으로 나뉜다. 깊이 우선 탐색은 한 방향으로 갈 수 있을 때까지 가보는 방식이며, 너비 우선 탐색은
현재 정점에서 연결된 모든 정점부터 방문하는 방식으로 둘의 성질이 매우 다르다. 위의 코드에서는 깊이
우선 탐색(DFS)을 구현하여 그래프의 정점을 순회하였다. 깊이 우선 탐색에서는 스택 자료구조를 활용하여 동작한다.
구현된 코드의 인접행렬을 표현하는 함수의 수행시간은 O(n^2)으로, 2차원 행렬을 그래프로 표현한 형태이기 때문에
n*n의 시간복잡도가 적용된다. 그래프의 인접리스트를 표현하는 함수는 일차원 배열 형태에서 이루어지기 때문에
수행시간은 O(노드의수 + 간선의수)가 된다. 따라서 최종 수행 시간은 O(n^2)이 되겠다.

