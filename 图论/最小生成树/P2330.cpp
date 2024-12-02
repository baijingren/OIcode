#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
struct Edge
{
    int to, nxt, w;
};

Edge edge[qwe];
int cnt = 0, hd[qwe];
void add(int u, int v, int w)
{
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

struct Dis
{
    int u, w;
    bool operator>(const Dis &b) const
    {
        return w > b.w;
    }
};

priority_queue<Dis, vector<Dis>, greater<Dis>> q;
int dis[qwe];
bool vis[qwe];
int ans = 0, cntPnt = 0;
void bfs()
{
    memset(dis, 0x7f, sizeof(dis));
    dis[1] = 0;
    q.push({1, 0});
    while (q.size())
    {
        if(cntPnt >= n){
            break;
        }
        auto tmp = q.top();
        int u = tmp.u;
        int w = tmp.w;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        ++cntPnt;
        ans = max(ans, w);
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int v = edge[i].to;
            if(vis[v]){
                continue;
            }
            if(dis[v] > edge[i].w){
                dis[v] = edge[i].w;
                q.push({v, dis[v]});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u ,v, w);
        add(v, u, w);
    }
    bfs();
    cout << n - 1 << ' ' << ans << endl;
    return 0;
}