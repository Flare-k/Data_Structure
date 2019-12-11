#include "Application.h"

Application::Application(){
    m_Command=0;
    times = 0;
}
Application::~Application(){
    delete [] p_List;
}

void Application::Run(){
    int subnum = 0;
        while(1) {
            m_Command = GetCommand();
            switch(m_Command)
            {
                case 1:
                    ManageUser();
                    break;
                case 2:
                    while(1){
                        cout<<endl;
                        cout<<"\t   ========= Master List ========= "<<endl;
                        cout<<"\t   1 : 곡 추가 "<<endl;
                        cout<<"\t   2 : 곡 삭제 "<<endl;
                        cout<<"\t   3 : 곡 정보 수정 "<<endl;
                        cout<<"\t   4 : 곡 찾기 "<<endl;
                        cout<<"\t   5 : 모든 곡 보기 "<<endl;
                        cout<<"\t   6 : 모든 곡 삭제 "<<endl;
                        cout<<"\t   7 : 모든 가수 보기 "<<endl;
                        cout<<"\t   8 : 모든 노래 보기 "<<endl;
                        cout<<"\t   9 : 파일에서 불러오기 "<<endl;
                        cout<<"\t   10 : 파일에 저장하기 "<<endl;
                        cout<<"\t   0 : 돌아가기 "<<endl;
                        cout<<endl<<"\t   Choose a Command--> ";
                        cin>>subnum;
                        
                        if(subnum == 1)
                            AddMusic();
                        else if(subnum == 2)
                            DeleteMusic();//기존 레코드 삭제 기능
                        else if(subnum == 3)
                            ReplaceMusic(); // 동일한 Primary Key를 가진 정보를 입력받은 정보로 치환
                        else if(subnum == 4){
                            int subnum1;
                            cout<<endl;
                            cout<<"\t           =========== Search ==========="<<endl;
                            cout<<"\t           1 : 순차탐색으로 곡 검색 "<<endl;
                            cout<<"\t           2 : 이진탐색으로 곡 검색 "<<endl;
                            cout<<"\t           3 : 가수명으로 곡 검색 "<<endl;
                            cout<<"\t           4 : 장르명으로 곡 검색 "<<endl;
                            cout<<"\t           =============================="<<endl;
                            cout<<"\n\t           Choose a Command--> ";
                            cin>>subnum1;
                            if(subnum1 == 1)
                                SearchByid_Seq();
                            else if(subnum1 == 2)
                                SearchByid_BinaryS();
                            else if(subnum1 == 3)
                                SearchByArtist();
                            else if(subnum1 == 4)
                                SearchByGenre();
                        }
                        /*
                         Search와 관련된 함수가 4개가 있어서 한 케이스 안에
                         조건문으로 묶어놨습니다.
                         */
                        else if(subnum == 5)
                            ​​​DisplayAllMusic();//전체 레코드를 보여주는 기능
                        else if(subnum == 6)// 모든 레코드 값을 지워주는 기능
                            m_List.MakeEmpty();
                        else if(subnum == 7)
                            ​​​DisplayAllSingerList();
                        else if(subnum == 8)
                            ​​​DisplayAllSongList();
                        else if(subnum == 9)// 파일에 저장된 내용을 불러오는 기능
                            ReadDataFromFile();
                        else if(subnum == 10)//파일에 저장하는 기능
                            WriteDataToFile();
                        else if(subnum == 0)
                            break;
                    }
                    break;
                case 0: // 종료
                    return;
                default:    // 맞지 않는 숫자를 입력했을 때의 출력
                    cout << "\t 잘 못 입력하셨습니다...\n";
                    break;
            }
        }
    
}
int Application::GetCommand(){
    int command;
    cout<<endl<<endl;
    cout<<"\t======== KYW MUSIC ======== "<<endl;
    cout<<"\t   1 : 회원 관리 "<<endl;
    cout<<"\t   2 : 관리자 모드 "<<endl;
    cout<<"\t   0 : 프로그램 종료 " << endl;
    cout<<"\t=========================== "<<endl;
    
    cout<<endl<<"\t Choose a Command--> ";
    cin>>command;
    cout<<endl;
    
    return command;
}

