#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "ItemType.h"
#include "SingerType.h"
#include "SimpleItemType.h"
#include "PlayItem.h"
#include "UserType.h"

#include "SortedList.h"
#include "AVLTree.h"
#include "DLinkedList.h"
#include "CircularQueue.h"
using namespace std;

//Application 클래스

class Application{
private:
    SortedList<ItemType> m_List;            //Master List
    CircularQueue<PlayItem> *p_List = new CircularQueue<PlayItem>[100]; //Play List
    DLinkedList<UserType> u_List;        //User List
    AVLTree<SingerType> s_List;     //Singer List
    AVLTree<SimpleItemType> simple_List;   //SimpleItem List
    int m_Command;
    int times;
    ifstream m_InFile;
    ofstream m_OutFile;
public:
    Application();
    
    ~Application();
    /*
     동적할당된 playlist를 동적할당 해제해준다.
     */
    
    void Run();
    /*
     Run() = 음원관리프로그램에 있어서 유저관리와 관리자모드를 실행하게 해주는 함수.
     */
    void RunPlaylist(UserType& user);
    /*
     RunPlaylist(UserType& user) = 유저가 로그인 되면 user 객체를 통해 플레이 리스트를 관리할 수 있는 함수.
     
     회원가입시 등록한 플레이리스트의 넘버를 통해 각 유저에게 플레이리스트를 하나씩 부여한다.
     플레이리스트에 등록한 리스트넘버를 플레이리스트 배열의 인덱스로 한다.
     */
    int GetCommand();
    /*
     GetCommand() = 프로그램이 실행될 때, 첫 화면을 보여주는 함수.
     */
    
