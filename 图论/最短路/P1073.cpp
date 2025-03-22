#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int qwe = 1e6 + 5;
struct Edge
{
    int nxt, to, w;
};

int hd[qwe], cnt = 0;
Edge edge[qwe];
void add(int u, int v, int w)
{
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

int dfn[qwe], low[qwe], cntTarjan = 0, cntDfn = 0;
int c[qwe], cntPnt[qwe];
vector<int> scc[qwe];
bool vis[qwe];
stack<int> s;
template <typename _Tp>
{
    struct Edge
    {
        int nxt, to;
        _Tp w;
    };
    void add(int u, int v, _Tp w)
    {
        edge[++cnt].nxt = hd[u];
        edge[cnt].to = v;
        edge[cnt].w = w;
        hd[u] = cnt;
    }
}
void dfs(int u)
{
    vis[u] = 1;
    dfn[u] = low[u] = ++cntDfn;
    s.push(u);
    for (int i = hd[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (vis[v])
        {
            low[u] = min(low[u], dfn[v]);
            continue;
        }
        dfs(v);
        low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u])
    {
        ++cntTarjan;
        int y;
        do
        {
            y = s.top();
            s.pop();
            c[y] = cntTarjan;
            scc[cntTarjan].push_back(y);
            cntPnt[cntTarjan]++;
            vis[y] = 0;
        } while (y != u);
    }
}

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
}