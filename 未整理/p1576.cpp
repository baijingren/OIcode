#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int n, m, cnt, hd[qwe],a,b;
bool vis[qwe];
double dis[qwe];
struct Edge
{
    int to, nxt;
    double w;
} edge[qwe];
void add(int u, int v, double w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    edge[cnt].w = w;
    hd[u] = cnt;
}
queue<int> q;
void spfa(int s)
{
    for (int i=0;i<=n+1;i++) dis[i]=23333333.0;
    dis[s] = 100.0;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd[u]; i; i=edge[i].nxt)
        {
            int v = edge[i].to;
            if (dis[v]>dis[u]/(1-0.01*edge[i].w))
            {
                dis[v]=dis[u]/(1-0.01*edge[i].w);
                if (vis[v] == 0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int uu, vv;
    double ww;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%lf", &uu, &vv, &ww);
        add(uu, vv, ww);
        add(vv, uu, ww);
    }
    scanf("%d %d", &a, &b);
    spfa(b);
    printf("%.8lf",dis[a]);
    return 0;
}