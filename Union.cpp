#include "Union.h"

void Init()
{
    int n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int Find(int x)
{
    if (x != parent[x])
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y)
{
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry)
        return;
    if (rnk[rx] < rnk[ry])
        parent[rx] = ry;
    else
    {
        if (rnk[rx] == rnk[ry])
            rnk[rx]++;
        parent[ry] = rx;
    }
}