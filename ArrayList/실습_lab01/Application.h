#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "ArrayList.h"

using namespace std;

class Application{
private:
    int m_Command;
    ArrayList m_List;
    ifstream m_InFile;
    ofstream m_OutFile;
public:
    Application(){
        m_Command = 0;
    }
    ~Application(){}
    
    void Run();
    int GetCommand();
    int AddMusic();
    int DeleteMusic();
    void ​​​DisplayAllMusic();
    
    int OpenInFile(string &fileName);
    int OpenOutFile(string &fileName);
    int ReadDataFromFile();
    int ​​WriteDataToFile();
    
    void ReplaceMusic();
    void RetrieveMusic();
    
};
