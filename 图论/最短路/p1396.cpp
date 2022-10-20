#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 1;
const int maxm = 1e5 + 1;
int n, m, s, t, hd[maxm], cnt, dis[maxm], vis[maxm],uu,vv,ww;
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
void dij()
{
   memset(dis, 0x3f, sizeof(dis));
   memset(vis, 0, sizeof(vis));
   dis[s] = 0;
   q.push(NODE(0, s));
   while (!q.empty())
   {
      int u = q.top().id;
      q.pop();
      if (vis[u])
         continue;
      vis[u] = 1;
      for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int y = max(dis[u], edge[i].w);
            int r = edge[i].to;
            if (y < dis[r])
            {
                dis[r] = y;
                q.push(NODE(dis[r], r));
                // cout << r<<" ";
            }
        }
   }
}
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        pls(uu, vv, ww);
        pls(vv, uu, ww);
    }
    dij();
    cout << dis[t];
   return 0;
}