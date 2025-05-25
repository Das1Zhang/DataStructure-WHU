#include "Tree.h"
#include<stack>
using namespace std;

void BTree::CreateBTree(string str)
{
    stack<BTNode*> st;
    BTNode* p;
    bool flag;
    int i = 0;
    while(i<str.length())
    {
        switch(str[i])
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
                if(r == NULL){
                    r = p;
                }
                else{
                    if(flag && !st.empty())
                        st.top()->lchild = p;
                    else if(!st.empty())
                        st.top()->rchild = p;
                }
                break;
        }
        i++;
    }
}

void BTree::DispBTree1(BTNode* b)
{
    if(b!=NULL)
    {
        cout<< b->data;
        if(b->lchild!=NULL || b->rchild != NULL)
        {
            cout<<"(";
            DispBTree1(b->lchild);
            if(b->rchild != nullptr)
                cout<<",";
            DispBTree1(b->rchild);
            cout<<")";
        }
    }
}

void BTree::DispBTree()
{
    DispBTree1(r);
}