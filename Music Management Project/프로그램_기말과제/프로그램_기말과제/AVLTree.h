#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

template<typename T>
class Node;
template<typename T>
class AVLTree;

template<typename T>
class Node {
    friend class AVLTree<T>;
private:
    T data;
    Node<T>* parent;    //부모 노드.
    Node<T>* left;      //좌측 노드.
    Node<T>* right;     //우측 노드.
    int balanceFactor;  //높이의 차이를 알려주는 변수.
public:
    Node(T d = T(), Node<T>* p = nullptr, Node<T>* l = nullptr, Node<T>* r = nullptr);
    // Node의 생성자.
};

template<typename T>
Node<T>::Node(T d, Node<T>* p, Node<T>* l, Node<T>* r){
    data = d;
    parent = p;
    left = l;
    right = r;
    balanceFactor = 0;
}

template<typename T>
class AVLTree {
private:
    Node<T>* root;
    //루트 노드.
    int size;
    //트리 크기에 대한 변수.
    int setBalance(Node<T>* node);
    int getHeight(Node<T>* node) const;
    //트리의 높이를 반환.
    void rebalance(Node<T>* node);
    void rotate(Node<T>* parent);
    //해당 노드가 LRR, LLR, RLR, RRR 중 어느방향으로 rotate할 지 알려준다.
    void LLR(Node<T>* parent, Node<T>* node, Node<T>* child);
    // LL rotation에서 부모노드는 좋지 않은 밸런스를 가진 노드이다.
    void LRR(Node<T>* parent, Node<T>* node, Node<T>* child);
    // LR rotation에서 부모노드는 좋지 않은 밸런스를 가진 노드이다.
    void RRR(Node<T>* parent, Node<T>* node, Node<T>* child);
    // RR rotation에서 부모노드는 좋지 않은 밸런스를 가진 노드이다.
    void RLR(Node<T>* parent, Node<T>* node, Node<T>* child);
    // RL rotation에서 부모노드는 좋지 않은 밸런스를 가진 노드이다.
    void printInOrder(Node<T>* node,ostream &out) const;
    // in-order로 출력.
    void printPostOrder(Node<T>* node,ostream &out) const;
    // post-order로 출력.
    void printPreOrder(Node<T>* node,ostream &out) const;
    // pre-order로 출력.
    void printLevelOrder(Node<T>* node,ostream &out) const;
    // level-order로 출력.
    void ReplaceItem(Node<T> *root, T& item, bool& found);
    //데이터를 치환해주는 함수.
    void RetrieveItem(Node<T> *root, T& data, bool& found);
    //데이터를 검색해주는 함수.
    
    Node<T>* copy(Node<T>* rhs) const;
    //노드를 복사할 때 쓰는 함수.
    void remove(Node<T>* node);
    //데이터를 삭제할 때 쓰는 함수.
    
public:
    AVLTree(): root(nullptr), size(0){}
    // AVLTree의 디폴트 생성자.
    AVLTree(const AVLTree<T>& rhs): root(nullptr) { *this = rhs; }
    // AVLTree의 생성자.
    ~AVLTree();
    // AVLTree의 소멸자.
    AVLTree<T>& operator =(const AVLTree<T>& rhs);
    // AVLTree의 assign operator.
    
    bool contains(const T& data) const;
    bool IsEmpty() const;
    //트리가 비어있는지 확인하는 함수.
    bool IsFull();
    //트리가 가득 차있는지 확인하는 함수.
    void MakeEmpty();
    //트리를 비우는 함수.
    void Add(T data);
    //트리에 값을 추가하는 함수.
    Node<T>* Get(const T& data) const;
    //트리에서 노드를 찾는 함수.
    int Retrieve(T& data, bool& found);
    //트리에서 값을 찾는 함수.
    int Replace(T& item, bool& found);
    //트리에 있는 값을 치환하는 함수.
    int Delete(const T& data) { remove(Get(data)); return 1;}
    //트리에서 값을 삭제하는 함수.
    void printInOrder(ostream &out) const;
    // in-Order로 출력.
    void printPostOrder(ostream &out) const;
    // post-Order로 출력.
    void printPreOrder(ostream &out) const;
    // pre-Order로 출력.
    void printLevelOrder() const { printLevelOrder(root,cout); }
    // level-Order로 출력.
    int getHeight() const { return getHeight(root); }
    // 트리의 높이를 리턴하는 함수.
    int GetLength() const { return size; }
    //트리의 전체 길이를 리턴하는 함수.
    
};

/*
 ----------------------- private에 있는 함수 정의. -----------------------
 */
template<typename T>
int AVLTree<T>::setBalance(Node<T>* node){
    if(node == nullptr)
        return 0;
    int leftHeight = getHeight(node->left); //왼쪽 서브트리에 대한 높이
    int rightHeight = getHeight(node->right); //오른쪽 서브트리에 대한 높이
    node->balanceFactor = rightHeight - leftHeight;  //오른쪽 서브트리와 왼쪽 서브트리의 차 = balance Factor
    return node->balanceFactor;
}

