#include"Stack.h"

const int initcap = 100;
template<typename T>
class SqStack
{
	T* data;
	int top;
	int capacity;
	SqStack()
	{
		data = new T[initcap];
		capacity = initcap;
		top = -1;
	}

	~SqStack() {
		delete[]data;
	}

	bool recap(int newcap) {
		T* newdata = new int[newcap];
		if (!empty()) {
			for (int i = 0; i <= top; i++) {
				newdata[i] = data[i];
			}
		}
		delete[]data;
		data = newdata;
	}
	bool empty()
	{
		return top == -1;
	}

	bool push(T e) {
		if (top == capacity - 1) {
			recap(2 * capacity);
		}
		top++;
		data[top] = e;
		return true;
	}

	bool pop(T& e)
	{
		if (empty()) {
			return false;
		}
		e = data[top];
		top--;
		return true;
	}

	bool top()
	{
		return data[top];
	}
};

template<typename T>
class STACK {
	T data[initcap];
	T mindata[initcap];
	int top;
	int mintop;

	STACK() :top(-1), mintop(-1) {}

	bool minempty()
	{
		return mintop == -1;
	}

	bool minpush(T e) {
		mintop++;
		mindata[top] = e;
	}

	T minpop()
	{
		T x = mindata[mintop];
		mintop--;
		return x;
	}

	T mingettop()
	{
		return mindata[top];
	}

	bool empty()
	{
		return top == -1;
	}

	bool push(T x)
	{
		if (top == initcap - 1) return false;
		if (empty() || x <= Getmin()) minpush(x);
		top++;
		data[top] = x;
		return true;
	}

	bool pop(T& x)
	{
		if (empty()) return false;
		x = data[top];
		top--;
		if (x = mingettop())
		{
			minpop();
		}
		return true;
	}

	bool gettop(T& e)
	{
		if (empty()) return false;
		e = data[top];
		return true;
	}

	T Getmin() {
		return mingettop();
	}

};

template<typename T>
struct LinkNode
{
	T data;
	LinkNode* next;
	LinkNode() : next(NULL) {}
	LinkNode(T d) : data(d), next(NULL) {}
};

template<typename T>
class LinkStack {
public:
	LinkNode<T>* head;

	LinkStack()
	{
		head = new LinkNode<T>();
	}

	~LinkStack()
	{
		LinkNode<T>* pre = head, * p = pre->next;
		while (p != NULL) {
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}

	bool empty()
	{
		return head->next == NULL;
	}

	bool push(T e)
	{
		LinkNode<T> p = new LinkNode<T>(e);
		p->next = head->next;
		head->next = p;
		return true;
	}

	bool pop(T& e)
	{
		LinkNode<T>* p;
		if (head->next == NULL) return false;
		p = head->next;
		e = p->data;
		head->next = p->next;
		delete p;
		return true;
	}

	bool gettop(T& e) {
		LinkNode<T>* p;
		if (empty()) return false;
		p = head->next;
		e = p->data;
		return true;
	}

	T top() {
		return head->next->data;
	}

};