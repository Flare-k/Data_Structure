#include "PlayItem.h"

PlayItem::PlayItem(){
    music = "";
    artist = "";
    primary = "";
    numPlay = 0;
    inTime = 0;
    like = 0;
    score = numPlay*like;
}
PlayItem::~PlayItem(){}

string PlayItem::GetMusic(){return music;}
string PlayItem::GetArtist(){return artist;}
string PlayItem::GetPrimary() const{return primary;}
int PlayItem::GetTime() const {return inTime;}
int PlayItem::GetNumPlay(){return numPlay;}
int PlayItem::GetLike(){return like;}
float PlayItem::GetScore(){return numPlay*like;}

void PlayItem::SetMusic(string _music){music = _music;}
void PlayItem::SetArtist(string _artist){artist = _artist;}
void PlayItem::SetPrimary(string inPri){primary = inPri;}
void PlayItem::SetTime(int _inTime){inTime = _inTime;}
void PlayItem::SetNumPlay(int _numPlay){numPlay = _numPlay;}
void PlayItem::SetLike(int _like){like = _like;}
void PlayItem::SetScore(float _score){score = _score;}

void PlayItem::SetRecord(string _music, string _artist, string inPri, int _inTime, int _numPlay, int _like){
    SetMusic(_music);
    SetArtist(_artist);
    SetPrimary(inPri);
    SetTime(_inTime);
    SetNumPlay(_numPlay);
    SetLike(_like);
}


// 고유번호 / 들어온 순서 / 재생된 횟수
void PlayItem::DisplayMusicOnScreen(){
    cout<<"\t 제목: "<<music<<endl;
}
void PlayItem::DisplayArtistOnScreen(){
    cout<<"\t 가수: "<<artist<<endl;
}
void PlayItem::DisplayPrimaryOnScreen(){
    cout<<"\t 고유번호: "<<primary<<endl;
}
void PlayItem::DisplayNumPlayOnScreen(){
    cout<<"\t 재생횟수: "<<numPlay<<endl;
}
void PlayItem::DisplayLikeOnScreen(){
    cout<<"\t 좋아요 : "<<like<<endl;
}
void PlayItem::DisplayScoreOnScreen(){
    cout<<"\t 평점 : "<<numPlay*like<<endl;
}

void PlayItem::DisplayPLRecordOnScreen(){
    DisplayMusicOnScreen();
    DisplayArtistOnScreen();
    DisplayPrimaryOnScreen();
    DisplayNumPlayOnScreen();
    DisplayLikeOnScreen();
    DisplayScoreOnScreen();
    cout<<endl;
}

void PlayItem::DisplayAllPLOnScreen(){
    cout<<setw(22)<<music
    <<setw(15)<<artist
    <<setw(9)<<primary
    <<setw(12)<<numPlay
    <<setw(7)<<like
    <<setw(7)<<numPlay*like<<endl;
}

int PlayItem::ReadDataFromFile(ifstream& fin){
    fin>>music;
    fin>>artist;
    fin>>primary;
    fin>>numPlay;
    fin>>like;
    return 1;
}
int PlayItem::WriteDataToFile(ofstream& fout){
    fout<<endl;
    fout<<music<<" ";
    fout<<artist<<" ";
    fout<<primary<<" ";
    fout<<numPlay<<" ";
    fout<<like;
    return 1;
}


/*
 들어온 순서대로 정렬하기 위한 연산자 오버로딩
 */

// '=='를 가능하게 하는 연산자 오버로딩
bool PlayItem::operator==(const PlayItem& data) const {
    if(this->primary == data.GetPrimary())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool PlayItem::operator!=(const PlayItem& data) const {
    if(this->primary != data.GetPrimary())
        return true;
    else
        return false;
}


// 비교연산자 오버로딩 ' > '
bool PlayItem::operator>(const PlayItem& data) const {
    if(this->primary > data.GetPrimary())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool PlayItem::operator<(const PlayItem& data) const {
    if(this->primary < data.GetPrimary())
        return true;
    else
        return false;
}



