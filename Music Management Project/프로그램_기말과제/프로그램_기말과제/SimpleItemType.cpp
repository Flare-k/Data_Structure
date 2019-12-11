#include "SimpleItemType.h"

SimpleItemType::SimpleItemType(){
    s_id = "";
    music = "";
}
SimpleItemType::~SimpleItemType(){}


string SimpleItemType::GetId() const {return s_id;}
string SimpleItemType::GetMusic(){return music;}
void SimpleItemType::SetId(string _sid){ s_id = _sid; }
void SimpleItemType::SetMusic(string _music){ music = _music;}

void SimpleItemType::SetSimpleItem(string _sid, string _music){
    SetId(_sid);
    SetMusic(_music);
}
void SimpleItemType::DisplayIdOnScreen(){
    cout<<"\t ID: "<<s_id<<endl;
}
void SimpleItemType::DisplayMusicOnScreen(){
    cout<<"\t MUSIC: "<<music<<endl;
}

void SimpleItemType::DisplaySimpleItemOnScreen(){
    DisplayIdOnScreen();
    DisplayMusicOnScreen();
    cout<<endl;
}

void SimpleItemType::SetMusicFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Music: ";
    cin>>music;
}
void SimpleItemType::SetIdFromKB(){ //키보드로 '곡제목' 입력
    cout<<"\t Primary Key: ";
    cin>>s_id;
}

void SimpleItemType::SetSimpleFromKB(){
    SetMusicFromKB();
    SetIdFromKB();
}

bool SimpleItemType::operator==(const SimpleItemType& data) const {
    if(this->s_id == data.GetId())
        return true;
    else
        return false;
}
bool SimpleItemType::operator!=(const SimpleItemType& data) const {
    if(this->s_id != data.GetId())
        return true;
    else
        return false;
}
bool SimpleItemType::operator>(const SimpleItemType& data) const {
    if(this->s_id > data.GetId())
        return true;
    else
        return false;
}
bool SimpleItemType::operator<(const SimpleItemType& data) const {
    if(this->s_id < data.GetId())
        return true;
    else
        return false;
}
/*
 ID를 기준으로 하였으나, Unsorted로 정렬됨
 */
