#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "CircularQueue.h"
using namespace std;

//User List

template<typename T>
class DNode{
public:
    DNode *prev; //왼쪽
    T data;     //가운데
    DNode *next; //오른쪽
};

/*
 ==================================== Doubly Linked List ====================================
 */
template<typename T>
class DLinkedList: public CircularQueue<T>{
private:
    int m_Length;
    DNode<T>* head;  //헤드의 더미노드를 위해.
    DNode<T>* tail;  //테일의 더미노드를 위해.
    DNode<T>* cur;   //현재 노드를 가리키는 부분 (삭제, 검색, 치환에 쓸 것)
public:
    DLinkedList();
    /*
     양 끝에 더미노드를 만들어주기 위해 head와 tail 노드를 만들고
     각각 prev와 next부분을 NULL로 만들어주고
     서로의 노드를 가리키에 하여 생성자 호출시 초기화되도록 만들어주었습니다.
     */
    ~DLinkedList();
    /*
     소멸자의 경우 MakeEmpty()함수를 통해 소멸의 과정을 표현하고 해당 함수를 호출하였습니다.
     */
    void MakeEmpty();
    /*
     head 부분을 기준으로 하여 NULL이 아니면 반복되도록 하였고
     temp에 담아 복사하고 delete해주어 모든 노드를 탐색해
     소멸시켜주었습니다.
     */
    
    int GetLength();
    void ResetList();
    /*
     더미노드를 가리키기 위해 cur 포인터를 초기화 시켜주는 내용입니다.
     */
    void GetCurItem(T& data);
    /*
     cur포인터를 이용하여 현재 노드를 가리키기 위한 내용입니다.
     */
    bool IsFull();
    /*
     현재 가리키는 노드의 다음주소가 NULL이면 마지막 tail의 노드를 가리키는 것이므로
     이 상태가 가득 찬 상태라고 판단하였습니다.
     */
    bool IsEmpty();
    /*
     head와 tail의 노드가 서로를 가리킬 때를 초기 상태라 생각하여
     조건을 다음과 같이 설정해주었습니다. m_Length == 0이라 해도 된다고 생각합니다.
     */
    
    int Add(T data);
    /*
     Singer list를 관리하기 위한 List인데,
     가수와 그에 대한 곡정보가 담겨져만 있으면 된다고 생각하였고
     정렬이 필요없다고 생각하여 다음과 같이 Unsorted형태로 작성하였습니다.
     */
    int Delete(T& data);
    /*
     특정 노드를 제거하고 싶을 경우 사용되는 내용입니다.
     */
    int Get(T& data);
    /*
     특정 노드를 검색할 때 쓰는 내용입니다.
     */
    int Replace(T& data);
    /*
     특정 노드를 내가 원하는 방식으로 수정하고 싶을 때 사용합니다.
     */

};

template<typename T>
DLinkedList<T>::DLinkedList(){
    m_Length = 0;
    head = new DNode<T>;
    tail = new DNode<T>;
    
    head->prev= tail->next = NULL;  //더미노드의 양끝은 NULL값으로 지정.
    head->next = tail;      //head의 next에 tail 노드의 주소를 저장.
    tail->prev = head;      //tail의 prev에 head 노드의 주소를 저장.
    cur = NULL;
}
template<typename T>
DLinkedList<T>::~DLinkedList(){
    MakeEmpty();
}

template <typename T>
void DLinkedList<T>::MakeEmpty(){
    DNode<T>* temp = head;
    
    while(head != NULL){
        head = head->next;
        delete temp;
        temp = head;
    }
    m_Length = 0;
}

template<typename T>
bool DLinkedList<T>::IsEmpty(){    // Empty일 때는 언제인가..
    if(head->next == tail && tail->prev == head)
        return true;
    else
        return false;
}

template<typename T>
bool DLinkedList<T>::IsFull(){
    if(cur->next == NULL)
        return true;
    else
        return false;
}

template<typename T>
int DLinkedList<T>::GetLength(){
    return m_Length;
}

template <typename T>
void DLinkedList<T>::ResetList(){
    cur = NULL; //더미노드를 가리키기 위해.
}

template <typename T>
void DLinkedList<T>::GetCurItem(T& data){
    if(cur == NULL)
        cur = head->next;     //cur이 NULL이면 더미노드 옆에 있는 사실상 첫값을 가리키게함.
    else
        cur = cur->next; //현재 가리켰던 값의 다음 값.
    
    data = cur->data;
    //현재의 데이터를 객체에 담아준다. 빈 객체가 들어올 예정
}

template<typename T>
int DLinkedList<T>::Add(T data){
    DNode<T>* newnode = new DNode<T>; //새로운 노드 할당.
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    newnode->prev = tail->prev;
    tail->prev->next = newnode;
    newnode->next = tail;
    tail->prev = newnode;
    
    m_Length++;
    
    return 1;
}

template<typename T>
int DLinkedList<T>::Delete(T& data){
    
    cur = head; //시작점을 head로 고정.
    
    bool notfinish = (cur != NULL);
    bool found = false;
    
    while(notfinish && !found){
        if(data == cur->data){
            found = true;
            
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            //입력 받은 객체와 노드안에 있는 값이 같으면 해당 노드를 제거해준다.
            m_Length--;
        }
        else{
            cur = cur->next;
            //같지 않으면 다음 노드로 이동한다.
            notfinish = (cur != NULL); //cur값이 바뀌었으므로 다시 초기화 필요.
        }
    }
    if(found)
        return 1;
    else
        return 0;
}

template <typename T>
int DLinkedList<T>::Get(T& data){
    
    bool found = false;
    bool notfinish = (cur != NULL);
    cur = head; //시작점을 head로 고정.
    
    while(notfinish && !found){
        if(data == cur->data){
            found = true;
            data = cur->data;
            break;
        }
        else{
            cur = cur->next;
            notfinish = (cur != NULL);
        }
    }
    if(found)
        return 1;
    else
        return 0;
}

template <typename T>
int DLinkedList<T>::Replace(T& data){
    bool found = false;
    bool notfinish = (cur != NULL);
    cur = head; //시작점을 head로 고정.
    
    while(notfinish && !found){
        if(data == cur->data){
            found = true;
            cur->data = data;
            break;
        }
        else{
            cur = cur->next;
            notfinish = (cur != NULL);
        }
    }
    if(found)
        return 1;
    else
        return 0;
}
