#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SimpleItemType.h"
using namespace std;


class SingerType{
private:
    string name;        //가수명
    int age;            //나이
    string gender;      //성별
    SimpleItemType item;//고유번호, 곡명
public:
    SingerType();
    //SingerType의 디폴트 생성자
    ~SingerType();
    //SingerType의 소멸자
    
    string GetName()const;
    //가수명 리턴
    int GetAge();
    //나이 리턴
    string GetGender();
    //성별 리턴
    string GetId() const;
    //고유번호 리턴
    string GetMusic();
    //제목 리턴
    
    void SetName(string _name);
    //가수명 할당
    void SetAge(int _age);
    //나이 할당
    void SetGender(string _gender);
    //성별 할당
    void SetSonglist(SimpleItemType _item);
    //SimpleItemType 할당
    void SetSinger(string _name, int _age, string _gender, SimpleItemType _item);
    //가수에 필요한 정보들 할당
    
    void DisplayNameOnScreen();
    //가수명 출력
    void DisplayAgeOnScreen();
    //나이 출력
    void DisplayGenderOnScreen();
    //성별 출력
    void DisplayIdOnScreen();
    //고유번호 출력
    void DisplayMusicOnScreen();
    //노래제목 출력
    
    void DisplaySingerOnScreen();
    //가수에 대한 모든 정보 출력
    void DisplaySongInSinger();
    //노래에 대한 모든 정보 출력
    
    void SetArtistFromKB();
    //키보드로 가수정보 할당
    void SetAgeFromKB();
    //키보드로 나이정보 할당
    void SetGenderFromKB();
    //키보드로 성별정보 할당
    void SetPrimaryFromKB();
    //키보드로 고유번호 정보 할당
    void SetMusicFromKB();
    //키보드로 곡명정보 할당
    void SetSingerFromKB();
    //키보드로 가수의 모든정보 할당
    
    bool operator==(const SingerType& data) const;
    bool operator!=(const SingerType& data) const;
    bool operator>(const SingerType& data) const;
    bool operator<(const SingerType& data) const;
    /*
     입력되는 객체는 Singer 객체지만 사실상 비교하는 것은 Singer 객체 안에 있는 SimpleItem 객체의 'ID' 내용을 가지고 비교하게끔 하였습니다.
     */
    friend ostream& operator << (ostream& out, SingerType& singer){
        out<<"\t 가수: "<<singer.GetName()<<endl;
        out<<"\t 나이: "<<singer.GetAge()<<endl;
        out<<"\t 성별: "<<singer.GetGender()<<endl;
        out<<endl;
        return out;
    }
};
