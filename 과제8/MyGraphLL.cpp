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