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
