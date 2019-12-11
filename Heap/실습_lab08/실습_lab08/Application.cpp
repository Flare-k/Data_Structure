#include "Application.h"


void Application::Run(){
    SelectHeap();   //어떤 힙을 사용할 것인지 여기서 먼저 결정.
    
    int num = 0;
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
            case 3:
                PopMusic();
                break;
            case 4: // 동일한 Primary Key를 가진 정보를 입력받은 정보로 치환
                ReplaceMusic();
                break;
            case 5: // Primary Key를 비교하여 같으면 정보를 출력 (순차탐색)
                cout<<"\t           ======== Search ========"<<endl;
                cout<<"\t           1 : Search by ID "<<endl;
                cout<<"\t           2 : Search by Artist "<<endl;
                cout<<"\t           3 : Search by Genre "<<endl;
                cout<<"\t           ========================"<<endl;
                cout<<"\n\t         Enter the number  --> ";
                cin>>num;
                if(num == 1)
                    SearchByid();
                else if(num == 2)
                    SearchByArtist();
                else if(num == 3)
                    SearchByGenre();
                break;
            case 6: //전체 레코드를 보여주는 기능
                ​​​DisplayAllMusic();
                break;
            case 7: // 모든 레코드 값을 지워주는 기능
                m_List->MakeEmpty();
                break;
            case 11:
                AddSongToPL();    //플레이 리스트에 추가하는 함수
                break;
            case 12:
                DeleteSongFrPL();
                break;
            case 13:
                PlayIOAddTime();
                break;
            case 14:
                PlayIOAddSelect();
                break;
            case 15:
                PlayIOFreq();
                break;
            case 16:
                PrintPlayList();    //플레이 리스트의 모든 곡을 보여주는 함수
                break;
            case 0: // 종료
                return;
            default:    // 맞지 않는 숫자를 입력했을 때의 출력
                cout << "\t Illegal selection...\n";
                break;
        }
    }
}

void Application::SelectHeap()      //여기서 먼저 자식클래스를 통해 인스턴스의 배열 크기를 결정해줘야한다.
{                                   //Add 함수 내에서 동적배열을 선언하면 계속 초기화가 되므로 배열의 인덱스가 계속 0이게 된다.
    int command;
    cout<<endl<<endl;
    cout<<"\t---ID -- Command ----- "<<endl;
    cout<<"\t   1 : Max Heap in Master List"<<endl;
    cout<<"\t   2 : Min Heap in Master List"<<endl;
    cout<<"\t   0 : Quit "<<endl;
    cout<<endl<<"\t Choose a Command--> ";
    cin>>command;
    cout<<endl;
    
    switch(command)
    {
        case 1:        // Max Heap
            m_List = new MaxHeap<ItemType>(10);
            break;
        case 2:        // Min Heap
            m_List = new MinHeap<ItemType>(10);
            break;
        case 0:
            return;
        default:
            cout << "\tIllegal sellection...\n";
            break;
    }
    
}


int Application::GetCommand(){
    int command;
    cout<<endl<<endl;
    cout<<"\t   ====== Master List ====== "<<endl;
    cout<<"\t   1 : Add Music "<<endl;
    cout<<"\t   2 : Delete Music "<<endl;
    cout<<"\t   3 : Pop Music "<<endl;
    cout<<"\t   4 : Replace Music "<<endl;
    cout<<"\t   5 : Search Music "<<endl;
    cout<<"\t   6 : Print Master List "<<endl;
    cout<<"\t   7 : Make empty list "<<endl;
    cout<<"\t   ======= Play List ======= "<<endl;
    cout<<"\t   11 : Add to Play List "<<endl;
    cout<<"\t   12 : Delete to PlayList "<<endl;
    cout<<"\t   13 : Play Insert Order "<<endl;
    cout<<"\t   14 : Play Selected Music "<<endl;
    cout<<"\t   15 : Play Frequency Order "<<endl;
    cout<<"\t   16 : Print Play List "<<endl;
    cout<<"\t   0 : Quit" << endl;
    cout<<endl<<"\t Choose a Command--> ";
    cin>>command;
    cout<<endl;
    
    return command;
}
//--------------------------------- Master List    -----------------------------------

int Application::AddMusic(){
    ItemType data;
    
    data.SetRecordFromKB(); //아이템 객체로 정보를 입력받습니다. (키보드로의 정보 입력은 여기서 단 한번 실행됨)
    
    if(m_List->IsFull()){
        cout<<"\t List is Full."<<endl;
        return 0;
    }
    else{
        m_List->Add(data);   //Master List에 저장.
      //  ​​​DisplayAllMusic();
        return 1;
    }
    
    
    return 1;
}

