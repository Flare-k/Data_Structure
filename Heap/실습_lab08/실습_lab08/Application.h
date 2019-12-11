#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "ItemType.h"
#include "PlayItem.h"

#include "HeapBase.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "D_LinkedList.h"
using namespace std;

//Application 클래스

class Application
{
    private:
    ifstream *m_InFile;
    ofstream *m_OutFile;
    HeapBase<ItemType> *m_List;        //Master List
    D_LinkedList<PlayItem> p_List;     //Play List
    int m_Command;
    int times = 0;
    
    public:
    Application(){
        m_Command=0;
    }
    ~Application(){}
    
    void Run();
    void SelectHeap();
    int GetCommand();
    
    /*
     =========================== Master List ===========================
     */
    int AddMusic();
    /*
     AddMusic() = Master List에 입력값을 저장하는 함수.
     
     ItemType 객체에 키보드로 모든 정보의 값을 입력받고 Master List에 저장합니다.
     */
    int DeleteMusic();
    /*
     DeleteMusic() = Primary Key값을 입력하여 Master List에 있는 값을 삭제해줍니다.
     
     ItemType 객체에 키보드로 Primary값을 입력해줍니다. 해당 입력 내용이 배열의 요소와 일치할 경우 삭제를 진행합니다.
     세 리스트에서 삭제가 진행될 경우, 확인하기 위해 출력함수를 모두 작성하였습니다.
     */
    
    int PopMusic();
    /*
     PopMusic() = Master List안에 있는 배열에 대해서 가장 먼저 저장된 데이터를 삭제해줍니다.
     */
    
    void ReplaceMusic();
    /*
     ReplaceMusic() = 키보드로 Primary Key값을 입력받고 Master List내에 같은 값을 가진 객체가 있다면 내용을 수정할 수 있게 해줍니다.
     
     객체에 키보드로 Primary Key를 입력받는다.
     만약 해당 객체가 있다면, 입력받은 객체를 확인하기 위해 해당 정보를 가진 객체 출력.
     바꿀내용을 하나씩 키보드로 바꿈. 단, Primary Key의 내용은 달라지면 안 됨.
     Primary Key를 미리 확인한 객체 정보와 다르게 입력하면 저장이 되지 않거나,
     입력한 Primary Key를 가진 다른 객체의 정보가 바뀌게 됨.
     */
    void SearchByid();
    /*
     SearchByid() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 탐색하여 출력해줍니다.
     
     객체에 키보드로 Primary값을 입력받고
     HeapBase class에 있는 Retrieve 함수로 넘겨줍니다.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
     */
    int SearchByArtist();
    /*
     SearchByArtist() = 가수명을 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
     
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetArtist() 문자열에 cin으로 입력받은 artist의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    int SearchByGenre();
    /*
     SearchByGenre() = 장르를 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
     
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetGenre() 문자열에 cin으로 입력받은 genre의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    void ​​​DisplayAllMusic();
    /*
     =========================== Play List ===========================
     */
    void AddSongToPL();
    /*
     AddtoPlayList() = Master List에서 데이터를 불러오고 갱신하여 PlayItemType에 값을 할당해줍니다.
     Q_List가 가득차면 Dequeue로 가장 오래된 데이터를 삭제해주고 맨 뒤에 최신 데이터를 저장해줍니다.
     저장할때, 저장하는 순서를 넣어줘야하므로 SetTime()을 사용했습니다.
     */
    
    int DeleteSongFrPL();
    /*
     DeleteSongFrPL() = Play List에서 원하는 데이터를 삭제해줍니다.
     */
    void PlayIOAddTime();
    /*
     PlayIDAddTime() = Master List에서 Play List로 정보를 저장할 때, 순서가 저장되고
     저장된 순서대로 아무런 키를 입력할때마다 Play List가 재생됩니다.
     */
    void PlayIOAddSelect();
    /*
     PlayIOAddSelect() = Play List 안에 있는 곡 중에서 사용자가 원하는 특정 곡을 재생하게 해줍니다.
     */
    void PlayIOFreq();  //자주 Play된 횟수 순으로 Play..
    /*
     PlayIOFreq() = 앞서 PlayIOAddTime() 함수와 PlayIOAddSelect() 함수를 통해서 갱신된
     재생횟수를 통해 가장 많이 플레이 된 횟수부터 내림차순으로 정렬이 되고
     그 순서대로 플레이할 수 있게 해줍니다.
     */
    void PrintPlayList();
    /*
     PrintPlayList() = 현재 Play List의 곡들의 정보를 모두 출력해줍니다.
     */

};