void Application::ManageUser(){
    int command;
    cout<<endl<<endl;
    cout<<"\t           ======= USER MODE ======= "<<endl;
    cout<<"\t           --ID -- Command --------- "<<endl;
    cout<<"\t              1 : 로그인 "<<endl;
    cout<<"\t              2 : 회원가입 "<<endl;
    cout<<"\t              3 : 회원정보 보기 "<<endl;
    cout<<"\t              0 : 종료 "<<endl;
    cout<<"\t           ========================= "<<endl;
    cout<<"\n\t           Choose a Command--> ";
    cin>>command;
    cout<<endl;
    
    switch(command){
        case 1:
            LoginUser();    //로그인
            break;
        case 2:
            AddUser();      //회원가입
            break;
        case 3:
            DisplayUser();  //모든 회원정보 확인
            break;
        case 0:
            Run();          //메인화면(KYW MUSIC)으로 돌아가기
            break;
        default:
            cout << "\t           잘 못 입력하셨습니다...\n";
            break;
    }
}

void Application::RunPlaylist(UserType& user){
    int num = 0;
    while(1){
        cout<<endl;
        cout<<"\t   ========== Play List ========== "<<endl;
        cout<<"\t   Player: "<<user.GetUserID()<<", Player List Num: "<<user.GetPlayListNum()<<endl;
        cout<<"\t   1 : 곡 추가 "<<endl;
        cout<<"\t   2 : 곡 삭제 "<<endl;
        cout<<"\t   3 : 곡 재생 "<<endl;;
        cout<<"\t   4 : '좋아요' 누르기 "<<endl;
        cout<<"\t   5 : 음원 순위 "<<endl;
        cout<<"\t   6 : 플레이 리스트 보기 "<<endl;
        cout<<"\t   7 : '좋아요' 리스트 보기 "<<endl;
        cout<<"\t   8 : 곡 찾기 "<<endl;
        cout<<"\t   0 : 돌아가기 "<<endl;
        cout<<endl<<"\t   Choose a Command--> ";
        cin>>num;
        
        if(num == 1)
            AddtoPlayList(user);    //유저의 PlayList에 곡 추가
        else if(num == 2)
            DeletetoPlayList(user);    //유저의 PlayList 곡 삭제
        else if(num == 3){         //유저의 PlayList 곡 재생
             int subnum;
             cout<<endl;
             cout<<"\t           ============ Play ============"<<endl;
             cout<<"\t           1 : 추가 순서대로 재생 "<<endl;
             cout<<"\t           2 : 원하는 곡 재생 "<<endl;
             cout<<"\t           3 : 즐겨듣는 곡 재생 "<<endl;
             cout<<"\t           4 : '좋아요' 곡 재생 "<<endl;
             cout<<"\t           =============================="<<endl;
             cout<<"\n\t           Choose a Command--> ";
             cin>>subnum;
             
             if(subnum == 1)
                 PlayInsertOrder(user); //추가한 순서대로 재생
             else if(subnum == 2)
                 PlayIOAddSelect(user); //원하는 곡 재생
             else if(subnum == 3)
                 PlayIOFreq(user);      //즐겨듣는 곡 재생
             else if(subnum == 4)
                 PlayLikeMusic(user);   //'좋아요'곡 재생
         }
        else if(num == 4)
            ClicktheLike(user);        //'좋아요' 클릭
        else if(num == 5)
            PrintPlayRank(user);       //음원 순위 확인
        else if(num == 6)
            PrintPlayList(user);    //플레이 리스트의 모든 곡을 보여주는 함수 함수
        else if(num == 7)
            PrintLikeList(user);        //'좋아요'를 누른 곡만 확인
        else if(num == 8)
            SearchinPL_BinaryS(user);   //곡 검색
        else if(num == 0){
            cout<<"\t Player "<<user.GetUserID()<<" Log-out "<<endl;
            break;
        }
    }
}

/*
 --------------------------------- User List -----------------------------------
 */

int Application::AddUser(){ //회원가입.
    UserType user;
    cout<<"\t           ========= 회원가입 ========="<<endl;
    user.SetUserFromKB();   //회원가입에 필요한 아이디, 패스워드 입력.
    if(!u_List.Get(user)){
        u_List.Add(user);
        cout<<"\n\t           >> 회원가입이 완료되었습니다."<<endl;
        cout<<"\t           =========================="<<endl;
    }
    else
        cout<<"\n\t           >> 이미 존재하는 회원입니다."<<endl;
    return 1;
    
}

