#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define maxsize 100

using namespace std;

//Play List

class FullQueue{
public:
    void print()
    {
        cout << "\n\t FullQueue exception thrown." << endl;
    }
};

class EmptyQueue
{
public:
    void print()
    {
        cout << "\n\t EmtpyQueue exception thrown." << endl;
    }
};

template <typename T>
class CircularQueue{
private:
    int front;      //큐의 프론트 인덱스
    int rear;       //큐의 리어 인덱스
    int maxQueue;   //큐의 최대 사이즈
    int pointer;    //현재 인덱스를 가리키는 포인터변수
    int length;     //객체가 생성될 때의 길이
    T *pItems;      //동적할당.
public:
    CircularQueue();
    /*
     마스터 리스트에서 플레이리스트에 추가될 때, 객체가 생성되는 생성자역할.
     */
    ~CircularQueue();
    /*
     플레이리스트가 끝날 때, 객체가 소멸되는 소멸자역할.
     */
    int GetLength();
    /*
     현재 플레이 리스트에 들어간 길이 출력.
     */
    bool IsFull();
    /*
     플레이 리스트가 가득찼을 때의 불 함수
     */
    bool IsEmpty();
    /*
     플레이 리스트가 비어있을 때의 불 함수
     */
    void MakeEmpty();
    /*
     플레이 리스트를 비우는 함수
     */
    int EnQueue(T& item);   //추가 First in First out
    /*
     플레이 리스트에 차례대로 삽입하는 함수.
     */
    int DeQueue(T& item);
    /*
     플레이 리스트에 오래된 요소부터 제거하는 함수.
     */
    void ResetList();
    /*
     현재 위치를 초기화해주는 함수
     */
    
    int GetNextItem(T& item);
    /*
     함수가 실행되면 현재 front 인덱스를 가리키게 됩니다.
     */
    int Search(T& item);
    /*
     플레이 리스트 내에서 원하는 곡을 출력하기 위해 필요한 함수.
     조금이라도 빨리 찾기위해 이진탐색으로 구현.
     
     배열의 시작 인덱스 값이 계속 바뀌므로 상수로 고정하기보다는
     i = (front+1)%maxQueue를 해줘 원형의 느낌을 표현했습니다.
     */
    int Delete(T& item);
    /*
     플레이리스트 내에서 원하는 곡을 삭제하고 싶을 때 사용합니다.
     
     플레이리스트 내에서 삭제할경우 한 칸씩 앞으로 당겨주고
     새로 추가할 경우가 있기 떄문에 rear값도 1감소 시켜주었습니다.
     
     배열의 시작 인덱스 값이 계속 바뀌므로 상수로 고정하기보다는
     i = (front+1)%maxQueue를 해줘 원형의 느낌을 표현했습니다.
     */
    int Replace(T& item);
    /*
     플레이 리스트 내에서 원하는 값을 수정하고 싶을 경우에 사용
     배열의 시작 인덱스 값이 계속 바뀌므로 상수로 고정하기보다는
     i = (front+1)%maxQueue를 해줘 원형의 느낌을 표현했습니다.
     */
};

template <typename T>
CircularQueue<T>::CircularQueue(){
    maxQueue = maxsize;
    front = maxsize-1;
    rear = maxsize-1;
    length = 0;
    pItems = new T[maxsize];   //맥스만큼 동적할당.
}


template <typename T>
CircularQueue<T>::~CircularQueue(){
    delete [] pItems;             //소멸자에서 동적할당 해제.
    if(!IsEmpty())
        cout<<"\t Player is Down. "<<endl;
}
template<typename T>
int CircularQueue<T>::GetLength(){
    return length;
}

template <typename T>
bool CircularQueue<T>::IsFull(){
    if((rear+1) % maxQueue == front)
        return true;
    else
        return false;
}

template <typename T>
bool CircularQueue<T>::IsEmpty(){
    if(front == rear)
        return true;
    else
        return false;
}

template <typename T>
void CircularQueue<T>::MakeEmpty(){
    front = rear;
}

template <typename T>
int CircularQueue<T>::EnQueue(T &item){
    if(IsFull()){
        throw FullQueue();
    }
    else{
        rear = (rear+1)%maxQueue;
        pItems[rear] = item;
        length++;
        cout<<"\n\t >> SAVE IN PLAYLIST."<<endl;
        return 1;
    }
    
}

template<typename T>
int CircularQueue<T>::DeQueue(T& item){
    if(IsEmpty())
        throw EmptyQueue();
    else{
        length--;
        front=(front+1)%maxQueue;
        return 1;
    }
}

template <typename T>
void CircularQueue<T>::ResetList(){
    pointer = front;
}

template <typename T>
int CircularQueue<T>::GetNextItem(T& item){
    pointer++;
    
    if(pointer&maxQueue == rear)
        return -1;
    
    item = pItems[pointer%maxQueue];
    
    return 1;
}

template <typename T>
int CircularQueue<T>::Search(T& item){
    int first = (front+1)%maxQueue;
    int last = length;
    int mid;    // mid를 여기서 정의하면 반복문이 돌 때, 초기화되기 힘듬.
    
    while(first <= last){
        mid = (first+last)/2;
        
        if(item == pItems[mid]){
            item = pItems[mid];
            return 1;
        }
        else{
            if(item>pItems[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
    }
    return 0;
}

template <typename T>
int CircularQueue<T>::Delete(T& item){
    
    for(int i = (front+1)%maxQueue; i < length; i++){
        if(item == pItems[i]){
            for(; i<length; i++){
                pItems[i] = pItems[i+1];
            }
            length--;
            rear--;
            return 1;
        }
    }
    return 0;
}

template <typename T>
int CircularQueue<T>::Replace(T& item){
    
    for(int i = (front+1)%maxQueue; i < length; i++){
        if(pItems[i] == item){
            pItems[i] = item;
            return 1;
        }
    }
    return 0;
}
