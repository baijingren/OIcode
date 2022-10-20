#include<bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int n,m,k,cnt,hd[qwe],dis[qwe];
bool vis[qwe];
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
priority_queue<int> q;
void spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 0;
        for (int i = hd[u]; i; i=edge[i].nxt)
        {
            int v = edge[i].to;
            if (dis[v]>dis[u]+edge[i].w)
            {
                dis[v]=dis[u]+edge[i].w;
                if (vis[v] == 0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    int uu, vv, ww;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        add(uu, vv, ww);
    }
    spfa();
    printf("%d", dis[n]);
    return 0;
}