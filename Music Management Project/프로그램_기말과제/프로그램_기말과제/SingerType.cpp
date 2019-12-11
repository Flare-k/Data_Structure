#include "SingerType.h"


SingerType::SingerType(){
    name = "";
    age = 0;
    gender = "";
    item.GetId();   //SimpleItem에서 받아온 ID로 대소 비교하여 Sorted-Linked-List의 기능을 하는 SingerList를 구현하였습니다.
    item.GetMusic();
}
SingerType::~SingerType(){}


string SingerType::GetName()const{return name;}
int SingerType::GetAge() {return age;}
string SingerType::GetGender(){return gender;}
string SingerType::GetId() const {return item.GetId();}
string SingerType::GetMusic(){return item.GetMusic();}

void SingerType::SetName(string _name){name = _name;}
void SingerType::SetAge(int _age){age = _age;}
void SingerType::SetGender(string _gender){gender = _gender;}
void SingerType::SetSonglist(SimpleItemType _item){item = _item;}
void SingerType::SetSinger(string _name, int _age, string _gender, SimpleItemType _item){
    SetName(_name);
    SetAge(_age);
    SetGender(_gender);
    SetSonglist(_item);
    //SongList를 구현하기위해 객체를 입력파라미터로 받았고, 'ID'와 '곡명' 총 두 가지의 정보를 가져오는 객체가 저장될 것입니다.
}

void SingerType::DisplayNameOnScreen(){
    cout<<"\t NAME: "<<name<<endl;
}
void SingerType::DisplayAgeOnScreen(){
    cout<<"\t AGE: "<<age<<endl;
}
void SingerType::DisplayGenderOnScreen(){
    cout<<"\t GENDER(M/F): "<<gender<<endl;
}
void SingerType::DisplayIdOnScreen(){
    cout<<"\t ID: "<<item.GetId()<<endl;
}
void SingerType::DisplayMusicOnScreen(){
    cout<<"\t Music: "<<item.GetMusic()<<endl;
}

void SingerType::DisplaySingerOnScreen(){
    DisplayNameOnScreen();
    DisplayAgeOnScreen();
    DisplayGenderOnScreen();
    cout<<endl;
}
void SingerType::DisplaySongInSinger(){
    DisplayIdOnScreen();
    DisplayMusicOnScreen();
    cout<<endl;
}

void SingerType::SetArtistFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Artist: ";
    cin>>name;
}
void SingerType::SetAgeFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Age: ";
    cin>>age;
}
void SingerType::SetGenderFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Gender: ";
    cin>>gender;
}

void SingerType::SetSingerFromKB(){
    SetArtistFromKB();
    SetAgeFromKB();
    SetGenderFromKB();
}

// '=='를 가능하게 하는 연산자 오버로딩
bool SingerType::operator==(const SingerType& data) const {
    //  if(this->name.find(data.GetName()) != string::npos)
    if(this->item.GetId() == data.GetId())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool SingerType::operator!=(const SingerType& data) const {
    if(this->item.GetId() != data.GetId())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' > '
bool SingerType::operator>(const SingerType& data) const {
    if(this->item.GetId() > data.GetId())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool SingerType::operator<(const SingerType& data) const {
    if(this->item.GetId() < data.GetId())
        return true;
    else
        return false;
}
/*
 SimpleItemType의 ID를 기준으로 하여 Sorted 정렬하였습니다.
 */
