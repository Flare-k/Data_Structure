#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class SimpleItemType{
private:
    string s_id;     //고유번호
    string music;    //곡 명
public:
    SimpleItemType();
    //SimpleItemType의 디폴트 생성자
    ~SimpleItemType();
    //SimpleItemType의 소멸자
    
    string GetId() const;
    //고유번호 리턴
    string GetMusic();
    //곡명 리턴
    void SetId(string _sid);
    //고유번호 할당
    void SetMusic(string _music);
    //곡명 할당
    void SetSimpleItem(string _sid, string _music);
    //SimpleItemType의 모든 정보 할당.
    void DisplayIdOnScreen();
    //고유번호 출력
    void DisplayMusicOnScreen();
    //곡명 출력
    void DisplaySimpleItemOnScreen();
    //SimpleItemType의 모든 정보 출력.
    
    void SetMusicFromKB();
    //키보드로 곡명 입력받기
    void SetIdFromKB();
    //키보드로 고유번호 입력받기
    void SetSimpleFromKB();
    //키보드로 모든 정보 입력받기
    
    bool operator==(const SimpleItemType& data) const;
    bool operator!=(const SimpleItemType& data) const;
    bool operator<(const SimpleItemType& data) const;
    bool operator>(const SimpleItemType& data) const;
    friend ostream& operator << (ostream& out, SimpleItemType& item){
        out<<"\t 제목: "<<item.GetMusic()<<endl;
        out<<"\t 고유번호: "<<item.GetId()<<endl;
        out<<endl;
        return out;
    }
};
