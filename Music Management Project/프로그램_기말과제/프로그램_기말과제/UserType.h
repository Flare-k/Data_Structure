#pragma once
#include <iostream>
#include <string>
#include "PlayItem.h"
#include "CircularQueue.h"
#define MAXSIZE 100
using namespace std;

class UserType{
private:
    string user_id; //사용자 아이디
    string user_pw; //사용자 비밀번호
    int playlistnum; //사용자 리스트넘버
public:
    UserType();
    //UserType의 디폴트 생성자
    ~UserType();
    //UserType의 소멸자
    string GetUserID() const;
    //User의 아이디 리턴
    string GetUserPW() const;
    //User의 비빌번호 리턴
    int GetPlayListNum() const;
    //User의 리스트 넘버 리턴
   
    void SetUserID(string _user_id);
    //User의 아이디 할당
    void SetUserPW(string _user_pw);
    //User의 비밀번호 할당
    void SetPlayListNum(int _playlistnum);
    //User의 리스트넘버 할당
    void SetUserRecord(string _user_id, string _user_pw);
    //User의 아이디와 비밀번호 할당
    
    void DisplayUserIDOnScreen();
    //User의 아이디 출력
    void DisplayUserPWOnScreen();
    //User의 비밀번호 출력
    void DisplayUserListOnScreen();
    //User의 리스트넘버 출력
    void DisplayUserOnScreen();
    //User의 아이디, 비밀번호, 리스트넘버 출력
    
    void SetUserIDFromKB();
    //키보드로 User의 아이디 할당
    void SetUserPWFromKB();
    //키보드로 User의 비밀번호 할당
    void SetUserPNFromKB();
    //키보드로 User의 리스트넘버 할당
    void SetUserFromKB();
    //키보드로 User의 모든 정보 할당
    
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);

    bool operator==(const UserType& user) const;
    bool operator!=(const UserType& user) const;
    bool operator>(const UserType& user) const;
    bool operator<(const UserType& user) const;
};
