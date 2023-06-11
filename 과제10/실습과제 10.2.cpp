//MyGraphSP.h
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

//MyGraphSP.cpp
#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100

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
						printf("%2d ", weight_mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");

}
//최단거리 관련 함수
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path) {
	int* distance = new int[n];
	int* visited = new int[n];
	for (int i = 0; i < n; i++) {
		distance[i] = weight_mat[v][i];
		path[i] = v;
		visited[i] = 0;
	}

	visited[v] = 1; //정점 0에서 시작
	distance[v] = 0;
	int step = 1; //수행 횟수
	int k = 0;
	while (step < n) {
		int min = INT_MAX;
		for (int i = 0; i < n; i++) { //가장 가까운 정점 찾기
			if (visited[i] == 0 && distance[i] < min) {
				min = distance[i];
				k = i;
			}
		}
		visited[k] = 1; //방문
		for (int u = 0; u < n; u++) {
			if (visited[u] == 0) {
				if ((distance[k] + weight_mat[k][u]) < distance[u]) {
					if (weight_mat[k][u] == INT_MAX)
						continue;
					distance[u] = distance[k] + weight_mat[k][u];
					path[u] = k;
				}
			}
		}
		step += 1;
	}
	for (int i = 0; i < n; i++) {
		printf("정점 0 -> 정점 %d : %d\n", i, distance[i]);
	}
}

void PrintPath(int* path, int v, int u) {
	if (u == v) {
		printf("%d ", u);
		return;
	}
	PrintPath(path, v, path[u]);
	printf("-> %d ", u);
}

//main.c
#include "MyGraphSP.h"
#include <limits.h>
int main() {
	const char* file = "g_file4.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	int* path = new int[num_of_ver];

	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		path[i] = 0;
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) weight_mat[i][j] = INT_MAX;
		}
	}

	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("##가중치 그래프##\n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	printf("##최단 거리##\n");
	Shortest_Path(weight_mat, num_of_ver, 0, path); //최단거리 계산
	printf("\n##최단 거리 경로##\n");

	for (int i = 0; i < num_of_ver; i++) {
		PrintPath(path, 0, i); //시작 정점0부터 모든 정점 사이의 최단거리 경로
		printf("\n");
	}

	return 0;
}


- 과제에 대한 고찰
이번 과제 또한 이전 과제 10.1과 동일하게 가중치 그래프를 사용하여 인접 행렬로 생성하고 출력한다.
이 인접 행렬을 사용하여 가중치 그래프의 최단 경로를 찾는 코드이며 임의의 정점에서 다른 모든 정점으로
갈 수 있는 최단 경로를 계산하는 알고리즘인 다익스트라(Dijkstra) 알고리즘을 사용한다. 새로운 정점이
추가됐을 때 기존의 정점 간 경로(기존 경로)보다 새로운 정점을 경유하여 가는 경로(우회 경로)의 비용이
더 적다면 이를 최단 거리로 선택하는 방식이 사용된다. 따라서 배열을 사용하여 시작 정점에서 각 정점까지의
최단 거리를 배열에 저장하고, 정점들을 방문하면서 우회 경로가 기존 경로보다 비용이 적다면 배열의 값을
갱신하고, 방문한 정점의 값을 1로 변경시키는 visited 배열을 활용하여 다익스트라 알고리즘의 조건문의 조건으로
사용된다. 따라서 다익스트라 알고리즘을 활용하여 최단 거리를 계산하고, 이를 바탕으로 최단 경로까지 출력한다.
이렇게 구현된 코드는 가중치 그래프의 인접 행렬 n*n을 사용하여 동작하기 때문에, 시간복잡도는 O(n^2)이다. 

