#pragma once
#include <iostream>
#include "HeapBase.h"
using namespace std;

template<typename T>
class MinHeap: public HeapBase<T>{
public:
    MinHeap();
    MinHeap(int size);
    
    virtual void ReheapDown(int iparent, int ibottom);
    /*
     Master List에 삭제가 이루어질 때, leaf 노드의 값을 삭제의 위치에 옮기고 옮겨진 값 보다 자식 노드의 값이 작을 경우 반복적으로 자리를 바꿔준다.
     즉, 좌우 작은 노드를 찾고 둘 중 작은 노드와 현재 노드의 대소를 비교한다. 현재 노드보다 작다면 서로 자리를 바꿔준다. 위에서 아래 방향으로 진행한다.
     */
    virtual void ReheapUp(int iroot, int ibottom);
    /*
     Master List에 추가가 이루어질 때, leaf node가 root node보다 작은 경우 두 노드의 값을 Swap해준다. (밑에서 위로 올라가며 swap)
     */
    virtual void Delete(T item, bool& found, int iparent);
    /*
     사용자가 입력한 객체와 일치한 배열의 요소를 삭제해준다.
     일치하지 않을 경우(found != true), 좌우 자식 노드를 탐색한다.
     */
    virtual void Retrieve(T& item, bool& found, int iparent);
    /*
     전체적인 알고리즘은 Delete 함수와 크게 벗어나지 않으며, 사용자가 입력한 Primary Key가 배열에 존재한다면
     빈 객체에 해당 요소를 할당해준다.
     */
    virtual void Replace(T& item, bool& found, int iparent);
    /*
     전체적인 알고리즘은 Delete 함수와 크게 벗어나지 않으며, 사용자가 입력한 Primary Key가 배열에 존재한다면
     빈 객체에 사용자가 새로 입력한 데이터를 할당해준다.
     */
    
};
template<typename T>
MinHeap<T>::MinHeap(){
    HeapBase<T>::m_pHeap = new T[HeapBase<T>::m_MaxSize];
}
template<typename T>
MinHeap<T>::MinHeap(int size){
    HeapBase<T>::m_MaxSize = size;
    HeapBase<T>::m_pHeap = new T[HeapBase<T>::m_MaxSize];
}

template<typename T>
void MinHeap<T>:: ReheapDown(int iparent, int ibottom){
    int minChild;
    int leftChild = iparent*2 + 1;
    int rightChild = iparent*2 + 2;
    
    if(leftChild <= ibottom){//길이가 6이면 이때 ibottom은 5
        if(leftChild == ibottom)
            minChild = leftChild;       //left랑 ibottom이 같으면 당연히 left가 max
        else{
            if(HeapBase<T>::m_pHeap[leftChild] > HeapBase<T>::m_pHeap[rightChild])
                minChild = rightChild;
            else
                minChild = leftChild;
        }       //왼쪽 자식노드와 오른쪽 자식노드중에 큰 자식 노드를 maxChild에 할당. 가장 큰값이 root에 와야하므로.
        
        //할당 받은 maxChild와 현재의 root node를 비교하여 큰 값
        if(HeapBase<T>::m_pHeap[iparent] > HeapBase<T>::m_pHeap[minChild]){
            HeapBase<T>::Swap(iparent, minChild);
            ReheapDown(iparent, ibottom);
        }
    }
}

template<typename T>
void MinHeap<T>:: ReheapUp(int iroot, int ibottom){
    int parent_node;
    if(ibottom > iroot){
        parent_node = (ibottom-1)/2;        //(6-1)/2 = 2
        if(HeapBase<T>::m_pHeap[parent_node] > HeapBase<T>::m_pHeap[ibottom]){
            HeapBase<T>::Swap(parent_node, ibottom);  //자식노드보다 부모노드가 크면, Swap(부모노드, 자식노드)   parent = 2, ibottom = 6
            ReheapUp(iroot, parent_node);   //반복~
        }
    }
}

template<typename T>
void MinHeap<T>:: Delete(T item, bool& found, int iparent){
    int leftChild = iparent*2 + 1;
    int rightChild = iparent*2 + 2;
    
    if(item == HeapBase<T>::m_pHeap[iparent]){
        HeapBase<T>::m_pHeap[iparent] = HeapBase<T>::m_pHeap[HeapBase<T>::m_iLastNode - 1];
        ReheapDown(iparent, HeapBase<T>::m_iLastNode-2);
        found = true;
    }
    if(leftChild < HeapBase<T>::m_iLastNode && !found)
        Delete(item, found, leftChild);
    if(rightChild < HeapBase<T>::m_iLastNode && !found)
        Delete(item, found, rightChild);
}

template<typename T>
void MinHeap<T>:: Retrieve(T& item, bool& found, int iparent){
    int leftChild = iparent*2 + 1;
    int rightChild = iparent*2 + 2;
    
    if(item == HeapBase<T>::m_pHeap[iparent]){
        item = HeapBase<T>::m_pHeap[iparent];
        found = true;
    }
    if(leftChild < HeapBase<T>::m_iLastNode && !found)
        Retrieve(item, found, leftChild);
    if(rightChild < HeapBase<T>::m_iLastNode && !found)
        Retrieve(item, found, rightChild);
}

template<typename T>
void MinHeap<T>::Replace(T &item, bool &found, int iparent){
    int leftChild = iparent*2 + 1;
    int rightChild = iparent*2 + 2;
    
    if(item == HeapBase<T>::m_pHeap[iparent]){
        HeapBase<T>::m_pHeap[iparent] = item;
        found = true;
    }
    if(leftChild < HeapBase<T>::m_iLastNode && !found)
        Replace(item, found, leftChild);
    if(rightChild < HeapBase<T>::m_iLastNode && !found)
        Replace(item, found, rightChild);
}


