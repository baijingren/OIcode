#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int m, n, x, cnt=1, hd[qwe], dis[qwe], ans[qwe], fhd[qwe], fdis[qwe];
bool vis[qwe], fvis[qwe];
struct Edge
{
    int to, nxt, w;
} edge[qwe], fedge[qwe];
void pls(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    edge[cnt].w = w;
    hd[u] = cnt;
    fedge[cnt].to = u;
    fedge[cnt].w = w;
    fedge[cnt].nxt = fhd[v];
    fhd[v] = cnt;
    return;
}
struct NODE
{
    int id, s;
    NODE(int x, int y)
    {
        s = x, id = y;
    }
};

bool operator<(NODE x, NODE y)
{
    return x.s > y.s;
}
priority_queue<NODE> q;
void dij(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    q.push((NODE){0, s});
    while (!q.empty())
    {
        int u = q.top().id;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int y = edge[i].to;
            if (dis[y] > dis[u] + edge[i].w)
            {
                dis[y] = dis[u] + edge[i].w;
                if (!vis[y])
                {
                    q.push(NODE(dis[y], y));
                }
            }
        }
    }
}
priority_queue<NODE> fq;
void fdij(int s)
{
    memset(fdis, 0x3f, sizeof(fdis));
    memset(fvis, 0, sizeof(fvis));
    fdis[s] = 0;
    fq.push((NODE){0, s});
    while (!fq.empty())
    {
        int u = fq.top().id;
        fq.pop();
        if (fvis[u])
        {
            continue;
        }
        fvis[u] = true;
        for (int i = fhd[u]; i; i = fedge[i].nxt)
        {
            int y = fedge[i].to;
            if (fdis[y] > fdis[u] + fedge[i].w)
            {
                fdis[y] = fdis[u] + fedge[i].w;
                if (!fvis[y])
                {
                    fq.push(NODE(fdis[y], y));
                }
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m, &x);
    int uu, vv, ww;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        pls(uu, vv, ww);
    }
    dij(x);
    fdij(x);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = dis[i] + fdis[i];
        if (ans[i]==0x3f3f3f3f*2)
        {
            ans[i] = 0;
        }
    }
    sort(ans + 1, ans + n + 1);
    printf("%d", ans[n]);
    return 0;
}