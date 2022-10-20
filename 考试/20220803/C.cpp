#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int qwe = 2e6 + 5;
int n;
ll ans = 0;
int k;
struct EDGE{
    int to,nxt,w;
} edge[qwe];
int hd[qwe],cnt_edge=1;
void add(int u,int v,int w){
    cnt_edge++;
    edge[cnt_edge].to=v;
    edge[cnt_edge].w=w;
    edge[cnt_edge].nxt=hd[u];
    hd[u]=cnt_edge;
}
ll f[qwe];
int v[qwe], vis[qwe];
ll s[qwe];
ll dp[qwe];
int r[qwe], cnt = 0;
bool dfs(int u, int fa)
{   
    if (v[u] == 1)
    {
        v[u] = 2;
        vis[u] = 1;
        r[++cnt] = u;
        return 1;
    }
    v[u] = 1;
    for (int i=hd[u];i;i=edge[i].nxt)
    {
        int v = edge[i].to,w=edge[i].w;
        if (i!=(fa^1) && dfs(v, i))
        {
            if (::v[u] != 2)
            {
                r[++cnt] = u;
                vis[u] = 1;
                s[cnt] = s[cnt - 1] + w;

            }
            else
            {
                s[k - 1] = s[k] - w;
                return 0;
            }
            return 1;
        }
    }
    return 0;
}
void dfs2(int u)
{
    vis[u] = 1;
    for (int i=hd[u];i;i=edge[i].nxt)
    {
        int v = edge[i].to,w=edge[i].w;
        if (vis[v])
        {   
            continue;
        }
        dfs2(v);
        ans = max(ans, f[u] + f[v] + w);
        f[u] = max(f[u], f[v] + w);
    }
}
int sol(int x)
{
    ll ansss = 0, anssss = 0;
    k = cnt + 1;
    dfs(x, 0);
    for (int i = k; i <= cnt; i++)
    {
        ans = 0;
        dfs2(r[i]);
        ansss = max(ansss, ans);
        dp[i + (cnt - k + 1)] = f[r[i]];
        dp[i] = f[r[i]];
        s[i + (cnt - k + 1)] = s[i + cnt - k] + s[i] - s[i - 1];
    }
    deque<int> q;
    for (int i = k; i <= cnt + (cnt - k + 1); i++)
    {
        while (!q.empty() && q.front() <= i-cnt+k-1)
        {
            q.pop_front();
        }
        if (q.size())
        {
            anssss = max(anssss, dp[i] + dp[q.front()] + s[i] - s[q.front()]);
        }
        while (!q.empty() && dp[q.back()] - s[q.back()] <= dp[i] - s[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    return max(ansss, anssss);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        add(i,v,w);
        add(v,i,w);
    }
    ll solans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            solans += sol(i);
        }
    }
    cout << solans << '\n';
    return 0;
}