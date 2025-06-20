#include "String.h"

class SqString
{
public:
	char *data;
	int length;

	int getlength()
	{
		return length;
	}
	SqString &SubStr(int i, int j)
	{
		static SqString s;
		if (i < 0 || i >= length || i + j > length || j < 0)
		{
			return s;
		}
		for (int k = i; k < i + j; k++)
		{
			s.data[k - i] = data[k];
		}
		s.length = j;
		return s;
	}

	int Strcmp(SqString &s, SqString &t)
	{
		int minl = min(s.getlength(), t.getlength());
		for (int i = 0; i < minl; i++)
		{
			if (s.data[i] > t.data[i])
				return 1;
			else if (s.data[i] < t.data[i])
				return -1;
			if (s.getlength() == t.getlength())
				return 0;
			else if (s.getlength() > t.getlength())
				return 1;
			else
				return -1;
		}
	}
};

struct LinkNode
{
	char data;
	LinkNode *next;
	LinkNode() : next(NULL) {}
	LinkNode(char d) : data(d), next(NULL) {}
};

class LinkString
{
public:
	LinkNode *head;
	int length;

	LinkString &InsStr(int i, LinkString &t)
	{
		static LinkString s;
		if (i < 0 || i > length)
			return s;
		LinkNode *p = head->next, *p1 = t.head->next;
		LinkNode *r = s.head, *q;
		for (int k = 0; k < i; k++)
		{
			q = new LinkNode(p->data);
			r->next = q;
			r = q;
			p = p->next;
		}
		while (p1 != NULL)
		{
			q = new LinkNode(p1->data);
			r->next = q;
			r = q;
			p1 = p1->next;
		}

		while (p != NULL)
		{
			q = new LinkNode(p->data);
			r->next = q;
			r = q;
			p = p->next;
		}
		s.length = length + t.length;
		r->next = NULL;
		return s;
	}

	bool StrEqual1(LinkString &s, LinkString &t)
	{
		if (s.length != t.length)
			return false;
		for (int i = 0; i < s.length; i++)
		{
			if (s.geti(i) != t.geti(i))
				return false;
		}
		return true;
	}

	bool StrEqual2(LinkString &s, LinkString &t)
	{
		if (s.length != t.length)
			return false;
		LinkNode *p = s.head->next;
		LinkNode *q = t.head->next;
		while (p != NULL && q != NULL)
		{
			if (p->data != q->data)
				return false;
			p = p->next;
			q = q->next;
		}
		return true;
	}

	char geti(int i)
	{
		LinkNode *p = head->next;
		for (int j = 0; j < i; j++)
		{
			p = p->next;
		}
		return p->data;
	}
};

void GetNextCopy(string t, int *next)
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < t.length() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMP_Copy(string s, string t)
{
	int n = s.length(), m = t.length();
	int *next = new int[m];
	GetNext(t, next);
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= m)
		return i - m;
	else
		return -1;
}
void GetNext(string t, int *next)
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < t.length() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMP(string s, string t)
{
	int n = s.length(), m = t.length();
	int *next = new int[m];
	GetNext(t, next);
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (j == -1 || s[i] == t[j]) // j = -1或匹配成功，向后移
		{
			i++;
			j++;
		}
		else
			j = next[j]; // 否则回退，继续尝试匹配
	}
	if (j >= m)
		return i - m; // 模式串已经遍历完，说明匹配完成，返回第一个匹配成功字符的索引
	else
		return -1; // 否则说明模式串没有遍历完，返回-1
}

void GetNextval(string t, int *nextval)
{
	int j = 0, k = -1;
	nextval[0] = -1;
	// 关键矛盾在于如果t[j] == next[j]，那么在进行回退匹配时一定会失配，
	// 注意一个关键点 k 其实就是 next[j]
	// 当匹配成功后，此时看 是否有 t[j] == t[next[j]]，也就是t[j] == t[k]
	// 如果成立，那么就跳转到next[next[j]]，也就是next[j] = next[next[j]]即next[j] = next[k]

	while (j < t.length() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			if (t[j] != t[k])	// 后移之后继续判断
				nextval[j] = k; // 如果匹配失败，则可以直接记录
			else
				nextval[j] = nextval[k];
		}
		else
			k = nextval[k];
	}
}

int KMPval(string s, string t)
{
	int n = s.length(), m = t.length();
	int *nextval = new int[m];
	GetNextval(t, nextval);
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j >= m)
		return i - m;
	else
		return -1;
}
