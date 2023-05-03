//MyCircularQueue.hpp
#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //데이터 시작 위치(-1)
	int rear; //데이터 마지막 위치
	T* arr; //큐의 실질적 데이터 저장 공간
	int qSize; //큐의 길이를 저장
public:
	CircularQueue() { //기본 생성자
		front = 0;
		rear = 0;
		arr = new T[QUEUE_SIZE];
		qSize = QUEUE_SIZE;
	}
	CircularQueue(int size) {
		front = 0;
		rear = 0;
		arr = new T[size];
		qSize = size;
	}
	bool IsEmpty() {  //큐가 비어 있는지 확인
		if (front == rear)
			return true;
		else
			return false;
	}
	bool IsFull() {  //큐가 가득 차 있는지 확인
		if (front == ((rear + 1) % QUEUE_SIZE))
			return true;
		else
			return false;
	}
	bool Enqueue(T item) {  //큐에 데이터를 삽입
		if(IsFull() == true)
			return false;
		rear = (rear + 1) % QUEUE_SIZE;
		arr[rear] = item;
	}
	T Dequeue() {  //큐에서 데이터를 꺼냄
		if (IsEmpty() == true)
			return -1;
		front = (front + 1) % QUEUE_SIZE;
		
		return arr[front];
	}
	T Peek() {  //최상단 데이터를 확인
		return arr[front];
	}
	~CircularQueue() {
		delete[] arr;
	}
};
#endif

//main.cpp
#include <iostream>
#include "MyCircularQueue.hpp"
using namespace std;

int main(void) {
	CircularQueue<int> q;

	//데이터 삽입
	q.Enqueue(5); q.Enqueue(33);
	q.Enqueue(25); q.Enqueue(17);

	//전체 데이터 인출
	while (q.IsEmpty() == false) {
		printf("%d ", q.Dequeue());
	}

	return 0;
}


- 과제에 대한 고찰
단순 배열이 아닌 원형 배열로 구현한 이유는 데이터를 삭제할 때 배열에 빈 공간이 발생하게 된다.
빈 공간이 발생하면 데이터를 배열 앞으로 땡겨와야 하는데, 이 때 매번 리소스가 낭비되게 된다.
이를 해결하기위해 원형 배열 큐로 구현하였다.
하지만 원형 큐에서도 문제점이 발생한다. 큐가 full일 때와 empty일 경우 front와 rear의 위치가 같기 때문에
구별을 할 수 없게된다. 이를 해결하기 위해서 배열 큐를 한 칸 비워서 사용하였다.
원형 큐에서 데이터를 삽입할 때는 항상 최상단(front)에서 이루어지므로 수행시간은 O(1)이다.
수행공간은 원형 큐 배열의 길이에 비례한다.
하지만 이러한 배열 형태의 큐는 가변 크기 대응이 힘들다는 단점이 있다.

