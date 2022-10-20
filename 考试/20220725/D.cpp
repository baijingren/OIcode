#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int n, k, cnt, ans, p;
int hd[qwe], f[qwe], fa[qwe];
bool vis[qwe], v[qwe];
struct EDGE
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
}
void dp(int u)
{
    vis[u] = 1;
    for (int i = hd[u]; i; i = edge[i].nxt)
    {
        int to = edge[i].to;
        if (vis[to])
            continue;
        dp(to);
        ans = max(ans, f[u] + f[to] + edge[i].w);
        f[u] = max(f[u], f[to] + edge[i].w);
    }
}
void bfs(int x, bool y)
{
    queue<int> q;
    memset(f, 0, sizeof(f));
    memset(vis, 0, sizeof(vis));
    q.push(x);
    vis[x] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int to = edge[i].to;
            if (vis[to])
                continue;
            vis[to] = 1;
            f[to] = f[u] + edge[i].w;
            q.push(to);
            if (y)
                fa[to] = u;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans < f[i])
        {
            ans = f[i];
            p = i;
        }
    }
}
void change(int x)
{
    while (fa[x])
    {
        int to = fa[x];
        for (int i = hd[to]; i; i = edge[i].nxt)
        {
            int u = edge[i].to;
            if (u == x)
            {
                edge[i].w = -1;
                break;
            }
        }
        for (int i = hd[x]; i; i = edge[i].nxt)
        {
            int u = edge[i].to;
            if (u == to)
            {
                edge[i].w = -1;
                break;
            }
        }
        x = to;
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v, 1);
        add(v, u, 1);
    }
    ans = 0;
    if (k == 1)
    {
        bfs(1, 0);
        bfs(p, 0);
        printf("%d\n", 2 * (n - 1) - f[p] + 1);
    }
    else if (k == 2)
    {
        bfs(1, 0);
        bfs(p, 1);
        int li = f[p];
        change(p);
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        dp(1);
        printf("%d\n", 2 * n - ans - li);
    }

    return 0;
}