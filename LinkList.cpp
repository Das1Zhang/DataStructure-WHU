
#include"LinkList.h"



template<typename T>
struct LinkNode
{
	T data;
	LinkNode<T>* next;
	LinkNode() :next(NULL) {}
	LinkNode(T d) :data(d), next(NULL) {}
};

template<typename T>
class LinkList
{
public:
	LinkNode<T>* head;

	void Insert(T* s, T* p)
	{
		s->next = p->next;
		p->next = s;
	}

	void Delete(T* p)
	{
		LinkNode<T>* q = p->next;
		p->next = q->next;
		delete q;
	}

	void CreateList(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			LinkNode<T>* s = new LinkNode<T>(a[i]);
			s->next = head->next;
			head->next = s;
		}
	}

	void CreateListR(T a[], int n)
	{
		LinkNode<T>* s, * r;
		r = head;
		for (int i = 0; i < n; i++)
		{
			s = new LinkNode<T>(a[i]);
			r->next = s;
			r = s;
		}
		r->next = NULL:
	}

	LinkNode<T>* geti(int i)
	{
		if (i < -1) return NULL;

		LinkNode<T>* temp = head;
		int j = -1;
		while (j < i && temp != NULL)
		{
			j++;
			temp = temp->next;
		}
		return temp;
	}

	LinkList()
	{
		head = new LinkNode<T>();
	}

	~LinkList()
	{
		LinkNode<T>* pre, * p;
		pre = head;
		p = head->next;
		while (p != NULL)
		{
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}

	void Add(T e)
	{
		LinkNode<T>* s = new LinkNode<T>(e);
		LinkNode<T>* p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}

	int Getlength()
	{
		LinkNode<T>* p = head;
		int i = 0;
		while (p->next != NULL)
		{
			i++;
			p = p->next;
		}
		return i;
	}

	//把序号为i的节点的数据赋给e
	bool GetElem(int i, T& e)
	{
		if (i < 0) return false;
		LinkNode<T>* p = geti(i);
		if (p != NULL)
		{
			e = p->data;
			return true;
		}
		else
			return false;
	}

	bool SetElem(int i, T e)
	{
		if (i < 0) return false;
		LinkNode<T>* p = geti(i);
		if (p != NULL)
		{
			p->data = e;
			return true;
		}
		else
			return false;
	}

	int GetNo(T e)
	{
		LinkNode<T>* p = head -> next;
		int i = 0;
		while (p != NULL && p->data != e)
		{
			i++;
			p = p->next;
		}
		
		if (p == NULL)
			return false;
		else
			return i;
	}

	bool Insert(int i, T e)
	{
		if (i < 0) return false;
		LinkNode<T>* p = geti(i-1);
		if (p == NULL) return false;
		
		LinkNode<T>* s = new LinkNode<T>(e);

		s->next = p->next;
		p->next = s;
		return true;
	}

	bool Deletei(int i)
	{
		if (i < 0) return false;
		LinkNode<T>* p = geti(i - 1);
		if (p != NULL)
		{
			LinkNode<T>* q = p->next;
			if (q != NULL)
			{
				p->next = q->next;
				delete q;
			}
			else return false;
		}
		else return false;
	}

	void DispList()
	{
		LinkNode<T>* p = head->next;
		while (p != NULL)
		{
			cout << p->data < " ";
			p = p->next;
		}

		cout << endl;
	}
};

template<typename T>
void merge2(LinkList<T>& A, LinkList<T>& B, LinkList<T>& C)
{
	LinkNode<T>* p = A.head->next;
	LinkNode<T>* q = B.head->next;
	LinkNode<T>* r = C.head;

	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	r->next = NULL;
	if (p != NULL) r->next = p;
	if (q != NULL) r->next = q;


}

template<typename T>
struct DlinkNode
{
	T data;
	DlinkNode* next;
	DlinkNode* prior;
	DLinkNode() :next(NULL), prior(NULL) {}
	DLinkNode(T d) :data(d), next(NULL), prior(NULL) {}
};

template<typename T>
class CDLinkList
{
public:
	DLinkNode<T>* dhead;
	CDLinkList()
	{
		dhead = new DLinkNode<T>();
		dhead->next = NULL;
		dhead->prior = NULL;
	}

	~CDLinkList()
	{
		DLinkNode<T>* pre, * p;
		pre = head;
		p = head->next;
		while (p != NULL)
		{
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
};

template<typename T>
class CLinkList
{
public:
	LinkNode* <T> head;

	CLinkList()
	{
		head = new LinkNode<T>();
		head->next = head;
	}

	~CLinkList()
	{
		LinkNode<T>* pre, * p;
		pre = head;
		p = head->next;

		while (p != NULL)
		{
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}


};


struct Child
{
	int no;
	Child* next;
	Child(int d) :no(d), next(NULL) {}

};
class Joseph
{
	int n, m;
	Child* first;
public:
	Joseph(int nl, int ml) :n(nl), m(ml) {}
	void CreateList()
	{
		first = new Child(1);
		Child* r = first;
		Child* p;
		for (int i = 2; i <= n; i++)
		{
			p = new Child(i);
			r->next = p;
			r = p;
		}
		r->next = first;
	}

	void Jsequence()
	{
		Child* p, * q;
		for (int i = 1; i <= n; i++)
		{
			p = first;
			int j = 1;
			while (j != m)
			{
				j++;
				p = p->next;
			}
			cout << p->no << " ";
			q = p->next;
			p->no = q->no;
			p->next = q->next;

		}
	}
};