//기말고사 시험 범위: 스택기초 ~ 그래프기초
//지필고사 손코딩, 비어있는 빈칸 채우기

#include <stdio.h>

#define VERTEX 7
#define SIZE 10

int queue[SIZE];
int front = 0, rear = 0;

void Insert_edge(int v_mat[VERTEX][VERTEX], int start, int end) {
	v_mat[start][end] = 1; //무방향 그래프
	v_mat[end][start] = 1;
}
void Dfs(int v_mat[VERTEX][VERTEX], int v, int visited[]) {
	visited[v] = 1; //현재 방문한 정점 기록
	printf("%3d ->", v);
	for (int w = 0; w < VERTEX; w++) { //중요
		if (v_mat[v][w] && !visited[w]) { //조건2개
			Dfs(v_mat, w, visited);
		}
	}
}
void Enq(int v) {
	if ((rear + 1) % SIZE == front) {
		return; //큐가 가득찼을 때
	}
	rear = (rear + 1) % SIZE;
	queue[rear] = v;
}
int Is_empty() {
	return front == rear;
}
int Deq() {
	if (Is_empty())
	{
		return -1;
	}
	front = (front + 1) % SIZE;
	return queue[front];
}
void Bfs(int v_mat[VERTEX][VERTEX], int v, int visited[]) {
	visited[v] = 1;
	printf("%3d -> ", v);
	Enq(v);
	while (!Is_empty())
	{
		v = Deq();
		for (int w = 0; w < VERTEX; w++) {
			if (v_mat[v][w] && !visited[w]) {
				visited[w] = 1;
				Enq(w);
				printf("%3d ->", w);
			}
		}
	}
}

void main() {
	int v_mat[VERTEX][VERTEX] = { 0 };
	int dfs_visited[VERTEX] = { 0 };
	int bfs_visited[VERTEX] = { 0 };

	Insert_edge(v_mat, 0, 1); //그래프 생성
	Insert_edge(v_mat, 0, 2);
	Insert_edge(v_mat, 1, 3);
	Insert_edge(v_mat, 1, 4);
	Insert_edge(v_mat, 2, 3);
	Insert_edge(v_mat, 2, 5);
	Insert_edge(v_mat, 3, 4);
	Insert_edge(v_mat, 3, 5);
	Insert_edge(v_mat, 4, 6);
	Insert_edge(v_mat, 5, 6);

	printf("깊이 우선 : ");
	Dfs(v_mat, 3, dfs_visited); //깊이우선탐색

	printf("\n너비 우선 : ");
	Bfs(v_mat, 3, bfs_visited); //너비우선탐색
}