int Application::LoginUser(){   //로그인
    UserType user;
    cout<<"\t           ========== 로그인 =========="<<endl;
    user.SetUserFromKB();
    cout<<"\t           =========================="<<endl;
    if(u_List.Get(user)){
        cout<<"\n\t           >> 환영합니다! "<<user.GetUserID()<<"님. "<<endl;
        RunPlaylist(user);
    }
    else{
        cout<<"\n\t           >> 아이디 및 비밀번호 오류 또는 회원정보가 존재하지 않습니다."<<endl;
    }
    return 1;
}
void Application::DisplayUser(){    //모든 회원의 정보 출력
    UserType user;
    cout<<"\n\t\t * Current User list *"<<endl;
    
    int length = u_List.GetLength();
    u_List.ResetList();
    
    for(int i = 0; i < length; i++){
        u_List.GetCurItem(user);
        user.DisplayUserOnScreen();
    }
    
}
/*
 --------------------------------- Master List    -----------------------------------
 */
int Application::AddMusic(){
    
    if(m_List.IsFull()){
        cout<<"\t List is Full."<<endl;
        return 0;
    }
    ItemType data;
    SingerType singer;
    SimpleItemType songinput;
    
    data.SetRecordFromKB(); //아이템 객체로 정보를 입력받습니다. (키보드로의 정보 입력은 여기서 단 한번 실행됨)
    
    songinput.SetSimpleItem(data.GetPrimary(), data.GetMusic());//SongType객체에 ID, 곡명을 담습니다.
    
    //SingerType에는 가수명, 나이, 성별, SimpleItemType(고유번호, 곡명)만 담습니다.
    singer.SetSinger(data.GetArtist(), data.GetAge(), data.GetGender(), songinput);
    
    m_List.Add(data);   //Master List에 저장.
    
    
    
     if(s_List.IsEmpty() || !s_List.Get(singer)){//값이 존재하지 않을 경우.
         cout<<"\n\t >>NOT EXIST IN SingerList."<<endl;
         cout<<"\t >>SAVE IN SingerList."<<endl;
         s_List.Add(singer);     //SingList가 비어있을 경우 저장.
         simple_List.Add(songinput); //SongList에도 저장.
     }
     else if(s_List.Get(singer)){//값이 존재할 경우.
         cout<<"\t >>This Singer is already exist."<<endl;
     }
     cout<<"\t=============================="<<endl;
    
    ​​​DisplayAllMusic();
    
    return 1;
}

// 2.
int Application::DeleteMusic(){
    ItemType data;
    SingerType singer;
    SimpleItemType song;
    
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    song.SetId(data.GetPrimary());  //SongType 객체에 Primary Key값을 입력해줌.
    singer.SetSonglist(song);       //SingerType 객체에 마찬가지로 Primary Key값을 입력해줌.
    
    if(m_List.IsEmpty()){
        cout<<"\t List is Empty."<<endl;
        return 0;
    }
    
    if(m_List.Delete(data)){
        cout<<"============ Music is Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        //​​​DisplayAllSingerList();
        //​​​DisplayAllSongList();
        return 1;
    }
    else{
        cout<<"============ Music is not Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        //    ​​​DisplayAllSingerList();
        //    ​​​DisplayAllSongList();
        return 0;
    }
    
}

// 3.
void Application::ReplaceMusic(){
    ItemType data;
    SingerType singer;
    SimpleItemType song;
    bool found;
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    song.SetId(data.GetPrimary());  //SongType 객체에 Primary Key값을 입력해줌.
    singer.SetSonglist(song);       //SingerType 객체에 마찬가지로 Primary Key값을 입력해줌.
    
    if(m_List.Retrieve_Binary(data)){
        data.DisplayRecordOnScreen(); // 내가 바꿀 객체가 무엇인지 다시 확인해보기 정도.
        cout<<"================= Replace ================="<<endl;
        data.SetRecordFromKB();
        song.SetSimpleItem(data.GetPrimary(), data.GetMusic());//SongType객체에 ID, 곡명을 담습니다.
        //SingerType에는 가수명, 나이, 성별만 담습니다.
        singer.SetSinger(data.GetArtist(), data.GetAge(), data.GetGender(), song);
        
        m_List.Replace(data);   //비교하고 값 바꿔주기
        s_List.Replace(singer, found);
        simple_List.Replace(song, found);
        cout<<"================= Complete ================="<<endl;
    }
    else
        cout<<endl<<"============ Primary Key Error ============"<<endl;
}