// 2.
int Application::DeleteMusic(){
    ItemType data;
    
    if(m_List->IsEmpty()){
        cout<<"\t List is Empty."<<endl;
        return 0;
    }
    else{
        data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
        if(m_List->Delete(data)){
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
}

// 3.
int Application::PopMusic(){
    if(!m_List->IsEmpty()){
        m_List->Pop();
        cout<<"\t Pop Complete"<<endl;
        return 1;
    }
    else{
        cout<<"\t Master List is Empty"<<endl;
        
    }
    
    return 1;
}



// 4.

void Application::ReplaceMusic(){
    ItemType data;
    
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    bool found = false;
    
    if(m_List->RetrieveItem(data, found)){
        data.DisplayRecordOnScreen(); // 내가 바꿀 객체가 무엇인지 다시 확인해보기 정도.
        cout<<"================= Replace ================="<<endl;
        data.SetRecordFromKB();
        m_List->ReplaceItem(data, found);   //비교하고 값 바꿔주기
        cout<<"================= Complete ================="<<endl;
    }
    else
        cout<<endl<<"============ Primary Key Error ============"<<endl;
}

// 5-1. 아이디로 찾기

void Application::SearchByid(){
    ItemType data;
    data.SetPrimaryFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    bool found = false;
    
    if(m_List->RetrieveItem(data,found)){   //HeapBase의 메소드.
        cout<<endl;
        
        if(found == true){
            cout<<"========= Music FOUND by Heap Search======="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"==============================================="<<endl;
        }
        else
            cout<<"===== Music Not Found by Heap Search ====="<<endl;
    }
    
}
// 5-2.가수이름으로 찾기

int Application::SearchByArtist(){
    ItemType data;
    
    int length = m_List->GetLength();
    
    string artist;
    cout<<"\t         Enter the Artist: ";
    cin>>artist;        //string으로 '가수명' 직접 입력 받음.
    cout<<endl;
    
    m_List->ResetList(); //배열 초기화
    
    for(int i = 0; i < length; i++){
        m_List->GetNextItem(data);
        
        if(data.GetArtist().find(artist) != string::npos){
            cout<<"========= Music FOUND by Artist ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================="<<endl;
        }
        
    }
    
    return 1;
}


// 5-3. 장르로 찾기
int Application::SearchByGenre(){
    ItemType data;
    
    int length = m_List->GetLength();
    
    string genre;
    cout<<"\t         Enter the Genre: ";
    cin>>genre;
    cout<<endl;
    
    m_List->ResetList();
    
    for(int i = 0; i < length; i++){
        m_List->GetNextItem(data);
        
        if(data.GetGenre().find(genre) != string::npos){
            cout<<"========= Music FOUND by Genre ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================"<<endl;
        }
    }
    
    return 1;
}


// 6. 전체출력
void Application::​​​DisplayAllMusic(){
    ItemType data;
    cout << "\n\t* Current Master list *" << endl;
    /*
    m_List->ResetList();
    int length = m_List->GetLength();
    
    for(int i = 0; i < length; i++){
        m_List->GetNextItem(data);
        data.DisplayRecordOnScreen();
    }*/
    if(!m_List->IsEmpty()){
        m_List->PrintHeap();
        //m_List->PrintHeapInOrder();
    }
}

// 7. MakeEmpty

//--------------------------------- Play List -----------------------------------
//11.
void Application::AddSongToPL(){
    ItemType data;
    PlayItem music;
    bool found = false;
    
    data.SetPrimaryFromKB();
    if(m_List->RetrieveItem(data, found)){
        music.SetRecord(data.GetPrimary(), data.GetTime(), data.GetNumPlay());
        music.SetTime(++times);
        p_List.Replace(music);
        p_List.Add(music);
    }
    else
    cout<<"\t Not Exist in Master List. Please, Try Again."<<endl;
    
    cout<<"\t==============================="<<endl;
    PrintPlayList();
    
}
//12.
int Application::DeleteSongFrPL(){
    ItemType data;
    PlayItem music;
    
    if(p_List.IsEmpty()){
        cout<<"\t PlayList is Empty."<<endl;
        return 0;
    }
    
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
    
    if(p_List.Delete(music)){
        cout<<"============ Deleted in Play List =========="<<endl;
        PrintPlayList();
        return 1;
    }
    else{
        cout<<"========== Not Deleted in Play List =========="<<endl;
        PrintPlayList();
        return 0;
    }
}
//13.
void Application::PlayIOAddTime(){
    ItemType data;
    PlayItem music;
    bool found = false;
    
    int count=0;    // 특정시점에서의 재생횟수.
    int num = 0;
    int limit = 0;
    
    if(!p_List.IsEmpty()){
        cout<<"\n\t============= Playing ============="<<endl;
        PrintPlayList();
        cout<<"\t =================================="<<endl;
        p_List.ResetList();
        
        while(1){
            limit++;    //길이보다 크거나 같아지면 초기화를 시켜주기 위해 설정.
            count++;    //현재 함수내에서 몇 번 재생되었는지 알기 위해.
            
            p_List.GetCurItem(music);  //플레이 리스트에 있는 데이터에 접근
            num = music.GetNumPlay() + 1;
            music.SetNumPlay(num);
            p_List.Replace(music);
            
            data.SetPrimary(music.GetPrimary());
            
            m_List->RetrieveItem(data, found);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
            //마스터리스트에 있는 정보로 가져옴.
            data.DisplayRecordOnScreen();
            cout<<"\t ======= [Play] >> 'Any Number' ==== [Stop] >> '0' ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(limit >= p_List.GetLength()){
                p_List.ResetList();
                limit = 0;
            }
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
            }
        }
    }
    else
        cout<<"\t >> Please, Add Song to Play List."<<endl;
    
    
}

