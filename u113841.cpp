#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int m, n, s, cnt, uu, vv, ww, hd[qwe], dis[qwe];
bool vis[qwe];
struct Edge
{
    int to, nxt, w;
} edge[qwe];
void pls(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    edge[cnt].w = w;
    hd[u] = cnt;
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
void dij()
{
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
        for( int i = hd[u]; i; i = edge[i].nxt )
        {
            int y = edge[i].to;
            if( dis[y] > dis[u] + edge[i].w )
            {
                dis[y] = dis[u] + edge[i].w;
                if( !vis[y] )
                {
                    q.push(NODE(dis[y],y));
                }
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        pls(uu, vv, ww);
    }
    dij();
    printf("%d ", dis[s]);
    return 0;
}