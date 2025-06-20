#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAXN 10

int parent[MAXN];
int rnk[MAXN];

void Init();
int Find(int x);
void Union(int x, int y);