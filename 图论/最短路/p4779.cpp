#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll qwe = 200005;
ll m, n, s, t, cnt, uu, vv, ww, hd[qwe], dis[qwe], maxx = -1, all[qwe];
bool vis[qwe];
struct Edge
{
    ll to, nxt, w;
} edge[qwe];
void pls(ll u, ll v, ll w)
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
    ll id, s;
    NODE(ll x, ll y)
    {
        s = x, id = y;
    }
};

bool operator<(NODE x, NODE y)
{
    return x.s > y.s;
}

void dij()
{
    priority_queue<NODE> q;
    dis[s] = 0;
    q.push((NODE){0, s});
    while (!q.empty())
    {
        ll u = q.top().id;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            ll y = edge[i].to;
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
void dijkstra()
{
    dis[s] = 0;
    priority_queue<NODE> q;
    q.push((NODE){s, 0});
    while (!q.empty())
    {
        ll u = q.top().id, d = q.top().s;
        q.pop();
        if (d != dis[u])
            continue;
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            ll v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                q.push((NODE){v, dis[v]});
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &uu, &vv, &ww);
        pls(uu, vv, ww);
    }
    for (int i = 1; i <= n; ++i)
    {
        s = i;
        dijkstra();
        all[i] = dis[t];
    }
    memset(dis, 0x3f, sizeof(dis));
    dij();
    for (int i = 1; i <= n; ++i)
    {
        all[i] += dis[i];
        maxx = max(maxx, all[i]);
    }
    cout << maxx;
    return 0;
}