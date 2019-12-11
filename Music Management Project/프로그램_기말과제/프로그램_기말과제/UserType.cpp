#include "UserType.h"

UserType::UserType(){}
UserType::~UserType(){}

string UserType::GetUserID() const {return user_id;}
string UserType::GetUserPW() const {return user_pw;}
int UserType::GetPlayListNum()const {return playlistnum;}

void UserType::SetUserID(string _user_id){user_id = _user_id;}
void UserType::SetUserPW(string _user_pw){user_pw = _user_pw;}
void UserType::SetPlayListNum(int _playlistnum){playlistnum = _playlistnum;}
void UserType::SetUserRecord(string _user_id, string _user_pw){
    SetUserID(_user_id);
    SetUserPW(_user_pw);
}
void UserType::SetUserIDFromKB(){ //키보드로 '회원 아이디' 입력
    cout<<"\t           아이디: ";
    cin>>user_id;
}
void UserType::SetUserPWFromKB(){ //키보드로 '회원 비밀번호' 입력
    cout<<"\t           비밀번호: ";
    cin>>user_pw;
}
void UserType::SetUserPNFromKB(){//키보드로 '회원 리스트넘버' 입력
    cout<<"\t           리스트: ";
    cin>>playlistnum;
}
void UserType::SetUserFromKB(){ //키보드로 '전체 회원정보' 입력
    SetUserIDFromKB();
    SetUserPWFromKB();
    SetUserPNFromKB();
}

void UserType::DisplayUserIDOnScreen(){
    cout<<"\t           아이디: "<<user_id<<endl;
}
void UserType::DisplayUserPWOnScreen(){
    cout<<"\t           비밀번호: "<<user_pw<<endl;
}
void UserType::DisplayUserListOnScreen(){
    cout<<"\t           리스트: "<<playlistnum<<endl;
}
void UserType::DisplayUserOnScreen(){
    DisplayUserIDOnScreen();
    DisplayUserPWOnScreen();
    DisplayUserListOnScreen();
    cout<<endl;
}

int UserType::ReadDataFromFile(ifstream& fin){      //객체에 파일의 내용을 읽어온다.
    fin>>user_id;
    fin>>user_pw;
    return 1;
}
int UserType::WriteDataToFile(ofstream& fout){      //객체의 내용을 파일에 저장해준다.
    fout<<endl;
    fout<<user_id<<" ";
    fout<<user_pw;
    return 1;
}

// '=='를 가능하게 하는 연산자 오버로딩
bool UserType::operator==(const UserType& user) const {
    if(this->user_id == user.user_id)
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool UserType::operator!=(const UserType& user) const {
    if(this->user_id != user.user_id)
        return true;
    else
        return false;
}
// 비교연산자 오버로딩 ' > '
bool UserType::operator>(const UserType& user) const {
    if(this->user_id > user.user_id)
        return true;
    else
        return false;
}
// 비교연산자 오버로딩 ' < '
bool UserType::operator<(const UserType& user) const {
    if(this->user_id < user.user_id)
        return true;
    else
        return false;
}
