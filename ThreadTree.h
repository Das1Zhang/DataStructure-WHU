#include <vector>
#include <queue>
#include <string>
using namespace std;

struct BthNode
{
    char data;
    BthNode *lchild, *rchild;
    int ltag, rtag;
    BthNode() {}
    BthNode(char d)
    {
        data = d;
        ltag = rtag = 0;
        lchild = rchild = nullptr;
    }
};

// 中序线索二叉树
class ThreadTree
{
public:
    BthNode *r;
    BthNode *root;
    BthNode *pre;

public:
    ThreadTree()
    {
        r = nullptr;
        root = nullptr;
    }

    ~ThreadTree()
    {
        if (r != nullptr)
            DestroyBTree1(r);
        if (root != nullptr)
            delete root;
    }

    void DestroyBTree1(BthNode *b);
    void CreateBTree(string str);
    void DispBTree();
    void CreateThread();
    void ThInOrder();
    void Thread(BthNode *&p);
};