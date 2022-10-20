#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int n, cnt, hd[qwe], dis[qwe], p, ans;
char a, b, st, ed;
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

void dij(int s)
{
    priority_queue<NODE> q;
    dis[s] = p;
    q.push((NODE){p, s});
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
            if (edge[i].w == 1)
            {
                if (dis[y] > dis[u] + 1)
                {
                    dis[y] = dis[u] + 1;
                    if (!vis[y])
                    {
                        q.push(NODE(dis[y], y));
                    }
                }
            }
            if (edge[i].w == -1)
            {
                if (dis[y] > dis[u] + ceil(dis[u]/20))
                {
                    dis[y] = dis[u] + ceil(dis[u]/20);
                    if (!vis[y])
                    {
                        q.push(NODE(dis[y], y));
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int i = 1;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        for (int i = 0; i <= n; i++)
        {
            scanf("%c %c", &a, &b);
            if (a >= 'a')
            {
                pls(int(b), int(a), 1);
            }
            else
            {
                pls(int(b), int(a), -1);
            }
            if (b >= 'a')
            {
                pls(int(a), int(b), 1);
            }
            else
            {
                pls(int(a), int(b), -1);
            }
        }
        scanf("%d %c %c", &p, &st, &ed);
        dij(ed);
        printf("case %d: %d", i, dis[1]);
        i++;
    }
}