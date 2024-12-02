#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
int n, m, s, t;

int cnt = 1, hd[qwe];
struct Edge
{
    int nxt, to;
    ll w;
} edge[qwe];
void add(int u, int v, ll w)
{
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

// queue<int> q;
int lst[qwe]; // 这个lst是干什么的呢
ll flow[qwe]; 
ll ans;

void init()
{
    memset(lst, -1, sizeof(lst));
    flow[s] = LONG_LONG_MAX;
}
bool bfs()
{
    init();
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == t)
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
    return lst[t] != -1;
}

int main()
{
    // freopen("/home/bai/code/test.in","r",stdin);
    // freopen("/home/bai/code/test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    while (bfs())
    {
        // cerr<<'a';
        ans += flow[t];
        for (int i = t; i != s; i = edge[lst[i] ^ 1].to)
        {
            edge[lst[i]].w -= flow[t];
            edge[lst[i] ^ 1].w += flow[t];
        }
    }
    // cout<<fixed<<setprecision(4)<<1.0<<endl;
    cout << ans << endl;
    return 0;
}