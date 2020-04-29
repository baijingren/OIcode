#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
const int rty = 5055;
int m, n, d, hd[qwe], dis[qwe], cnt, a, b, uu[rty], vv[rty], ww[rty];
bool vis[qwe], rec[105][105];
struct Edge
{
    int to, nxt, w;
} edge[qwe];
void add(int u, int v, int w)
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
    memset(dis, 0x3f, sizeof(dis));
    dis[a] = 0;
    q.push((NODE){0, a});
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
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d\n%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &uu[i], &vv[i], &ww[i]);
    }
    scanf("%d", &d);
    int u, v;
    for (int i = 1; i <= d; i++)
    {
        scanf("%d %d", &u, &v);
        rec[u][v] = 1;
        rec[v][u] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (rec[uu[i]][vv[i]] == 0)
        {
            add(uu[i], vv[i], 0);
            add(vv[i], uu[i], 0);
        }
        else
        {
            add(uu[i], vv[i], ww[i]);
            add(vv[i], uu[i], ww[i]);
        }
    }
    scanf("%d %d", &a, &b);
    dij();
    printf("%d", dis[b]);
    return 0;
}