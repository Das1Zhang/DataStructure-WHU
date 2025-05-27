#include "Tree.h"
#include <stack>
using namespace std;

void BTree::CreateBTree(string str)
{
    stack<BTNode *> st;
    BTNode *p;
    bool flag;
    int i = 0;
    while (i < str.length())
    {
        switch (str[i])
        {
        case '(':
            st.push(p);
            flag = true;
            break;
        case ')':
            st.pop();
            break;
        case ',':
            flag = false;
            break;
        default:
            p = new BTNode(str[i]);
            if (r == NULL)
            {
                r = p;
            }
            else
            {
                if (flag && !st.empty())
                    st.top()->lchild = p;
                else if (!st.empty())
                    st.top()->rchild = p;
            }
            break;
        }
        i++;
    }
}

void BTree::DispBTree1(BTNode *b)
{
    if (b != NULL)
    {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL)
        {
            cout << "(";
            DispBTree1(b->lchild);
            if (b->rchild != nullptr)
                cout << ",";
            DispBTree1(b->rchild);
            cout << ")";
        }
    }
}

void BTree::DispBTree()
{
    DispBTree1(r);
}

int BTree::NodeCount11(BTNode *b)
{
    int m, n, k;
    k = 1;
    m = NodeCount11(b->lchild);
    n = NodeCount11(b->rchild);
    return m + n + k;
}

int BTree::NodeCount1()
{
    NodeCount11(r);
}

int BTree::NodeCount41(BTNode *b)
{
    if (b == nullptr)
        return 0;
    else
        return NodeCount41(b->lchild) + NodeCount41(b->rchild) + 1;
}

int BTree::NodeCount4()
{
    NodeCount41(r);
}

void BTree::DispLeaf11(BTNode *b)
{
    if (b != nullptr)
    {
        if (b->lchild == nullptr && b->rchild == nullptr)
            cout << b->data << " ";
        DispLeaf11(b->lchild);
        DispLeaf11(b->rchild);
    }
}

void BTree::DispLeaf1()
{
    DispLeaf11(r);
}

void BTree::Swap11(BTNode *&b)
{
    if (b != nullptr)
    {
        swap(b->lchild, b->rchild);
        Swap11(b->lchild);
        Swap11(b->rchild);
    }
}

void BTree::Swap1(BTree &bt)
{
    Swap11(bt.r);
}

int BTree::Level1(BTNode *b, char x, int h)
{
    if (b == nullptr)
        return 0;
    else if (b->data == x)
        return h;
    else
    {
        int l = Level1(b->lchild, x, h + 1); // 在左子树中查找
        if (l != 0)
            return l;
        else
            return Level1(b->rchild, x, h + 1); // 在右子树中查找
    }
}

int BTree::Level(BTree &bt, char x)
{
    Level1(bt.r, x, 1);
}

void BTree::KCount1(BTNode *b, int h, int k, int &cnt)
{
    if (b == nullptr)
        return;
    if (h == k)
        cnt++;
    if (h < k)
    {
        KCount1(b->lchild, h + 1, k, cnt);
        KCount1(b->rchild, h + 1, k, cnt);
    }
}

int BTree::KCount(BTree &bt, int k)
{
    int cnt = 0;
    KCount1(bt.r, 1, k, cnt);
    return cnt;
}

bool BTree::Ancestor11(BTNode *b, char x, vector<char> &res)
{
    if (b == NULL)
        return false;
    if (b->lchild != nullptr && b->lchild->data == x)
    {
        res.push_back(b->data);
        return true;
    }
    if (b->rchild != nullptr && b->rchild->data == x)
    {
        res.push_back(b->data);
        return true;
    }
    if (Ancestor11(b->lchild, x, res) || Ancestor11(b->rchild, x, res))
    {
        res.push_back(b->data);
        return true;
    }
    return false;
}

void BTree::Ancestor1(BTree &bt, char x, vector<char> &res)
{
    Ancestor11(bt.r, x, res);
    reverse(res.begin(), res.end());
}

bool BTree::Ancestor21(BTNode *b, char x, vector<char> path, vector<char> &res)
{
    if (b == nullptr)
        return;
    path.push_back(b->data);
    if (b->data == x)
    {
        path.pop_back();
        res = path;
        return;
    }
    Ancestor21(b->lchild, x, path, res);
    Ancestor21(b->rchild, x, path, res);
}

void BTree::Ancestor2(BTree &bt, char x, vector<char> &res)
{
    vector<char> path;
    Ancestor21(bt.r, x, path, res);
}

bool BTree::Ancestor31(BTNode *b, char x, vector<char> path, vector<char> &res)
{
    if (b == nullptr)
        return false;
    path.push_back(b->data);
    if (b->data == x)
    {
        path.pop_back();
        res = path;
        return true;
    }
    if (Ancestor31(b->lchild, x, path, res))
        return true;
    else
        return Ancestor31(b->rchild, x, path, res);
}

