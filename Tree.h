#include<string.h>
#include<iostream>

using namespace std;

struct BTNode{
    char data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode(): lchild(nullptr), rchild(nullptr){}
    BTNode(char d){
        data = d;
        lchild = rchild = nullptr;
    }
};

class BTree{
    BTNode* r;
public:
    BTree(){
        r = nullptr;
    }

    void CreateBTree(string str);
    void DispBTree();
    void DispBTree1(BTNode* b);
};