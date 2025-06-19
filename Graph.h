#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int MAXV = 100;
const int INF = 0X3F3F3F3F;

class MatGraph
{
public:
    int edges[MAXV][MAXV]; // 邻接矩阵
    int n, e;              // 顶点数和边数
    string vexs[MAXV];     // 存放顶点信息

    void CreateMaxGraph(int a[][MAXV], int n, int e)
    {
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->edges[i][j] = a[i][j];
            }
        }
    }

    void DispMatGraph();
};

int Degree1(MatGraph &g, int v);
vector<int> Degree2(MatGraph &g, int v);

struct ArcNode
{
    int adjvex;       // 邻接点
    int weight;       // 权值
    ArcNode *nextarc; // 指向下一条边的边结点
};

struct HNode
{
    string info;
    ArcNode *firstarc;
};

class AdjGraph
{
public:
    HNode adjlist[MAXV];
    int n, e;
    AdjGraph()
    {
        for (int i = 0; i < MAXV; i++)
        {
            adjlist[i].firstarc = NULL;
        }
    }

    ~AdjGraph()
    {
        ArcNode *pre, *p;
        for (int i = 0; i < n; i++)
        {
            pre = adjlist[i].firstarc;
            if (pre != NULL)
            {
                p = pre->nextarc;
                while (p != NULL)
                {
                    delete pre;
                    pre = p;
                    p = p->nextarc;
                }
                delete pre;
            }
        }
    }

    void CreateAdjGraph(int a[][MAXV], int n, int e)
    {
        ArcNode *p;
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (a[i][j] != 0 && a[i][j] != INF)
                {
                    p = new ArcNode();
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc; // 头插法
                    adjlist[i].firstarc = p;
                }
            }
        }
    }

    void DispAdjGraph();
};

int Degree1(AdjGraph &G, int v);

vector<int> Degree2(AdjGraph &G, int v);

//=======简化的邻接表=======
const int MAXE = 200;
int head[MAXV];
struct Edge
{
    int adjvex;
    int weight;
    int next;
} edges[MAXE];

int n;
int cnt;

void addedge(int u, int v, int w)
{
    edges[cnt].adjvex = v;
    edges[cnt].weight = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
}

void CreateAdjGraph(vector<vector<int>> a, int n)
{
    for (int i = 0; i < a.size(); i++)
    {
        addedge(a[i][0], a[i][i], a[i][2]);
    }
}

void DispAdjGraph()
{
    for (int i = 0; i < n; i++)
    {
        printf("    [%d]", i);
        for (int j = head[i]; j != -1; j = edges[j].next)
        {
            printf(" (%d,%d,%d)", edges[i].adjvex, edges[j].weight, edges[j].next);
        }
        printf("\n");
    }
}

// ==========图的遍历========
// 深度优先
int visited[MAXV];
void DFS(AdjGraph &G, int v)
{
    cout << v << " ";
    visited[v] = 1;
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (visited[w] == 0)
            DFS(G, w);
        p = p->nextarc;
    }
}

void DFS(MatGraph &g, int v)
{
    cout << v << " ";
    visited[v] = 1;
    for (int w = 0; w < g.n; w++)
    {
        if (g.edges[v][w] != 0 && g.edges[v][w] != INF)
        {
            if (visited[w] == 0)
                DFS(g, w);
        }
    }
}

void BFS(AdjGraph &G, int v)
{
    int visited[MAXV];
    queue<int> qu;
    cout << v << " ";
    visited[v] = 1;
    qu.push(v);
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        ArcNode *p = G.adjlist[u].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                cout << p->adjvex << " ";
                visited[p->adjvex] = 1;
                qu.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

void BFS(MatGraph &g, int v)
{
    int visited[MAXV];
    queue<int> qu;
    cout << v << " ";
    visited[v] = 1;
    qu.push(v);
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < g.n; i++)
        {
            if (g.edges[u][i] != 0 && g.edges[u][i])
            {
                cout << i << " ";
                visited[i] = 1;
                qu.push(i);
            }
        }
    }
}

void DFSA(AdjGraph &G)
{
    for (int i = 0; i < G.n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(G, i);
        }
    }
}

void BFSA(AdjGraph &G)
{
    for (int i = 0; i < G.n; i++)
    {
        if (visited[i] == 0)
        {
            BFS(G, i);
        }
    }
}

//=====判断无向图的连通性========
bool Connect(AdjGraph &G)
{
    DFS(G, 0);
    for (int i = 0; i < G.n; i++)
    {
        if (visited[i] == 0)
        {
            return false;
        }
    }

    return true;
}
