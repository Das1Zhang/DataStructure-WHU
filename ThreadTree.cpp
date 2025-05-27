#include "ThreadTree.h"
#include <iostream>

using namespace std;

void ThreadTree::DestroyBTree1(BthNode *b)
{
    if (b->ltag == 0)
        DestroyBTree1(b->lchild);
    if (b->rtag == 0)
        DestroyBTree1(b->rchild);
    delete b;
}

void ThreadTree::CreateThread()
{
    root = new BthNode();
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = r;
    if (r == nullptr)
    {
        root->lchild = root;
        root->rchild = nullptr;
    }
    else
    {
        root->lchild = r;
        pre = root;
        Thread(r);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
}

void ThreadTree::Thread(BthNode *&p)
{
    if (p != nullptr)
    {
        Thread(p->lchild);
        if (p->lchild == nullptr)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        else
            p->ltag = 0;
        if (pre->rchild == nullptr)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        else
            pre->rtag = 0;
        pre = p;
        Thread(p->rchild);
    }
}

void ThreadTree::ThInOrder()
{
    BthNode *p = root->lchild;
    while (p != root)
    {
        while (p != root && p->ltag == 0)
            p = p->lchild;
        cout << p->data;
        while (p->rtag == 1 && p->rchild != root)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}