// 4-1.
void Application::SearchByid_Seq(){
    ItemType data;
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
// 4-2.
void Application::SearchByid_BinaryS(){
    ItemType data;
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

// 4-3.가수이름으로 찾기

int Application::SearchByArtist(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string artist;
    cout<<"\t         Enter the Artist: ";
    cin>>artist;        //string으로 '가수명' 직접 입력 받음.
    cout<<endl;
    
    m_List.ResetList(); //배열 초기화
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetArtist().find(artist) != string::npos){
            cout<<"========= Music FOUND by Artist ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================="<<endl;
        }
    }
    
    return 1;
}


// 4-4. 장르로 찾기
int Application::SearchByGenre(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string genre;
    cout<<"\t         Enter the Genre: ";
    cin>>genre;
    cout<<endl;
    
    m_List.ResetList();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetGenre().find(genre) != string::npos){
            cout<<"========= Music FOUND by Genre ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================"<<endl;
        }
    }
    return 1;
}
// 5. 전체출력
void Application::​​​DisplayAllMusic(){
    ItemType data;
    cout << "\n\t* Current Master list *" << endl;
    
    int length = m_List.GetLength();
    m_List.ResetList();
    cout << "\t________________________________________________________________________________________________________" << endl;
    cout << "\t|     Music      |   Artist   |   Age   |     Gender     |  Composer |      Genre    |   Primary Key   |" << endl;
    cout << "\t--------------------------------------------------------------------------------------------------------" << endl;
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        //data.DisplayRecordOnScreen();
        data.DisplayAllOnScreen();
    }
}

// 6. MakeEmpty

// 7, 8. 파일 입출력
int Application::OpenInFile(string &fileName){
    m_InFile.open(fileName);
    
    if(!m_InFile)
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
        m_List.Add(data);//읽은 거 저장..
    }
    m_InFile.close();
    
    ​​​DisplayAllMusic();
    return 1;
}
int Application::OpenOutFile(string &fileName){
    m_OutFile.open(fileName);
    
    if(!m_OutFile)
        return 0;
    else
        return 1;
}
int Application::WriteDataToFile(){
    ItemType data;
    
    string filename="";
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenOutFile(filename))
        return 0;
    
    m_List.ResetList();
    
    int length = m_List.GetLength();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.WriteDataToFile(m_OutFile);
    }
    
    m_OutFile.close();    // file close
    
    return 1;
}
/*
--------------------------------- Play List -----------------------------------
*/
void Application::AddtoPlayList(UserType& user){
    ItemType data;
    PlayItem music;
    data.SetPrimaryFromKB();
    if (m_List.Retrieve_Binary(data)){
        //music에 곡제목, 아티스트, 고유번호, 삽입순서,재생횟수를 할당.
        music.SetRecord(data.GetMusic(), data.GetArtist(), data.GetPrimary(), data.GetTime(), data.GetNumPlay(), 0);
        
        if (p_List[user.GetPlayListNum()-1].IsFull()) {
            music.SetTime(++times);
            p_List[user.GetPlayListNum()-1].Replace(music);
            
            p_List[user.GetPlayListNum()-1].DeQueue(music);
            cout << "\n\t >> Please, Dequeue Item... " << endl;
            p_List[user.GetPlayListNum()-1].EnQueue(music);
            
        }
        else {
            p_List[user.GetPlayListNum()-1].EnQueue(music);
            music.SetTime(++times);
            p_List[user.GetPlayListNum()-1].Replace(music);
        }
        cout << "\t   ===============================" << endl;
    }
    else {
        cout << "\n\t >> Please, Add Master List. " << endl;
    }
    
}

