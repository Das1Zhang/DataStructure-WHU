#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(char d)
    {
        data = d;
        lchild = rchild = nullptr;
    }
};

class BTree
{
    BTNode *r;

public:
    BTree()
    {
        r = nullptr;
    }

    void CreateBTree(string str);
    void DispBTree();
    void DispBTree1(BTNode *b);

    int NodeCount11(BTNode *b); // 先序遍历统计节点个数，根->左子树->右子树
    int NodeCount1();
    int NodeCount41(BTNode *b); // 递归算法
    int NodeCount4();

    void DispLeaf11(BTNode *b); // 先序输出叶子节点
    void DispLeaf1();

    void Swap11(BTNode *&b); // 先序交换二叉树
    void Swap1(BTree &bt);
    // ** 注意二叉树不可以使用中序交换，会产生错误结果 **

    int Level1(BTNode *b, char x, int h); // 查找 x 所在的层次
    int Level(BTree &bt, char x);

    void KCount1(BTNode *b, int h, int k, int &cnt); // 统计 第 k 层 的节点个数
    int KCount(BTree &bt, int k);

    // Ancestor 找到目标结点的所有祖先节点
    //  递归算法，先嵌套到目标值的双亲，再回滚，最后把数组进行逆序
    bool Ancestor11(BTNode *b, char x, vector<char> &res);
    void Ancestor1(BTree &bt, char x, vector<char> &res);

    // 先序遍历，使用非引用数组，每次调用函数都会在路径上添加上当前节点，如果找到，那么该路径直接给到res作为答案
    bool Ancestor21(BTNode *b, char x, vector<char> path, vector<char> &res);
    void Ancestor2(BTree &bt, char x, vector<char> &res);

    // 改进Ancestor31,如果左子树找到了，那么后续就不需要再查找了
    bool Ancestor31(BTNode *b, char x, vector<char> path, vector<char> &res);
    void Ancestor3(BTree &bt, char x, vector<char> &res);

    // 层次遍历
    void LevelOrder(BTree& bt);

    // 使用层次遍历来统计第k层的节点个数
    struct QNode
    {
        int lev;
        BTNode* node;
        QNode(int l,BTNode* p)
        {
            lev = l;
            node = p;
        }
    };
    int KCount1(BTree& bt,int k);   //每次加入孩子节点时，增加高度
    int KCount2(BTree& bt, int k);  //通过记录下一层的最后一个节点，来实现对高度的更新
    int KCount3(BTree& bt, int k);  // 一层一层的遍历，因为我们不需要寻找到某个特定节点
};