#include <bits/stdc++.h>
using namespace std;
const int qwe = 50005;
int n, m, cnt, hd[qwe], dis[qwe], rec[qwe];
bool vis[qwe];
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
}
priority_queue<int> q;
bool spfa(int s)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    memset(rec, 0, sizeof(rec));
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = false;
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                rec[v] = rec[u] + 1;
                if (rec[v] > n)
                    return false;
                if (vis[v] == false)
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin>>m>>n;
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        cin >> u >> v >> w;
        add(u, v, -w);
    }
    int ans;
    if (!spfa(1))
    {
        cout << "Forever love" << endl;
        return 0;
    }
    ans = dis[n];
    if(!spfa(n))
    {
        cout << "Forever love" << endl;
        return 0;
    }
    cout << min(ans,dis[1]) << endl;
    return 0;
}