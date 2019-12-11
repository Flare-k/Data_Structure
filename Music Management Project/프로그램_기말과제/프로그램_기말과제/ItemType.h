#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define MAXSIZE 100


class ItemType{
private:
    string music;   //곡명
    string artist;  //가수 또는 연주자
    string composer;//작곡가
    string genre;   //장르
    string primary;    //고유번호
    int numPlay;    //실행된 횟수
    int inTime;     //들어온 순서
    int age;
    string gender;
public:
    ItemType();
    ~ItemType();
    
    string GetMusic();
    string GetArtist();
    string GetComposer();
    string GetGenre();
    string GetPrimary() const;
    int GetTime();
    int GetNumPlay();
    int GetAge();
    string GetGender();
    
    void SetMusic(string inMusic);
    void SetArtist(string inArtist);
    void SetComposer(string inComposer);
    void SetGenre(string inGenre);
    void SetPrimary(string inPri);
    void SetTime(int _inTime);
    void SetNumPlay(int _numPlay);
    void SetAge(int _age);
    void SetGender(string _gender);
    void SetRecord(string inMusic, string inComposer,string inArtist, string inGenre, string inPri, int _inTime, int _numPlay);
    
    void SetSingerRecord(string inMusic,string inArtist, string inPri, string _gender, int _age);
    
    
    //곡이름 / 가수 / 작곡가 / 장르 / 고유번호 / 들어온 순서 / 실행 횟수 / 나이 / 성별
    void DisplayMusicOnScreen();
    void DisplayArtistOnScreen();
    void DisplayComposerOnScreen();
    void DisplayGenreOnScreen();
    void DisplayPrimaryOnScreen();
    void DisplayTimeOnScreen();
    void DisplayNumPlayOnScreen();
    void DisplayAgeOnScreen();
    void DisplayGenderOnScreen();
    
    void DisplayAllOnScreen();
    void DisplayRecordOnScreen();
    void DisplayPLRecordOnScreen();
    
    void SetMusicFromKB();
    void SetComposerFromKB();
    void SetArtistFromKB();
    void SetGenreFromKB();
    void SetPrimaryFromKB();
    void SetAgeFromKB();
    void SetGenderFromKB();
    void SetRecordFromKB();
    
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);
    
    bool operator==(const ItemType& data) const;
    bool operator!=(const ItemType& data) const;
    bool operator>(const ItemType& data) const;
    bool operator<(const ItemType& data) const;
    
    
    friend ostream& operator << (ostream& out, ItemType& item){
        out<<setw(20)<<item.GetMusic()
        <<setw(14)<<item.GetArtist()
        <<setw(7)<<item.GetAge()
        <<setw(15)<<item.GetGender()
        <<setw(15)<<item.GetComposer()
        <<setw(14)<<item.GetGenre()
        <<setw(13)<<item.GetPrimary()<<endl;
        out<<endl;
        return out;
    }
};


