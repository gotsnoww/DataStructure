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