#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
const int INF = 0x7ffffff;
int cnt, m, vis[maxn], dis[maxn],hd[maxn];
struct Edge
{
    int to, nxt, w;
} edge[maxn];
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
void dij(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis)); //结点标记
    dis[s] = 0;                  //点到自己的距离为0
    q.push(NODE(0, s));
    while (q.size())
    {
        int x = q.top().id;
        q.pop();
        if (vis[x])
            continue;
        else
            vis[x] = 1;
        for (int i = hd[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].to;
            if (dis[y] > dis[x] + edge[i].w)
            {
                dis[y] = dis[x] + edge[i].w;
                q.push(NODE(dis[y], y));
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int m, s;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        char x, y;
        int z;
        cin >> x >> y >> z;
        pls(int(x), int(y), z);
        pls(int(y), int(x), z);
    }
    dij(int('Z'));
    char ans = 'A';
    for (int i = 'B'; i <= 'Y'; i++)
        if (dis[int(i)] < dis[int(ans)])
            ans = i;
    cout << ans << " " << dis[int(ans)];
    return 0;
}