template<typename T>
int AVLTree<T>::getHeight(Node<T>* node) const{
    if (node == nullptr)
        return -1;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

template<typename T>
void AVLTree<T>::rebalance(Node<T>* node){
    while (node != nullptr){
        setBalance(node);
        if (node->balanceFactor >= 2 || node->balanceFactor <= -2)
            rotate(node);
        node = node->parent;
    }
}

template<typename T>
void AVLTree<T>::rotate(Node<T>* node){
    Node<T>* child;
    //node가 크면 왼쪽으로 갈때..
    if (node->balanceFactor < -1){
        child = node->left;
        setBalance(child);
        //child가 크면 오른쪽으로 간다.
        if (child->balanceFactor == 1)
            LRR(node, child, child->right);
        //child가 크면 왼쪽으로 간다.
        else
            LLR(node, child, child->left);
    }
    //node가 크면 오른쪽으로 갈때..
    else {
        child = node->right;
        setBalance(child);
        //child가 크면 왼쪽으로 간다.
        if (child->balanceFactor == -1)
            RLR(node, child, child->left);
        //child가 크면 오른쪽으로 간다.
        else
            RRR(node, child, child->right);
    }
}

template<typename T>
void AVLTree<T>::LLR(Node<T>* parent, Node<T>* node, Node<T>* child){
    Node<T>* grandParent = parent->parent;
    node->parent = grandParent;
    Node<T>* nodeRight = node->right;
    if (nodeRight != nullptr) nodeRight->parent = parent;
    node->right = parent;
    parent->parent = node;
    parent->left = nodeRight;
    if (grandParent == nullptr)
        root = node;
    else if (grandParent->left == parent)
        grandParent->left = node;
    else
        grandParent->right = node;
}

//(>= 1 || <= -1)
template<typename T>
void AVLTree<T>::LRR(Node<T>* parent, Node<T>* node, Node<T>* child){
    RRR(node, child, child->right);
    LLR(parent, child, node);
}

template<typename T>
void AVLTree<T>::RRR(Node<T>* parent, Node<T>* node, Node<T>* child){
    Node<T>* grandParent = parent->parent;
    node->parent = grandParent;
    Node<T>* nodeLeft = node->left;
    if (nodeLeft != nullptr) nodeLeft->parent = parent;
    node->left = parent;
    parent->parent = node;
    parent->right = nodeLeft;
    if (grandParent == nullptr)
        root = node;
    else if (grandParent->left == parent)
        grandParent->left = node;
    else
        grandParent->right = node;
}

template<typename T>
void AVLTree<T>::RLR(Node<T>* parent, Node<T>* node, Node<T>* child){
    LLR(node, child, child->left);
    RRR(parent, child, node);
}

template<typename T>
void AVLTree<T>::printInOrder(Node<T>* node,ostream &out) const {
    if (node == nullptr)
        return;
    printInOrder(node->left, out);
    out<<node->data;
    printInOrder(node->right, out);
}

template<typename T>
void AVLTree<T>::printPostOrder(Node<T>* node,ostream &out) const {
    if (node == nullptr) return;
    printPostOrder(node->left,out);
    printPostOrder(node->right, out);
    out<<node->data;
}

template<typename T>
void AVLTree<T>::printPreOrder(Node<T>* node,ostream &out) const {
    if (node == nullptr) return;
    out<<node->data;
    printPreOrder(node->left,out);
    printPreOrder(node->right),out;
}

template<typename T>
void AVLTree<T>::printLevelOrder(Node<T>* node,ostream &out) const {
    if (node == nullptr) return;
    list<Node<T>*> nodeQueue;
    list<int> levelQueue;
    nodeQueue.push_back(node);
    levelQueue.push_back(0);
    while (!nodeQueue.empty()){
        Node<T>* currNode = nodeQueue.front();
        int currLevel = levelQueue.front();
        nodeQueue.pop_front();
        levelQueue.pop_front();
        if (currNode->left != nullptr){
            nodeQueue.push_back(currNode->left);
            levelQueue.push_back(currLevel + 1);
        }
        if (currNode->right != nullptr){
            nodeQueue.push_back(currNode->right);
            levelQueue.push_back(currLevel + 1);
        }
        for (int i = 0; i < currLevel; i++)
            cout << '\t';
        out<<currNode->data;
    }
}

template<typename T>
Node<T>* AVLTree<T>::copy(Node<T>* rhs) const {
    if (rhs == nullptr)
        return nullptr;
    Node<T>* ret = new Node<T>(rhs->data, nullptr, copy(rhs->left), copy(rhs->right));
    
    if (ret->left != nullptr)
        ret->left->parent = ret;
    if (ret->right != nullptr)
        ret->right->parent = ret;
    return ret;
}

template<typename T>
void AVLTree<T>::remove(Node<T>* node){
    if (node == nullptr) return;
    if (root == nullptr) return;
    
    Node<T>* parent = node->parent;
    //리프노드를 제거한다.
    if (node->left == nullptr && node->right == nullptr){
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == node)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete node;
        rebalance(parent);
        size--;
    }
    // 오직 좌측 자식을 가지고 있는 노드를 제거한다.
    else if (node->right == nullptr){
        if (parent == nullptr){
            root = node->left;
            root->parent = nullptr;
        }
        else if (parent->left == node){
            parent->left = node->left;
            node->left->parent = parent;
        }
        else {
            parent->right = node->left;
            node->left->parent = parent;
        }
        delete node;
        rebalance(parent);
        size--;
    }
    // 오직 우측 자식을 가지고 있는 노드를 제거한다.
    else if (node->left == nullptr){
        if (parent == nullptr){
            root = node->right;
            root->parent = nullptr;
        }
        else if (parent->left == node){
            parent->left = node->right;
            node->right->parent = parent;
        }
        else {
            parent->right = node->right;
            node->right->parent = parent;
        }
        delete node;
        rebalance(parent);
        size--;
    }
    //두 자식을 가지고 있는 노드를 제거한다.
    //우측 자식노드의 좌측 가장 큰 자식노드를 바꾼다.
    //제거하기 위해 재귀함수 호출을 해준다.
    else {
        Node<T>* temp = node->right;
        while (temp->left != nullptr)
            temp = temp->left;
        node->data = temp->data;
        remove(temp);
    }
}


