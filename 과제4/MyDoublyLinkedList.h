#ifndef __MY_DOUBLY_LINKED_LIST_H__
#define __MY_DOUBLY_LINKED_LIST_H__
typedef struct Node { //Node 구조체
	int data; //데이터 필드
	struct Node* prev;// 다음 노드의 주소를 저장
	struct Node* next;// 다음 노드의 주소를 저장
}Node;
Node* DLL_Create_Node(int newData); //노드 생성
void DLL_Destroy_Node(Node* node); //노드 소멸
void DLL_Append_Node(Node** head, Node* newNode); //노드 추가
Node* DLL_Get_Node(Node* head, int pos); //노드 탐색
void DLL_Remove_Node(Node** head, Node* targetNode); //노드 삭제
void DLL_Insert_Node_After(Node* currentNode, Node* newNode); //노드 삽입
void DLL_Print_Linked_List(Node* head); //이중 연결리스트 출력
void DLL_Print_Linked_List_Reverse(Node* tail);//이중 연결리스트 역순 출력
#endif