int Application::DeletetoPlayList(UserType& user){
    ItemType data;
    PlayItem music;
    
    if(p_List[user.GetPlayListNum()-1].IsEmpty()){
        cout<<"\t PlayList is Empty. "<<endl;
        return 0;
    }
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
    
    
    if(p_List[user.GetPlayListNum()-1].Delete(music)){
        cout<<"============ Deleted in Play List =========="<<endl;
        PrintPlayList(user);
        return 1;
    }
    else{
        cout<<"========== Not Deleted in Play List =========="<<endl;
        PrintPlayList(user);
        return 0;
    }
    
}

 void Application::PlayInsertOrder(UserType& user){
     ItemType qdata;
     PlayItem music;
     
     
     cout<<"\n\t============= Playing ============="<<endl;
     int count=0;    // 특정시점에서의 재생횟수.
     
     cout << "\n\t* Current Play list *" << endl;
     PrintPlayList(user);
     cout<<"\t ========================="<<endl;
     p_List[user.GetPlayListNum()-1].ResetList();
     
     int num = 0;
     int limit = 0;
     
     if(!p_List[user.GetPlayListNum()-1].IsEmpty()){
     while(1){
         limit++;    //길이보다 크거나 같아지면 초기화를 시켜주기 위해 설정.
         count++;    //현재 함수내에서 몇 번 재생되었는지 알기 위해.
         
         p_List[user.GetPlayListNum()-1].GetNextItem(music);  //플레이 리스트에 있는 데이터에 접근
         num = music.GetNumPlay() + 1;
         music.SetNumPlay(num);
         p_List[user.GetPlayListNum()-1].Replace(music);
         
         qdata.SetPrimary(music.GetPrimary());
         
         m_List.Retrieve_Binary(qdata);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
         //마스터리스트에 있는 정보로 가져옴.
         qdata.DisplayRecordOnScreen();
         cout<<"\t ======= Play >> Any Number - Stop >> 0 ======"<<endl;
         cout<<"\t -----> ";
         cin>>num;
         
         if(limit >= p_List[user.GetPlayListNum()-1].GetLength()){
             p_List[user.GetPlayListNum()-1].ResetList();
             limit = 0;
         }
         if(num == 0){
             cout<<"\n\t [Total Play Times] : "<<count<<endl;
             cout<<"\n\t=============== Stop ==============="<<endl;
             break;
         }
       }
    }
     else
         cout<<"\t >> Please, Add Song to Play List."<<endl;
 }
 
