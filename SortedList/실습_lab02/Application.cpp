#include "Application.h"
#include "SortedList.h"
#define FILENAMESIZE 1024

void Application::Run(){
    while(1) {
        m_Command = GetCommand();
        switch(m_Command)
        {
            case 1: //객체를 추가하는 기능
                AddMusic();
                break;
            case 2: //기존 레코드 삭제 기능
                DeleteMusic();
                break;
            case 3: // 동일한 Primary Key를 가진 정보를 입력받은 정보로 치환
                ReplaceMusic();
                break;
            case 4: // Primary Key를 비교하여 같으면 정보를 출력 (순차탐색)
                SearchByid_Seq();
                break;
            case 5: // Primary Key를 비교하여 같으면 정보를 출력 (이진탐색)
                SearchByid_BinaryS();
                break;
            case 6: // '가수명'을 입력하여 비슷한 내용을 가진 객체 정보 전부 찾기
                SearchByArtist();
                break;
            case 7: // '장르'를 입력하여 비슷한 내용을 가진 객체 정보 전부 찾기
                SearchByGenre();
                break;
            case 8: //전체 레코드를 보여주는 기능
                ​​​DisplayAllMusic();
                break;
            case 9: // 모든 레코드 값을 지워주는 기능
                m_List.MakeEmpty();
                break;
            case 10: // 파일에 저장된 내용을 불러오는 기능
                ReadDataFromFile();
                break;
            case 11: //파일에 저장하는 기능
                WriteDataToFile();
                break;
            case 0: // 종료
                return;
            default:    // 맞지 않는 숫자를 입력했을 때의 출력
                cout << "\t Illegal selection...\n";
                break;
                
        }
    }
}
int Application::GetCommand(){
    int command;
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t   1 : Add Music " << endl;
    cout << "\t   2 : Delete Music " << endl;
    cout << "\t   3 : Replace Music " << endl;
    cout << "\t   4 : Search Music by SQ " << endl;
    cout << "\t   5 : Search Music by BS " << endl;
    cout << "\t   6 : Search by Artist " << endl;
    cout << "\t   7 : Search by Genre " << endl;
    cout << "\t   8 : Print all on screen " << endl;
    cout << "\t   9 : Make empty list " << endl;
    cout << "\t   10 : Get from file " << endl;
    cout << "\t   11 : Put to file " << endl;
    cout << "\t   0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}


// 1.
int Application::AddMusic(){
    if(m_List.IsFull()){
        cout<<"List is Full."<<endl;
        return 0;
    }
    ItemType data;
    /*
     객체에 키보드로 모든 정보의 값을 입력받고
     SortedList class에 있는 Add 함수로 넘겨준다.
     값을 저장되면 모든 객체 정보를 화면에 출력해준다.
     */
    data.SetRecordFromKB();
    
    m_List.Add(data);
    cout<<"\t=============================="<<endl;
    ​​​DisplayAllMusic();
    return 1;
}
// 2.
int Application::DeleteMusic(){
    if(m_List.IsEmpty()){
        cout<<"\t List is Empty."<<endl;
        return 0;
    }
    ItemType data;
    /*
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Delete 함수로 넘겨준다.
     값을 찾으면 해당 객체를 제외한 모든 객체 정보를 화면에 출력해준다.
     */
    data.SetPrimaryFromKB();
    if(m_List.Delete(data)){
        cout<<"============ Music is Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        return 1;
    }
    else{
        cout<<"============ Music is not Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        return 0;
    }
    
}

// 3.
void Application::ReplaceMusic(){
    ItemType data;
    /*
     객체에 키보드로 Primary Key를 입력받는다.
     만약 해당 객체가 있다면, 입력받은 객체를 확인하기 위해 해당 정보를 가진 객체 출력.
     바꿀내용을 하나씩 키보드로 바꿈. 단, Primary Key의 내용은 달라지면 안 됨.
     Primary Key를 미리 확인한 객체 정보와 다르게 입력하면 저장이 되지 않거나,
     입력한 Primary Key를 가진 다른 객체의 정보가 바뀌게 됨.
     */
    data.SetPrimaryFromKB();
    if(m_List.Retrieve_Seq(data)){
        data.DisplayRecordOnScreen(); // 내가 바꿀 객체가 무엇인지 다시 확인해보기 정도.
        cout<<"================= Replace ================="<<endl;
        data.SetTypeFromKB();
        data.SetMusicFromKB();
        data.SetComposerFromKB();
        data.SetArtistFromKB();
        data.SetGenreFromKB();
        data.SetPrimaryFromKB();    // 위에 출력된 내용의 Primary Key와 같게 입력해야함.
        
        m_List.Replace(data);   //비교하고 값 바꿔주기
        cout<<"================= Complete ================="<<endl;
    }
    else
        cout<<endl<<"============ Primary Key Error ============"<<endl;
}
// 4.
void Application::SearchByid_Seq(){        //Get함수와 호응..
    ItemType data;
    /*
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Seq 함수로 넘겨준다.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    data.SetPrimaryFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    
    if(m_List.Retrieve_Seq(data)){   //ArrayList의 메소드.
        cout<<endl;
        cout<<"========= Music FOUND by Sequence Search======="<<endl;
        data.DisplayRecordOnScreen();
        cout<<"==============================================="<<endl;
        
    }
    else{
        cout<<endl;
        cout<<"===== Music Not Found by Sequence Search ====="<<endl;
    }
    
}
// 5.
void Application::SearchByid_BinaryS(){
    ItemType data;
    /*
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Binary함수로 넘겨준다.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    data.SetPrimaryFromKB();
    
    if(m_List.Retrieve_Binary(data)){   //ArrayList의 메소드.
        cout<<endl;
        cout<<"========= Music FOUND by Binary Search======="<<endl;
        data.DisplayRecordOnScreen();
        cout<<"============================================="<<endl;
        
    }
    else{
        cout<<endl;
        cout<<"===== Music Not Found by Binary Search ====="<<endl;
    }
}

// 6.
/*
 예시,
 키보드에서 이름을 읽고 list에서 이 이름을 가진 모든 레코드를 찾아서 화면에 출력.
 예) '김'이 입력되면 이름에 '김'이 포함되는 모든 항목("김”, “김파래“, “김연아“)을 화면에 출력
 */

//가수이름으로 찾기
int Application::SearchByArtist(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string artist;
    cout<<"\t Enter the Artist: ";
    cin>>artist;        //string으로 '가수명' 직접 입력 받음.
    cout<<endl;
    
    m_List.ResetList(); //배열 초기화
    /*
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetArtist() 문자열에 cin으로 입력받은 artist의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetArtist().find(artist) != string::npos){
            data.DisplayRecordOnScreen();
        }
    }
    
    return 1;
}


// 7. 장르로 찾기
int Application::SearchByGenre(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string genre;
    cout<<"\t Enter the Genre: ";
    cin>>genre;
    cout<<endl;
    
    m_List.ResetList();
    /*
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetGenre() 문자열에 cin으로 입력받은 genre의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetGenre().find(genre) != string::npos){
            data.DisplayRecordOnScreen();
        }
    }
    
    return 1;
}


// 8. 전체출력
void Application::​​​DisplayAllMusic(){
    ItemType data;
    cout << "\n\t* Current list *" << endl;
    
    int length = m_List.GetLength();
    m_List.ResetList();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.DisplayRecordOnScreen();
    }
}


// 9. MakeEmpty



// 10, 11. 파일 입출력
int Application::OpenInFile(string &fileName){
    m_InFile.open(fileName);
    
    if(!m_InFile)
        return 0;
    else
        return 1;
}

int Application::OpenOutFile(string &fileName){
    m_OutFile.open(fileName);
    
    if(!m_OutFile)
        return 0;
    else
        return 1;
}
int Application::ReadDataFromFile(){
    ItemType data;
    
    string filename;
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenInFile(filename))
        return 0;
    
    while(!m_InFile.eof()){         //만약 읽을 파일이 끝나지 않았다면 계속 읽어 들일 것!
        data.ReadDataFromFile(m_InFile);        //ItemType의 메소드
        m_List.Add(data);//읽은거 저장..
    }
    m_InFile.close();
    
    ​​​DisplayAllMusic();
    return 1;
}
int Application::WriteDataToFile(){
    ItemType data;
    
    string filename="";
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenOutFile(filename))
        return 0;
    
    m_List.ResetList();//ArrayList의 메소드.
    
    int length = m_List.GetLength();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.WriteDataToFile(m_OutFile);
    }
    
    m_OutFile.close();    // file close
    
    return 1;
}