/*
 ----------------------- public에 있는 함수 정의. -----------------------
 */
template<typename T>
AVLTree<T>::~AVLTree(){
    MakeEmpty();
}

template<typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& rhs){
    if (this == &rhs) return *this;
    MakeEmpty();
    root = copy(rhs.root);
    size = rhs.size;
    return *this;
}

template<typename T>
bool AVLTree<T>::contains(const T& data) const {
    if (Get(data) == nullptr)
        return false;
    return true;
}
template<typename T>
bool AVLTree<T>::IsEmpty() const {
    return size == 0;
}
template<typename T>
bool AVLTree<T>::IsFull(){
    Node<T>* room;                    // 임시의 node를 만들고
    try{
        room = new Node<T>;        // 새 노드를 추가할 수 있는지 확인
        delete room;            // 임시로 만든 room 노드를 지움
        return false;            // isFull에 대한 false 리턴
    }
    catch(std::bad_alloc exception){        // 더 이상 아이템 추가를 할 수 없고 Full일 경우
        return true;                    // isFull에 대한 true 리턴
    }
}

template<typename T>
void AVLTree<T>::MakeEmpty(){
    while (root != nullptr)
        remove(root);
}

template<typename T>
void AVLTree<T>::Add(T data){
    if (root == nullptr){
        root = new Node<T>(data);
        return;
    }
    Node<T>* curr = root;
    Node<T>* prev = curr;
    while(curr != nullptr){
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else if (data > curr->data)
            curr = curr->right;
        else
            return;
    }
    size++;
    
    Node<T>* newNode = new Node<T>(data, prev);
    if (data < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;
    
    rebalance(newNode);
}

template<typename T>
Node<T>* AVLTree<T>::Get(const T& data) const {
    Node<T>* temp = root;
    while (temp != nullptr){
        if(temp->data == data){
            return temp;
        }
        if(temp->data < data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return nullptr;
}

template <class T>
void AVLTree<T>::printInOrder(ostream &out) const {
    printInOrder(root, cout);
    cout<<endl;
}

template <class T>
void AVLTree<T>::printPostOrder(ostream &out) const {
    printPostOrder(root, cout);
    cout<<endl;
}

template <class T>
void AVLTree<T>::printPreOrder(ostream &out) const {
    printPreOrder(root, cout);
    cout<<endl;
}

template <typename T>
int AVLTree<T>::Retrieve(T &data, bool &found){
    RetrieveItem(root, data, found);
    return 1;
}

template<typename T>
void AVLTree<T>::RetrieveItem(Node<T> *root, T& data, bool& found){
    if(root == NULL)
        found = false;
    else if(root->data > data){         //삭제와 같은 구조를 보이고 있음.
        RetrieveItem(root->left, data, found);
    }
    else if(root->data < data){
        RetrieveItem(root->right, data, found);
    }
    else{
        data = root->data;
        found = true;
    }
}

template<typename T>
int AVLTree<T>::Replace(T &item, bool &found){
    ReplaceItem(root, item, found);
    return 1;
}

template<typename T>
void AVLTree<T>::ReplaceItem(Node<T> *root, T &item, bool &found){
    if(root == NULL)
        found = false;
    else if(root->data > item){         //삭제와 같은 구조를 보이고 있음.
        ReplaceItem(root->left, item, found);
    }
    else if(root->data < item){
        ReplaceItem(root->right, item, found);
    }
    else{
        root->data = item;
        found = true;
    }
}
