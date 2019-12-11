#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
//Play List에 들어갈 객체.
class PlayItem{
private:
    string music;       //곡명
    string artist;      //가수명
    string primary;     //고유번호
    int numPlay;        //실행된 횟수
    int inTime;         //들어온 순서
    int like;           //좋아요
    int score;          //플레이 횟수와 좋아요 수에 대한 평점.
public:
    PlayItem();
    //PlayItem의 디폴트 소멸자
    ~PlayItem();
    //PlayItem의 소멸자
    
    string GetMusic();
    //음악정보 리턴
    string GetArtist();
    //가수정보 리턴
    string GetPrimary() const;
    //고유번호 리턴
    int GetTime() const;
    //삽입순서정보 리턴
    int GetNumPlay();
    //재생횟수 정보 리턴
    int GetLike();
    //'좋아요'정보 리턴
    float GetScore();
    //평점 정보 리턴
    
    void SetMusic(string _music);
    //음악에 대한 내용 할당
    void SetArtist(string _artist);
    //가수에 대한 내용 할당
    void SetPrimary(string inPri);
    //고유번호에 대한 내용 할당
    void SetTime(int _inTime);
    //삽입순서에 대한 내용 할당
    void SetNumPlay(int _numPlay);
    //재생횟수에 대한 내용 할당
    void SetLike(int _like);
    //'좋아요'에 대한 내용 할당
    void SetScore(float _score);
    //평점에 대한 내용 할당
    void SetRecord(string _music, string _artist, string inPri, int _inTime, int _numPlay, int _like);
    //모든정보에 대한 내용 할당
    
    void DisplayMusicOnScreen();
    //제목 출력
    void DisplayArtistOnScreen();
    //가수 출력
    void DisplayPrimaryOnScreen();
    //고유번호 출력
    void DisplayTimeOnScreen();
    //삽입순서 출력
    void DisplayNumPlayOnScreen();
    //재생횟수 출력
    void DisplayLikeOnScreen();
    //'좋아요' 출력
    void DisplayScoreOnScreen();
    //평점 출력
    void DisplayPLRecordOnScreen();
    //플레이 리스트에서 보여줄 정보 출력
    void DisplayAllPLOnScreen();
    //플레이 리스트에서 보여줄 다른 포맷의 정보출력
    
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);
    bool operator==(const PlayItem& data) const;
    bool operator!=(const PlayItem& data) const;
    bool operator>(const PlayItem& data) const;
    bool operator<(const PlayItem& data) const;
};