void BTree::Ancestor3(BTree &bt, char x, vector<char> &res)
{
    vector<char> path;
    Ancestor31(bt.r, x, path, res);
}

void BTree::LevelOrder(BTree &bt)
{
    BTNode *p;
    queue<BTNode *> qu;
    qu.push(bt.r);
    while (!qu.empty())
    {
        p = qu.front();
        qu.pop();
        cout << p->data;
        if (p->lchild != nullptr)
            qu.push(p->lchild);
        if (p->rchild != nullptr)
            qu.push(p->rchild);
    }
}

int BTree::KCount1(BTree &bt, int k)
{
    int cnt = 0;
    queue<QNode> qu;
    qu.push(QNode(1, bt.r));
    while (!qu.empty())
    {
        QNode p = qu.front();
        qu.pop();
        if (p.lev > k)
            return cnt;
        if (p.lev == k)
            cnt++;
        else
        {
            if (p.node->lchild != NULL)
                qu.push(QNode(p.lev + 1, p.node->lchild));
            if (p.node->rchild != nullptr)
                qu.push(QNode(p.lev + 1, p.node->rchild));
        }
    }
}

int BTree::KCount2(BTree &bt, int k)
{
    int cnt = 0;
    queue<BTNode *> qu;
    int curl = 1;
    BTNode *last = bt.r, *p, *q;
    qu.push(bt.r);
    while (!qu.empty())
    {
        if (curl > k)
            return cnt;
        p = qu.front();
        qu.pop();
        if (curl == k)
            cnt++;
        if (p->lchild != nullptr)
        {
            q = p->lchild;
            qu.push(q);
        }
        if (p->rchild != nullptr)
        {
            q = p->rchild;
            qu.push(q);
        }
        if (p == last)
        {
            last = q;
            curl++;
        }
    }
}

int BTree::KCount3(BTree &bt, int k)
{
    if (k < 1)
        return 0;
    queue<BTNode *> qu;
    int curl = 1;
    qu.push(bt.r);
    while (!qu.empty())
    {
        if (curl == k)
            return qu.size();
        int n = qu.size();
        for (int i = 0; i < n; i++)
        {
            BTNode *p = qu.front();
            qu.pop();
            if (p->lchild != nullptr)
                qu.push(p->lchild);
            if (p->rchild != nullptr)
                qu.push(p->rchild);
        }
        curl++;
    }
    return 0;
}

BTNode *BTree::CreateBTree11(vector<char> pres, int i, vector<char> ins, int j, int n)
{
    if (n <= 0)
        return nullptr;
    char d = pres[i];
    BTNode *b = new BTNode(d);
    int p = j;
    while (ins[p] != d)
        p++;
    int k = p - j;
    b->lchild = CreateBTree11(pres, i + 1, ins, j, k);
    b->rchild = CreateBTree11(pres, i + k + 1, ins, p + 1, n - k - 1);
    return b;
}

void BTree::CreateBTree1(BTree &bt, vector<char> pres, vector<char> ins)
{
    int n = pres.size();
    bt.r = CreateBTree11(pres, 0, ins, 0, n);
}

BTNode *BTree::CreateBTree21(vector<char> posts, int i, vector<char> ins, int j, int n)
{
    if (n <= 0)
        return nullptr;
    char d = posts[i + n - 1];
    BTNode *b = new BTNode(d);
    int p = j;
    while (ins[p] != d)
        p++;
    int k = p - j;
    b->lchild = CreateBTree21(posts, i, ins, j, k);
    b->rchild = CreateBTree21(posts, i + k, ins, j, n - k - 1);
}

void BTree::CreateBTree2(BTree &bt, vector<char> posts, vector<char> ins)
{
    int n = posts.size();
    bt.r = CreateBTree21(posts, 0, ins, 0, n);
}

string BTree::PreOrderSeq1(BTNode *b)
{
    if (b == NULL)
        return "#";
    string s(1, b->data);
    s += PreOrderSeq1(b->lchild);
    s += PreOrderSeq1(b->rchild);
    return s;
}

string BTree::PreOrderSeq(BTree &bt)
{
    return PreOrderSeq1(bt.r);
}

BTNode *BTree::CreateBTree31(string s, int &i)
{
    if (i >= s.length())
        return nullptr;
    char d = s[i];
    i++;
    if (d == '#')
        return nullptr;
    BTNode *b = new BTNode(d);
    b->lchild = CreateBTree31(s, i);
    b->rchild = CreateBTree31(s, i);
    return b;
}

void BTree::CreateBTree3(BTree &bt, string s)
{
    int i = 0;
    bt.r = CreateBTree31(s, i);
}