void Application::PlayIOAddSelect(UserType& user){
     ItemType data;
     PlayItem music;
     int num = 0;
     int count = 0;
     
     data.SetPrimaryFromKB();    //ID입력
     music.SetPrimary(data.GetPrimary());    //music에다가 초기화.
     if(p_List[user.GetPlayListNum()-1].Search(music)){      //해당 ID를 가진 데이터가 있는지 조회.
         cout<<"\n\t============= Playing ============="<<endl;
     
         while(1){
             count++;
     
             num = music.GetNumPlay() + 1;
             music.SetNumPlay(num);
             p_List[user.GetPlayListNum()-1].Replace(music);
             
             data.SetPrimary(music.GetPrimary());
             
             m_List.Retrieve_Binary(data);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
             //마스터리스트에 있는 정보로 가져옴.
             data.DisplayRecordOnScreen();
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
     else
         cout<<"\t >> Please, Add Song to Play List."<<endl;
}
void Application::PlayIOFreq(UserType& user){
     ItemType data;
     PlayItem music;
 
     int length = p_List[user.GetPlayListNum()-1].GetLength();
     //각 재생횟수 끼리 비교해서.. 가장 많은 횟수부터 내림차순으로..
     PlayItem *max = new PlayItem[length];  //재생횟수가 많은 것부터 내림차순으로 max 배열에 삽입.
     PlayItem *temp = new PlayItem[length];
     //max라는 동적배열에다가 집어넣고 대소비교할 예정.
    
     p_List[user.GetPlayListNum()-1].ResetList();   //초기화
 
     for(int i = 0; i<length;i++){
         p_List[user.GetPlayListNum()-1].GetNextItem(music);//첫번째 데이터를 가져옴.
         max[i] = music;
     }   //일단 다 받음. 다 받고 내림차순하는게 더 쉬울듯..
    
     int temp1, i;
 
     for(i=0; i<length-1; i++){
         temp1 = i;
         for(int j = i+1; j<length; j++){ //i=0 -> j=1,2 길이가 3이라 가정하면..
             if(max[j].GetNumPlay() > max[temp1].GetNumPlay())
                 temp1 = j;
         }
         temp[i] = max[i];
         max[i] = max[temp1];
         max[temp1] = temp[i];
     }
    cout << "\n\t* Current Play list *" << endl;
    cout << "\t________________________________________________________________________" << endl;
    cout << "\t|      Music      |    Artist    |  Primary Key  | Play | Like | score |" << endl;
    cout << "\t------------------------------------------------------------------------" << endl;
    for(int i = 0; i < length; i++){
        p_List[user.GetPlayListNum()-1].GetNextItem(music);
        music.DisplayAllPLOnScreen();
    }
    
     int num = 0;
     int count = 0;
     int elem = 0;
     if(!p_List[user.GetPlayListNum()-1].IsEmpty()){
         cout<<"\n\t============= Playing ============="<<endl;
 
         while(1){
             count++;
 
             num = max[elem%length].GetNumPlay() + 1;
             max[elem%length].SetNumPlay(num);
             p_List[user.GetPlayListNum()-1].Replace(max[elem%length]);
 
             data.SetPrimary(max[elem%length].GetPrimary());
 
             m_List.Retrieve_Binary(data);
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
 
     delete []max;
     delete []temp;
 
}

void Application::ClicktheLike(UserType& user){
     ItemType data;
     PlayItem music;
     int num = 0;
     
     cout<<"\t What is your favorite? "<<endl;
     data.SetPrimaryFromKB();    //ID입력
     music.SetPrimary(data.GetPrimary());    //music에다가 초기화.
     
     if(p_List[user.GetPlayListNum()-1].Search(music)){
         num = music.GetLike()+1;
         music.SetLike(num);
         p_List[user.GetPlayListNum()-1].Replace(music);
 
     }
     else
         cout<<"\t NOT EXIST IN PLAYLIST. "<<endl;
}

void Application::PlayLikeMusic(UserType& user){
    ItemType qdata;
    PlayItem music;
 
 
    cout<<"\n\t============= Playing ============="<<endl;
    int count = 0;    // 특정시점에서의 재생횟수.
 
    cout << "\n\t* Current Like list *" << endl;
    PrintLikeList(user);
    
    cout<<"\n\t================================================================"<<endl;
    p_List[user.GetPlayListNum()-1].ResetList();
 
    int num = 0;
    int limit = 0;
    if(!p_List[user.GetPlayListNum()-1].IsEmpty()){
        while(1){
            limit++;    //길이보다 크거나 같아지면 초기화를 시켜주기 위해 설정.
            count++;    //현재 함수내에서 몇 번 재생되었는지 알기 위해.
 
            p_List[user.GetPlayListNum()-1].GetNextItem(music);  //플레이 리스트에 있는 데이터에 접근
            if(music.GetLike()){
                num = music.GetNumPlay() + 1;
                music.SetNumPlay(num);
                p_List[user.GetPlayListNum()-1].Replace(music);
                qdata.SetPrimary(music.GetPrimary());
 
                m_List.Retrieve_Binary(qdata);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
                //마스터리스트에 있는 정보로 가져옴.
                qdata.DisplayRecordOnScreen();
                cout<<"\t ======= Play >> Any Number - Stop >> 0 ======"<<endl;
                cout<<"\t -----> ";
                cin>>num;
            }
            if(limit >= p_List[user.GetPlayListNum()-1].GetLength()){
                p_List[user.GetPlayListNum()-1].ResetList();
                limit = 0;
            }
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t=============== Stop ==============="<<endl;
                break;
            }
        }
    }
    else
        cout<<"\t >> Please, Add Song to Play List."<<endl;
}
 

void Application::PrintPlayRank(UserType& user){
    ItemType data;
    PlayItem music;
    int length = p_List[user.GetPlayListNum()-1].GetLength();
    PlayItem *max_time = new PlayItem[length]; //평점에 대한 동적배열 할당.
    PlayItem *max_like = new PlayItem[length]; //좋아요에 대한 동적배열 할당.
    
    PlayItem *temp_t = new PlayItem[length];   //max라는 동적배열에다가 집어넣고 대소비교할 예정.
    PlayItem *temp_l = new PlayItem[length];
    
    p_List[user.GetPlayListNum()-1].ResetList();    //playlist 초기화
 
    for(int i = 0; i<length;i++){
        p_List[user.GetPlayListNum()-1].GetNextItem(music);//첫번째 데이터를 가져옴.
         max_time[i] = music;
         max_like[i] = music;
    }
    /*
     삽입시간배열과 좋아요배열에 PlayList에 있는 모든 객체의 정보를 담습니다.
     */
    int temp1, i;

    for(i=0; i<length-1; i++){
        temp1 = i;
        for(int j = i+1; j<length; j++){ //i=0 -> j=1,2 길이가 3이라가정하면..
            
            if(max_time[j].GetScore() > max_time[temp1].GetScore())
                temp1 = j;
        }
        temp_t[i] = max_time[i];
        max_time[i] = max_time[temp1];
        max_time[temp1] = temp_t[i];
    }
    /*
     각 곡에 대해서 평점순으로 내림차순하여 정렬하였습니다.
     여기서 평점은 단순히 (재생횟수x'좋아요'의 수) 로 설정하였습니다.
     */
    
    for(i=0; i<length-1; i++){
        temp1 = i;
        for(int j = i+1; j<length; j++){ //i=0 -> j=1,2 길이가 3이라가정하면..
            if(max_like[j].GetLike() > max_like[temp1].GetLike())
                temp1 = j;
        }
        temp_l[i] = max_like[i];
        max_like[i] = max_like[temp1];
        max_like[temp1] = temp_l[i];
    }
    /*
     각 곡에 대해서 '좋아요'순으로 내림차순하여 정렬하였습니다.
     */
    
    cout<<"\n\t\t***** Ranking ***** "<<endl;
    cout<<"\t\t    1. 평점순  "<<endl;
    cout<<"\t\t    2. '좋아요'순 "<<endl;
    cout<<"\t\t******************* "<<endl;
    cout<<"\t\t >> ";
    int click;
    cin>>click;
 
    if(click == 1){
        cout << "\n\t* Current Play Rank *" << endl;
        for(int i=0; i<length; i++){
            cout<<'\t'<<"["<<i+1<<"] "<<endl;
            max_time[i].DisplayPLRecordOnScreen();
        }
    }
    else if(click == 2){
        cout << "\n\t* Current Like Rank *" << endl;
        
        for(int i=0; i<length; i++){
            cout<<'\t'<<"["<<i+1<<"] "<<endl;
            max_like[i].DisplayPLRecordOnScreen();
        }
    }
    else
        cout<<"\t >>Please Click number 1 or 2"<<endl;
    /*
     단, 동점의 경우는 고려하지 않았습니다.
     */
    delete[] max_time;
    delete[] max_like;
    delete[] temp_t;
    delete[] temp_l;
}

void Application::PrintPlayList(UserType user){
    ItemType data;
    PlayItem music;
    cout << "\n\t* Play list *" << endl;
    
    int length = p_List[user.GetPlayListNum()-1].GetLength();
    p_List[user.GetPlayListNum()-1].ResetList();
    
    
    cout << "\n\t* Current Play list *" << endl;
    cout << "\t________________________________________________________________________" << endl;
    cout << "\t|      Music      |    Artist    |  Primary Key  | Play | Like | score |" << endl;
    cout << "\t------------------------------------------------------------------------" << endl;
    
    for(int i = 0; i < length; i++){
        p_List[user.GetPlayListNum()-1].GetNextItem(music);
        music.DisplayAllPLOnScreen();
    }
    
}

void Application::PrintLikeList(UserType& user){
    ItemType data;
    PlayItem music;
    int length = p_List[user.GetPlayListNum()-1].GetLength();
    p_List[user.GetPlayListNum()-1].ResetList();
    
    cout << "\n\t* Like list *" << endl;
    cout << "\t________________________________________________________________________" << endl;
    cout << "\t|      Music      |    Artist    |  Primary Key  | Play | Like | score |" << endl;
    cout << "\t------------------------------------------------------------------------" << endl;
    for(int i = 0; i < length; i++){
        p_List[user.GetPlayListNum()-1].GetNextItem(music);
        if(music.GetLike())
            music.DisplayAllPLOnScreen();
    }
}

int Application::SearchinPL_BinaryS(UserType& user){
    ItemType data;
    PlayItem music;
 
    if(p_List[user.GetPlayListNum()-1].IsEmpty()){
        cout<<"\t PlayList is empty."<<endl;
        return 0;
    }
 
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
 
    if(p_List[user.GetPlayListNum()-1].Search(music)){
        cout<<endl;
        cout<<"=========== Music FOUND in Play List========="<<endl;
        music.DisplayPLRecordOnScreen();
        cout<<"============================================="<<endl;
        return 1;
    }
    else{
        cout<<endl;
        cout<<"======= Music Not Found in Play List ======="<<endl;
    }
 return 1;
}

/*
 PlayItem에 ID, numPlay, inTime만 들어가서 Replace의 필요성이 없다고 생각하여 삭제하였습니다.
 (ID값은 바뀌면 안되고 numPlay와 inTime은 계속 바뀌는 값이기 때문)
 */

/*
 ----------------------------------- Singer & Song List ----------------------------------
 */
int Application::AddSinger(){
    SingerType singer;
    ItemType data;
    SimpleItemType songinput;
    
    cout<<"\t ====== Enter the ARTIST ======"<<endl<<endl;
    songinput.SetIdFromKB(); //Primary Key 입력
    singer.SetSonglist(songinput);  //SingerType에 Primary Key 갱신
    
    if(s_List.Get(singer)){ //Primary Key를 이용하여 탐색.
        cout<<"\n\t  >>ID already exists, Please enter again."<<endl;
        return 0;
    }
    else{
        cout<<"\n\t  >>ID is available. ENTER THE SINGER."<<endl<<endl;
        singer.SetSingerFromKB();      //singer list에 대해 정보를 키보드로 입력받음.
        songinput.SetSimpleFromKB();      //song list에 대해 정보를 키보드로 입력받음.
        
        data.SetSingerRecord(songinput.GetMusic(), singer.GetName(), songinput.GetId(), singer.GetGender(), singer.GetAge());
        //입력받은 정보를 마스터리스트 객체에 갱신시켜놓음. 새로운 정보일 경우 추가시키기 위해.
        singer.SetSonglist(songinput);
        //singer list엔 현재 songlist의 내용이 갱신되지 않은 상태이므로 갱신시켜줌.
        m_List.Add(data);
        s_List.Add(singer);
        simple_List.Add(songinput);
        cout<<"\n\t  >> SAVE THE SINGER."<<endl;
    }
    
    return 1;
}

int Application::AddSong(){
    SingerType singer;
    SimpleItemType songinput;
    ItemType emptydata, inputdata;
    
    int length = m_List.GetLength();
    
    cout<<"\t ====== Enter the ARTIST ======"<<endl<<endl;
    
    singer.SetSingerFromKB();       //singer list에 대해 정보를 키보드로 입력받음.
    songinput.SetSimpleFromKB();      //song list에 대해 정보를 키보드로 입력받음.
    
    inputdata.SetSingerRecord(songinput.GetMusic(), singer.GetName(), songinput.GetId(), singer.GetGender(), singer.GetAge());
    //새로운 정보일 경우 추가시키기 위해 입력받은 정보를 마스터리스트 객체에 갱신시켜놓음.
    singer.SetSonglist(songinput);
    //singer list에 있는 songlist의 현재 내용이 갱신되지 않은 상태이므로 갱신시켜줌.
    
    
    m_List.ResetList(); //배열 초기화
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(emptydata);  //빈 객체를 넣어 현재 Master List에 있는 값들 중 같은 가수이름을 가진 데이터가 있는지 탐색.
        if(emptydata.GetArtist().find(singer.GetName()) != string::npos){
            cout<<"========= The Artist is already exist. ========="<<endl;
            return 0;
        }
    }
    
    if(s_List.Get(singer)){     //갱신받은 songlist의 id값으로 singer list 내에 해당하는 Primary Key가 있는지 확인.
        cout<<"\t ID already exists Please enter again."<<endl;
        return 0;
    }
    else{
        cout<<"\n\t  >>NOT EXIST. SAVE THE SINGER."<<endl;
        
        m_List.Add(inputdata);
        s_List.Add(singer);
        simple_List.Add(songinput);
        // 새로운 정보일 경우 세 리스트에 모두 추가.
    }
    return 1;
    
}
void Application::​​​DisplayAllSingerList(){
    SingerType singer;
    cout<<"\n\t* Current Singer list *" << endl;
    
    s_List.printInOrder(cout);
}
void Application::​​​DisplayAllSongList(){
    SimpleItemType song;
    cout<<"\n\t* Current Song list *" << endl;
    
    simple_List.printInOrder(cout);
}
