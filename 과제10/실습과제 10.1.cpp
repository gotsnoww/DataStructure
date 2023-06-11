//MyGraphMST.h
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

//MyGraphMST.cpp
#include "MyGraphMST.h"
#include <limits.h>

//파일에 저장된 데이터로 가중치 그래프 구성
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES]) {
	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return;
	}
	while (1) {
		int i, j, w;
		int result = fscanf_s(file, "%d, %d, %d", &i, &j, &w);
		if (result == EOF) break;
		weight_mat[i][j] = w;
		weight_mat[j][i] = w;
	}
	fclose(file);

}
//출력함수
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n) {
	for (int i = -1; i < n; i++) {
		for (int j = -1; j < n; j++) {
			if (i == -1) {
				if (j != -1) printf("%2d ", j);
				else printf(" ");
			}
			else {
				if (j == -1) printf("%2d ", i);
				else
					if (weight_mat[i][j] == INT_MAX)
						printf("INF");
					else
						printf("%2d ",weight_mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
//프림 알고리즘 기반 최소비용 신장트리
void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n) {
	int* selected = new int[n]; //MST에 선택된 정점 표시
	for (int i = 0; i < n; i++)
		selected[i] = 0;
	selected[0] = 1;
	int edge_count = 0; //간선 개수 저장
	while (edge_count < (n - 1)) {
		int min = INT_MAX;
		int u = 0;
		int v = 0;
		for (int i = 0; i < n; i++) {
			if (selected[i] == 1) {
				for (int j = 0; j < n; j++) {
					if ((selected[j] == 0) && (min > weight_mat[i][j])) {
						min = weight_mat[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		selected[v] = 1;
		MST[u][v] = weight_mat[u][v];
		MST[v][u] = weight_mat[u][v];
		edge_count += 1;
	}
}

//main.c
#include "MyGraphMST.h"
#include <limits.h>

int main()
{
	const char* file = "g_file3.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int MST[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) {
				weight_mat[i][j] = INT_MAX;
				MST[i][j] = INT_MAX;
			}
		}
	}

	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("가중치 그래프: \n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	MST_Prim(weight_mat, MST, num_of_ver); //프림 알고리즘을 활용한 MST 구성
	printf("MST: \n");
	ADJ_Print_Array(MST, num_of_ver); //MST 행렬 출력

	return 0;
}


- 과제에 대한 고찰
이전 과제 9.1에서 사용한 무방향 그래프에 정점 간 간선에 비용(가중치)를 추가한 가중치 그래프를 사용한다. 가중치
그래프를 인접 행렬로 생성하고, 이 인접 행렬을 이용하여 가중치 그래프의 최소 비용 신장 트리(MST)를 구성한다. 이 때 최소
비용 신장 트리를 구성하는 방법에는 프림 알고리즘, 크루스칼 알고리즘 두 가지가 존재하는데, 위의 코드에서는 프림 알고리즘을
구현하여 가중치 그래프의 최소 비용 신장 트리를 구성한다. 최소 비용 신장 트리는 모든 정점을 지나야 하며 신장 트리에 포함하는
간선의 가중치 합이 최소가 되야하고, 두 정점 간의 경로가 반드시 존재해야 하는 트리이다. 시작 정점을 임의로 하나 선택하고
인접 정점 사이의 가중치중 가장 낮은 가중치를 가진 간선과 정점을 선택하여 MST에 추가한다. 프림 알고리즘에서는 edge_count라는
변수를 반복문의 조건으로 사용하여 모든 정점이 MST에 추가되면 종료 되도록 구현하였다.
프림 알고리즘의 수행시간은 O(n^3)으로, 인접 행렬을 구성하는 함수의 수행시간인 O(n^2)보다 크므로 위 코드의 전체 수행시간은
O(n^3)이 되겠다. 

