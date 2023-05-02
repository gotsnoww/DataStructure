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
