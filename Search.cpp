#include "Search.h"

int BinSearch1(vector<int> &R, int k)
{
    int n = R.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (k == R[mid])
            return mid;
        if (k < R[mid])
            high = mid - 1;
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// ===========二叉排序树========
template <typename T1, typename T2>
struct BSTNode
{
    T1 key;
    T2 data;
    BSTNode *lchild;
    BSTNode *rchild;
    BSTNode(T1 k, T2 d)
    {
        key = k;
        data = d;
        lchild = rchild = nullptr;
    }
};

template <typename T1, typename T2>
class BSTClass
{
public:
    BSTNode<T1, T2> *r;
    BSTNode<T1, T2> *f;

    BSTClass()
    {
        r = nullptr;
        f = nullptr;
    }

    ~BSTClass()
    {
        DestroyBTree(r);
        r = nullptr;
    }

    void DestoryBTree(BSTNode<T1, T2> *b)
    {
    }

    void InsertBST(T1 k, T2 d)
    {
        r = _InsertBTree(r, k, d);
    }

    BSTNode<T1, T2> *_InsertBST(BSTNode<T1, T2> *p, T1 k, T2 d)
    {
        if (p == nullptr)
        {
            p = new BSTNode<T1, T2>(k, d);
        }
        else if (k < p->key)
        {
            p->lchild = _InsertBST(p->lchild, d);
        }
        else if (k > p->key)
        {
            p->rchild = _InsertBST(p->rchild, k, d);
        }
        else
        {
            p->data = d;
        }

        return p;
    }

    void CreateBST(vector<T1> &a, vector<T2> &b)
    {
        r = new BSTNode<T1, T2>(a[0], b[0]);
        for (int i = 1; i < a.size(); i++)
        {
            InsertBST(a[i], b[i])
        }
    }

    BSTNode<T1, T2> *SearchBST(T1 k)
    {
        return _SearchBST(r, k);
    }

    BSTNode<T1, T2> *_SearchBST(BSTNode<T1, T2> *p, T1 k)
    {
        if (p == NULL)
            return NULL;
        if (p->key == k)
            return p;
        if (k < p->key)
            return _SearchBST(p->lchild, k);
        else
        {
            return _SearchBST(p->rchild, k);
        }
    }
};

// ==========平衡二叉树==========
template <typename T1, typename T2>
struct AVLNode
{
    T1 key;
    T2 data;
    int ht;
    AVLNode *lchild, rchild;

    AVLNode(T1 k, T2 d)
    {
        key = k;
        data = d;
        ht = 1;
        lchild = rchild = nullptr;
    }
};

template <typename T1, typename T2>
class AVLTree
{
    AVLNode *r;

public:
    AVLTree() : r(nullptr) {}
    int getht(AVLNode *p)
    {
        if (p == nullptr)
            return 0;
        return p->ht;
    }

    AVLNode *right_rotate(AVLNode *a)
    {
        AVLNode *b = a->lchild;
        a->lchild = b->rchild;
        b->rchild = a;
        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;
        return b;
    }

    AVLNode *LL(AVLNode *a)
    {
        return right_rotate(a);
    }

    AVLNode *left_rotate(AVLNode *a)
    {
        AVLNode *b = a->rchild;
        a->rchild = b->lchild;
        b->lchild = a;
        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;
        return b;
    }

    AVLNode *RR(AVLNode *a)
    {
        return left_rotate(a);
    }

    AVLNode *LR(AVLNode *a)
    {
        AVLNode *b = a->lchild;
        a->lchild = left_rotate(b);
        return right_rotate(a);
    }

    AVLNode *RL(AVLNode *a)
    {
        AVLNode *b = a->rchild;
        a->rchild = right_rotate(b);
        return left_rotate(a);
    }
};