//14.
void Application::PlayIOAddSelect(){
    ItemType data;
    PlayItem music;
    int num = 0;
    int count = 0;
    bool found = false;
    
    data.SetPrimaryFromKB();    //ID입력
    music.SetPrimary(data.GetPrimary());    //music에다가 초기화.
    if(p_List.Get(music)){      //해당 ID를 가진 데이터가 있는지 조회.
        cout<<"\n\t============= Playing ============="<<endl;
        while(1){
            count++;
            
            num = music.GetNumPlay() + 1;
            music.SetNumPlay(num);
            p_List.Replace(music);
            
            data.SetPrimary(music.GetPrimary());
            
            m_List->RetrieveItem(data, found);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
            //마스터리스트에 있는 정보로 가져옴.
            data.DisplayRecordOnScreen();
            //cout<<"\t ======= [Play] >> 'Any Number' ==== [Stop] >> '0' ======"<<endl;
            cout<<"\t ======= [Play]/[Stop] : Any number / 0 ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
                
            }
        }
    }
}

//15.
//플레이 리스트에서 자주 플레이된 횟수 순으로 플레이.
void Application::PlayIOFreq(){
    ItemType data;
    PlayItem music;
    
    int length = p_List.GetLength();
    //각 재생횟수 끼리 비교해서.. 가장 많은 횟수부터 내림차순으로..
    PlayItem *max = new PlayItem[length];
    PlayItem temp[length];
    //max라는 동적배열에다가 집어넣고 대소비교할 예정.
    p_List.ResetList();
    
    for(int i = 0; i<length;i++){
        p_List.GetCurItem(music);//첫번째 데이터를 가져옴.
        max[i] = music;
    }   //일단 다 받음. 다 받고 내림차순하는게 더 쉬울듯..
    int temp1, i;
    
    for(i=0; i<length-1; i++){
        temp1 = i;
        for(int j = i+1; j<length; j++){ //i=0 -> j=1,2 길이가 3이라가정하면..
            if(max[j].GetNumPlay() > max[temp1].GetNumPlay())
            temp1 = j;
        }
        temp[i] = max[i];
        max[i] = max[temp1];
        max[temp1] = temp[i];
    }
    cout << "\n\t* Current Play list *" << endl;
    for(int i=0; i<length; i++){
        max[i].DisplayPLRecordOnScreen();
    }
    
    bool found = false;
    int num = 0;
    int count = 0;
    int elem = 0;
    if(!p_List.IsEmpty()){
        cout<<"\n\t============= Playing ============="<<endl;
        
        while(1){
            count++;
            
            num = max[elem%length].GetNumPlay() + 1;
            max[elem%length].SetNumPlay(num);
            p_List.Replace(max[elem%length]);
            
            data.SetPrimary(max[elem%length].GetPrimary());
            
            m_List->RetrieveItem(data, found);
            data.DisplayRecordOnScreen();
            
            cout<<"\t ======= [Play]/[Stop] : Any number / 0 ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
            }
            elem++;
        }
    }
    else
    cout<<"\t >> Please, Add Song to Play List."<<endl;
    
}
//16.
void Application::PrintPlayList(){
    PlayItem music;
    DIterator<PlayItem> iter(p_List);
    music = iter.Next();
    cout << "\n\t* Current Play list *" << endl;
    
    while(iter.NextNotNull()){
        music.DisplayPLRecordOnScreen();
        music = iter.Next();
    }
}

