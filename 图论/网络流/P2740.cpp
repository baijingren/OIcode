#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e5 + 5;
int n, m;

int cnt = 1, hd[qwe];
struct Edge
{
    int nxt, to, w;
} edge[qwe];
void add(int u, int v, int w)
{
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

// queue<int> q;
int lst[qwe], flow[qwe]; // 这个lst是干什么的呢
int ans;

void init()
{
    memset(lst, -1, sizeof(lst));
    flow[1] = INT_MAX;
}
bool bfs()
{
    init();
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == m)
        {
            break;
        }
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int v = edge[i].to;
            if (edge[i].w > 0 && lst[v] == -1)
            {
                lst[v] = i;
                flow[v] = min(flow[u], edge[i].w);
                q.push(v);
            }
        }
    }
    return lst[m] != -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    while (bfs())
    {
        // cerr<<'a';
        ans += flow[m];
        for (int i = m; i != 1; i = edge[lst[i] ^ 1].to)
        {
            edge[lst[i]].w -= flow[m];
            edge[lst[i] ^ 1].w += flow[m];
        }
    }
    // cout<<fixed<<setprecision(4)<<1.0<<endl;
    cout << ans << endl;
    return 0;
}