    /*
     =========================== Master List ===========================
     */
    int AddMusic();
    /*
     AddMusic() = Master List, Singer List, Song List에 입력값을 연동하여 저장하는 함수.
     
     ItemType 객체에 키보드로 모든 정보의 값을 입력받고 Master List에 저장될 때,
     Singer List에도 동시에 저장되어야 합니다.
     따라서 ItemType 객체로 입력 받은 정보를 통해,
     SingerType객체와 SongType객체에 서로의 메소드를(Set함수, ItemType의 Get함수) 활용하여 값을 입력해줍니다.
     Master List에 객체를 저장할 때, Singer List가 비어있거나 같은 Primary Key를 가진 객체가 없을 경우
     Singer List에도 저장해줍니다. 뿐만아니라 Song List도 관리해야 하므로 동시에 Song List에도 저장해줍니다.
     */
    int DeleteMusic();
    /*
     DeleteMusic() = Primary Key값을 입력하여 Master List(Singer List, Song List포함)에 있는 값을 삭제해줍니다.
     
     ItemType 객체에 키보드로 Primary값을 입력받고 SingerType과 SongType 객체에도 필요한 정보를 입력해줍니다.
     Master List에서 삭제되면 Singer List와 Song List에서도 똑같이 없어져야 하므로 세 리스트에서 동시에 삭제가 진행된 경우 참이 되게 조건문을 만들어줬습니다.
     세 리스트에서 삭제가 진행될 경우, 확인하기 위해 출력함수를 모두 작성하였습니다.
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
    void SearchByid_Seq();
    /*
     SearchByid_Seq() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 순차탐색하여 출력해줍니다.
     
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Seq 함수로 넘겨줍니.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
     */
    void SearchByid_BinaryS();
    /*
     SearchByid_BinaryS() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 이진탐색하여 출력해줍니다.
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Binary함수로 넘겨줍니다.
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
    int OpenInFile(string &fileName);
    int OpenOutFile(string &fileName);
    int ReadDataFromFile();
    int WriteDataToFile();
    
    /*
     =========================== Play List ===========================
     */
    void AddtoPlayList(UserType& user);
    /*
     AddtoPlayList() = Master List에서 데이터를 불러오고 갱신하여 PlayItemType에 값을 할당해줍니다.
     Q_List가 가득차면 Dequeue로 가장 오래된 데이터를 삭제해주고 맨 뒤에 최신 데이터를 저장해줍니다.
     저장할때, 저장하는 순서를 넣어줘야하므로 SetTime()을 사용했습니다.
     */
    int DeletetoPlayList(UserType& user);
    /*
     DeleteSongFrPL() = Play List에서 원하는 데이터를 삭제해줍니다.
     */
    void PlayInsertOrder(UserType& user);
    /*
     PlayInsertOrder() = Master List에서 Play List로 정보를 저장할 때, 순서가 저장되고
     저장된 순서대로 아무런 키를 입력할때마다 Play List가 재생됩니다.
     */
    void PlayIOAddSelect(UserType& user);
    /*
     PlayIOAddSelect() = Play List 안에 있는 곡 중에서 사용자가 원하는 특정 곡을 재생하게 해줍니다.
     */
    void PlayIOFreq(UserType& user);  //자주 Play된 횟수 순으로 Play..
    /*
     PlayIOFreq() = 앞서 PlayIOAddTime() 함수와 PlayIOAddSelect() 함수를 통해서 갱신된
     재생횟수를 통해 가장 많이 플레이 된 횟수부터 내림차순으로 정렬이 되고
     그 순서대로 플레이할 수 있게 해줍니다.
     */
    void PlayLikeMusic(UserType& user);
    /*
     PlayLikeMusic() = ClicktheLike() 함수를 통해 '좋아요'가 업데이트 되고 '좋아요'가 눌린 곡들에 대해서 플레이할 수 있게 해줍니다.
     */
    void ClicktheLike(UserType& user);
    /*
     ClicktheLike() = 사용자가 원하는 곡에 호감도를 표시하기 위해서 원하는 곡의 고유번호를 입력하면 '좋아요'가 증가합니다.
     */
    void PrintPlayRank(UserType& user);
    /*
     PrintPlayRank() = 현재 재생횟수가 가장 많은 순으로 순위를 보여주고, 또는 현재 '좋아요' 수가 가장 많은 순으로 순위를 보여줍니다.
     */
    void PrintPlayList(UserType user);
    /*
     PrintPlayList() = 현재 Play List의 곡들의 정보를 모두 출력해줍니다.
     */
    void PrintLikeList(UserType& user);
    /*
     PrintLikeList() = 현재 Like List의 곡들의 정보를 모두 출력해줍니다.
     */
    int SearchinPL_BinaryS(UserType& user);
    /*
     SearchinPL_BinaryS() = 현재 Play List를 이진탐색하여 원하는 정보를 찾게 도와줍니다. (Play List를 Linked List로 구현 안 한 이유.)
     */
    int ReplacePlayList(UserType& user);
    /*
     ReplacePlayList() = 원하는 정보에 대해서 사용자가 원하는대로 변경할 수 있게 해줍니다.
     */

    /*
     =========================== Singer & Song List ===========================
     */
    void ​​​DisplayAllSingerList();
    /*
     DisplayAllSingerList() = SingerType의 객체를 출력하도록 하였습니다.
     */
    void ​​​DisplayAllSongList();
    /*
     DisplayAllSongList() = SimpleItemType의 객체를 출력하도록 하였습니다.
     */
    int AddSinger();
    /*
     AddSinger() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
     Singer의 정렬을 가수로 하려고 했으나 의미가 없는 것 같아서 SimpleItemType의 ID를 불러와서
     ID순으로 오름차순으로 Singer를 정렬하였습니다.
     함수가 실행되면 Singer List, Song List, Master List 모두 저장됩니다.
     */
    int AddSong();
    /*
     AddSong() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
     하지만 같은 가수명이 없다고 가정하여서 같은 이름을 갖는 경우, 저장을 하지 않도록 구현하였습니다.
     
     Song의 정렬은 Unsorted로 정렬하였고, 기준은 ID로 하였습니다.
     */
    
    /*
     =========================== User List ===========================
     */
    int AddUser();
    /*
     AddUser() = 유저리스트에 유저객체를 추가하는 함수.
     */
    int LoginUser();
    /*
     LoginUser() = 유저객체에 추가된 객체를 로그인하여 불러오는 함수.
     */
    void DisplayUser();
    /*
     DisplayUser() = 현재 유저리스트에 저장된 모든 유저를 보여주는 함수.
     */
    void ManageUser();
    /*
     ManageUser() = 유저 로그인, 회원가입, 전체출력을 실행해주는 함수.
     */
};
