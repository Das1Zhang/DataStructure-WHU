#include "Graph.h"
void MatGraph::DispMatGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == INF)
            {
                printf("%4s", "INF");
            }
            else
            {
                printf("%4d", edges[i][j]);
            }
        }
    }
}

int Degree1(MatGraph &g, int v)
{
    int d = 0;
    for (int j = 0; j < g.n; j++)
    {
        if (g.edges[v][j] != 0 && g.edges[v][j] != INF)
        {
            d++;
        }
    }
    return d;
}

vector<int> Degree2(MatGraph &g, int v)
{
    vector<int> ans = {0, 0};
    for (int j = 0; j < g.n; j++)
    {
        if (g.edges[v][j] != 0 && g.edges[v][j] != INF)
        {
            ans[0]++;
        }
    }
    for (int i = 0; i < g.n; i++)
    {
        if (g.edges[i][v] != 0 && g.edges[i][v] != INF)
        {
            ans[1]++;
        }
    }
    return ans;
}

void AdjGraph::DispAdjGraph()
{
    ArcNode *p;
    for (int i = 0; i < n; i++)
    {
        printf("    [&d]", i);
        p = adjlist[i].firstarc;
        if (p != NULL)
            printf("->");
        while (p != NULL)
        {
            printf(" (%d, %d)", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
}

int Degree1(AdjGraph &G, int v)
{
    int d = 0;
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        d++;
        p = p->nextarc;
    }
    return d;
}

vector<int> Degree2(AdjGraph &G, int v)
{
    vector<int> ans = {0, 0};
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        ans[0]++;
        p = p->nextarc;
    }
    for (int i = 0; i < G.n; i++)
    {
        p = G.adjlist[i].firstarc;
        while (p != NULL)
        {
            if (p->adjvex = v)
            {
                ans[1]++;
                p = p->nextarc;
            }
        }
    }

    return ans;
}