#pragma once
#include <iostream>
#include "ItemType.h"
using namespace std;

template<typename T>
class HeapBase{
public:
    HeapBase();
    /*
     추상클래스에 대한 생성자이다.
     추상클래스의 생성자에서는 인스턴스(객체) 생성이 불가능하다.
     */

    virtual ~HeapBase();
    /*
     자식클래스에서 생성자들이 소멸될 때, 최종적으로 소멸된다.
     */

    bool IsEmpty();
    /*
     현재 배열이 비어있는지 확인해주는 bool 함수이다.
     */
    bool IsFull();
    /*
     현재 배열이 꽉 차있는지 확인해주는 bool 함수이다.
     */
    
    int GetLength() const;
    /*
     현재 배열의 길이를 리턴해주는 함수이다.
     */

    void MakeEmpty();
    /*
     현재 배열을 모두 삭제해주기 위해 사용된다.
     */
    void ResetList();
    /*
     배열의 출력, 탐색 등의 역할을 위해,
     현재 배열의 위치를 리셋해준다.
     */
    int GetNextItem(T& data);
    /*
     배열의 출력, 탐색 등의 역할을 위해,
     반복문을 통해 해당 인덱스의 요소를 객체에 할당해준다.
     */

    virtual int Add(T item);
    /*
     동적할당된 배열에 객체를 추가해주는 기능을 한다.
     ReheapUP 재귀함수를 통해 각 배열의 크기에 따라 정렬된다.
     */
    virtual int Delete(T item);
    /*
     사용자가 입력한 객체의 값이 배열에 존재할 경우 삭제해준다.
     */
    virtual T Pop();
    /*
     Pop을 실행하게 되면 가장 먼저 들어온 데이터가 나가게(삭제) 된다.
     */

    virtual int RetrieveItem(T& item, bool& found);
    /*
     사용자가 입력한 객체를 찾아준다.
     */
    virtual int ReplaceItem(T& item, bool& found);
    /*
     사용자가 입력한 객체를 찾아서 원하는 값으로 치환해준다.
     단, Primary키는 바뀌면 안 된다.
     */
    void Swap(int iparent, int ibottom);
    /*
     ReheapUp/Down시 필요한 경우 배열 내 요소 간의 위치를 바꿔주는 역할을 한다.
     */
    virtual void PrintHeap();
    
    virtual void PrintHeapInOrder(T m_pHeap[], int m_iLastNode);

    //순수가상함수 -> 자식클래스에서 정의 필요.
    virtual void ReheapDown(int iparent, int ibottom) = 0;
    virtual void ReheapUp(int iroot, int ibottom) = 0;
    virtual void Delete(T item, bool& found, int iparent) = 0;
    virtual void Retrieve(T& item, bool& found, int iparent) = 0;
    virtual void Replace(T& item, bool& found, int iparent) = 0;
    
protected:
    T *m_pHeap;         //배열 동적할당.
    int m_iLastNode;    //heap에서 node의 수
    int m_MaxSize;      //최대 배열 크기
    int m_CurPointer;   //ResetList()와 GetNextItem()을 이용하기 위해, 현재 노드를 가리킨다.
};

template<typename T>
HeapBase<T>::HeapBase(){//생성자
    m_MaxSize = MAXSIZE;
    m_iLastNode = 0;
    ResetList();
}
template<typename T>
HeapBase<T>::~HeapBase(){//소멸자
    delete [] m_pHeap;
}
template<typename T>
bool HeapBase<T>::IsEmpty(){//배열이 비어있는지 확인
    if(m_iLastNode == 0)   //최대 배열의 크기가 0이면 Empty
        return true;
    else
        return false;
}
template<typename T>
bool HeapBase<T>::IsFull(){ //배열이 가득 차 있는지 확인
    if(m_MaxSize == m_iLastNode)   //최대 배열의 크기와 마지막 노드의 수가 일치하면 Full
        return true;
    else
        return false;
}
template<typename T>
int HeapBase<T>::GetLength() const{  //현재 노드의 수를 리턴
    return m_iLastNode;
}
template<typename T>
void HeapBase<T>::MakeEmpty(){   //배열의 길이를 0으로 만들어준다.
    m_iLastNode = 0;
}
template<typename T>
void HeapBase<T>::ResetList(){       //배열의 현재 위치를 리셋해준다.
    m_CurPointer = -1;
}
template<typename T>
int HeapBase<T>::GetNextItem(T &data){//배열의 위치를 탐색한다.
    m_CurPointer++;
    
    if(m_CurPointer == m_iLastNode)
        return -1;
    
    data = m_pHeap[m_CurPointer];//0부터 반복하면서 다음 data값을 불러오게 함.
    return 1;
}
template<typename T>
int HeapBase<T>::Add(T item){//배열에 객체를 할당한다.
    m_pHeap[m_iLastNode] = item;    //배열에 추가해준다.
    ReheapUp(0, m_iLastNode);       //ReheapUP
    m_iLastNode++;                  //배열의 길이 증가.
    return 1;
}
template<typename T>
int HeapBase<T>::Delete(T item){//사용자가 입력한 객체와 일치한 요소를 삭제한다.
    bool found = false;
    
    Delete(item, found, 0);
    
    if(found)
        m_iLastNode--;
    else
        return 0;
    
    return 1;
}
template<typename T>
T HeapBase<T>::Pop(){   //가장 먼저 들어온 데이터를 삭제해준다.
    T item = m_pHeap[0];
    
    Delete(item);
    
    return item;
}
template<typename T>
int HeapBase<T>::RetrieveItem(T& item, bool& found){//사용자가 입력한 객체와 일치한 요소를 찾아준다.
    Retrieve(item, found, 0);
    return 1;
}
template<typename T>
int HeapBase<T>::ReplaceItem(T &item, bool &found){//사용자가 입력한 객체와 일치한 요소를 찾고 값을 치환하도록 해준다.
    Replace(item, found, 0);
    return 1;
}
template<typename T>
void HeapBase<T>::Swap(int iparent, int ibottom){//ReheapUp/Down의 과정에서 필요에 의해 요소들 간의 값을 바꿔준다.
    T temp = m_pHeap[iparent];
    m_pHeap[iparent] = m_pHeap[ibottom];
    m_pHeap[ibottom] = temp;
}


template <typename T>
void HeapBase<T>::PrintHeap(){
    T item;
    
    for(int i=0; i<m_iLastNode; i++)
    {
        item << m_pHeap[i];
    }
}

template<typename T>
void HeapBase<T>::PrintHeapInOrder(T m_pHeap[], int m_iLastNode){
    T item;
    
        item<<m_pHeap[2*m_iLastNode+1];
        item<<m_pHeap[0];
        item<<m_pHeap[2*m_iLastNode+2];
    
}
