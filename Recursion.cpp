#include<iostream>
#include<string>
#include<vector>
#include"LinkList.h"
using namespace std;

void Hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("将第%d个盘片从%c移动到%c\n", n, x, y, z);
	}
	else
	{
		Hanoi(n - 1, x, z, y);
		printf("将第%d个盘片从%c移动到%c\n", n, x, z);
		Hanoi(n - 1, y, x, z);
	}
}

int Min(int a[], int i)
{
	if (i == 0)
		return a[0];
	else
	{
		int mind = Min(a, i - 1);
		return min(mind, a[i]);
	}
}

/*
func(p)
if(p==NULL)
	return;
else
{
	cout<<p->data;
	func(p->next);
}

funcr(p)
if(p==NULL)
	return
else
{
	funcr(p->next)
	cout<<p->data;
}
*/

double pow(double x, int n)
{
	if (n == 1) return x;
	double p = pow(x, n / 2);
	if (n % 2 == 1)
		return x * p * p;
	else
		return p * p;
}

const int MAX = 10;
int dx[] = { -1,0,-1,0 };
int dy[] = { 0,1,0,1 };
int mg[MAX][MAX] = { {0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0} };
int m = 4, n = 4;
int cnt = 0;
class Box
{
public:
	int i;
	int j;
	Box(int i1, int j1) :i(i1), j(j1) {}
};

void mgpath(int xi, int yi, int xe, int ye, vector<Box> path)
{
	Box b(xi, yi);
	path.push_back(b);
	mg[xi][yi] = -1;
	if (xi == xe && yi == ye)
	{
		cnt++;
		printf("迷宫路径%d: ", cnt);
		for (int k = 0; k < path.size(); k++)
		{
			printf("(%d,%d) ", path[k].i, path[k].j);
		}
		printf("\n");
		mg[xi][yi] = 0;
		return;
	}
	else
	{
		int di = 0;
		while (di < 4)
		{
			int i = xi + dx[di];
			int j = yi + dy[di];
			if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0)
				mgpath(i, j, xe, ye, path);
			di++;
		}
		mg[xi][yi] = 0;
	}
}

bool place(int i, int j)
{
	if (i == 1) return true;
	int k = 1;
	while (k < i)
	{
		if (q[k] == j || (abs(q[k] - j) == abs(i - k)))
		{
			return false;
		}
		k++;
	}
	return true;
}

void queen(int i, int n)
{
	if (i > n)
		dispasolution(n);
	else
	{
		for (int j = 1; j <= n; j++)
		{
			if (place(i, j))
			{
				q[i] = j;
				queen(i + 1, n);
			}
		}
	}
}