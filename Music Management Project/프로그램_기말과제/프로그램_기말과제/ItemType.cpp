#include "ItemType.h"

ItemType::ItemType(){
    music = "";
    artist = "";
    composer = "";
    genre = "";
    primary = "";
    numPlay = 0;
    inTime = 0;
    age = 0;
    gender = "";
}
ItemType::~ItemType(){}

string ItemType::GetMusic(){return music;}
string ItemType::GetArtist(){return artist;}
string ItemType::GetComposer(){return composer;}
string ItemType::GetGenre(){return genre;}
string ItemType::GetPrimary() const{return primary;}
int ItemType::GetTime(){return inTime;}
int ItemType::GetNumPlay(){return numPlay;}
int ItemType::GetAge(){return age;}
string ItemType::GetGender(){return gender;}

void ItemType::SetMusic(string inMusic){music = inMusic;}
void ItemType::SetArtist(string inArtist){artist = inArtist;}
void ItemType::SetComposer(string inComposer){composer = inComposer;}
void ItemType::SetGenre(string inGenre){genre = inGenre;}
void ItemType::SetPrimary(string inPri){primary = inPri;}
void ItemType::SetTime(int _inTime){inTime = _inTime;}
void ItemType::SetNumPlay(int _numPlay){numPlay = _numPlay;}
void ItemType::SetAge(int _age){age = _age;}
void ItemType::SetGender(string _gender){gender = _gender;}
void ItemType::SetRecord(string inMusic, string inComposer,string inArtist, string inGenre, string inPri, int _inTime, int _numPlay){
    SetMusic(inMusic);
    SetArtist(inArtist);
    SetComposer(inComposer);
    SetGenre(inGenre);
    SetPrimary(inPri);
    SetTime(_inTime);
    SetNumPlay(_numPlay);
}

void ItemType::SetSingerRecord(string inMusic,string inArtist, string inPri, string _gender, int _age){
    SetMusic(inMusic);
    SetArtist(inArtist);
    SetPrimary(inPri);
    SetGender(_gender);
    SetAge(_age);
}


// 곡이름 / 가수 / 작곡가 / 장르 / 고유번호 / 들어온 순서 / 실행 횟수 / 나이 / 성별

void ItemType::DisplayMusicOnScreen(){
    cout<<"\t 제목: "<<music<<endl;
}
void ItemType::DisplayArtistOnScreen(){
    cout<<"\t 가수: "<<artist<<endl;
}
void ItemType::DisplayAgeOnScreen(){
    cout<<"\t 나이: "<<age<<endl;
}
void ItemType::DisplayGenderOnScreen(){
    cout<<"\t 성별: "<<gender<<endl;
}
void ItemType::DisplayComposerOnScreen(){
    cout<<"\t 작곡가: "<<composer<<endl;
}
void ItemType::DisplayGenreOnScreen(){
    cout<<"\t 장르: "<<genre<<endl;
}
void ItemType::DisplayPrimaryOnScreen(){
    cout<<"\t 고유번호: "<<primary<<endl;
}
void ItemType::DisplayTimeOnScreen(){
    cout<<"\t 등록 순서: "<<inTime<<endl;
}
void ItemType::DisplayNumPlayOnScreen(){
    cout<<"\t 재생횟수: "<<numPlay<<endl;
}

void ItemType::DisplayAllOnScreen(){
    cout<<setw(20)<<music
    <<setw(14)<<artist
    <<setw(7)<<age
    <<setw(15)<<gender
    <<setw(15)<<composer
    <<setw(14)<<genre
    <<setw(13)<<primary<<endl;
}


//전체 출력
void ItemType::DisplayRecordOnScreen(){
    DisplayMusicOnScreen();
    DisplayArtistOnScreen();
    DisplayAgeOnScreen();
    DisplayGenderOnScreen();
    DisplayComposerOnScreen();
    DisplayGenreOnScreen();
    DisplayPrimaryOnScreen();
    cout<<endl;
}
void ItemType::DisplayPLRecordOnScreen(){
    DisplayMusicOnScreen();
    DisplayArtistOnScreen();
    DisplayNumPlayOnScreen();
    DisplayPrimaryOnScreen();
    cout<<endl;
}


void ItemType::SetMusicFromKB(){ //키보드로 '곡제목' 입력
    cout<<setw(20)<<"제목: ";
    cin>>music;
}
void ItemType::SetArtistFromKB(){ //키보드로 '가수 또는 연주자' 입력
    cout<<setw(20)<<"가수: ";
    cin>>artist;
}
void ItemType::SetAgeFromKB(){ //키보드로 '고유번호' 입력
    cout<<setw(20)<<"나이: ";
    cin>>age;
}
void ItemType::SetGenderFromKB(){ //키보드로 '고유번호' 입력
    cout<<setw(20)<<"성별: ";
    cin>>gender;
}
void ItemType::SetComposerFromKB(){ //키보드로 '작곡자' 입력
    cout<<setw(21)<<"작곡가: ";
    cin>>composer;
}
void ItemType::SetGenreFromKB(){ //키보드로 '장르' 입력
    cout<<setw(20)<<"장르: ";
    cin>>genre;
}
void ItemType::SetPrimaryFromKB(){ //키보드로 '고유번호' 입력
    cout<<setw(24)<<" 고유번호: ";
    cin>>primary;
}

void ItemType::SetRecordFromKB(){ //키보드로 '전체정보' 입력
    SetMusicFromKB();
    SetArtistFromKB();
    SetAgeFromKB();
    SetGenderFromKB();
    SetComposerFromKB();
    SetGenreFromKB();
    SetPrimaryFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin){      //객체에 파일의 내용을 읽어온다.
    fin>>music;
    fin>>artist;
    fin>>age;
    fin>>gender;
    fin>>composer;
    fin>>genre;
    fin>>primary;
    
    return 1;
}

int ItemType::WriteDataToFile(ofstream& fout){      //객체의 내용을 파일에 저장해준다.
    fout<<endl;
    fout<<music<<" ";
    fout<<artist<<" ";
    fout<<age<<" ";
    fout<<gender<<" ";
    fout<<composer<<" ";
    fout<<genre<<" ";
    fout<<primary;
    
    return 1;
}
// '=='를 가능하게 하는 연산자 오버로딩
bool ItemType::operator==(const ItemType& data) const {
    if(this->primary == data.GetPrimary())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool ItemType::operator!=(const ItemType& data) const {
    if(this->primary != data.GetPrimary())
        return true;
    else
        return false;
}
// 비교연산자 오버로딩 ' > '
bool ItemType::operator>(const ItemType& data) const {
    if(this->primary > data.GetPrimary())
        return true;
    else
        return false;
}
// 비교연산자 오버로딩 ' < '
bool ItemType::operator<(const ItemType& data) const {
    if(this->primary < data.GetPrimary())
        return true;
    else
        return false;
}
