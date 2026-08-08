#include <bits/stdc++.h>
#define PII pair<int, int>
#define MP make_pair
#define V first
#define W second
using namespace std;
const int qwe = 1e6 + 5;
int n, m, ans;
int _cnt = 0, hd[qwe];
struct Edge
{
    int to, nxt, w, u;
} edge[qwe];
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define w(i) edge[i].w
#define u(i) edge[i].u
void add(int u, int v, int w)
{
    _cnt++;
    to(_cnt) = v;
    w(_cnt) = w;
    u(_cnt) = u;
    nxt(_cnt) = hd[u];
    hd[u] = _cnt;
}
vector<PII> e[qwe];
int dfn[qwe], low[qwe], cnt = 0, num = 0, c[qwe];
bool vis[qwe];
stack<int> s;
void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    vis[u] = 1;
    for (auto i : e[u])
    {
        int v = i.V;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        num++;
        int v = s.top();
        s.pop();
        vis[v] = 0;
        c[v] = num;
        while (u != v)
        {
            v = s.top();
            s.pop();
            vis[v] = 0;
            c[v] = num;
        }
    }
}
int f[qwe];
void clear()
{
    cnt = 0;
    ans = 0;
    num = 0;
    while (!s.empty())
        s.pop();
    for (int i = 0; i < n; i++)
        e[i].clear();
    memset(f,0x3f,sizeof(f));
    memset(hd, 0, sizeof(hd));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(edge, 0, sizeof(edge));
}
int fa[qwe];
int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
void kru()
{
    sort(edge + 1, edge + _cnt + 1, [](Edge x, Edge y)
         { return x.w < y.w; });
    for (int i = 1; i <= num; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= _cnt; i++)
    {
        int x = fnd(u(i));
        int y = fnd(to(i));
        // cout<<x<<' '<<y<<' '<<u(i)<<' '<<to(i)<<endl;
        if (x == y)
            continue;
        fa[x] = y;
        ans += w(i);
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d", &n, &m);
        if (!n && !m)
            break;
        clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back(MP(v, w));
        }
        tarjan(0);
        // for(int i=0;i<n;i++){
        //     for(auto j:e[i]){
        //         printf("%d %d\n",j.first,j.second);
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            for (auto j : e[i])
            {
                int v = j.V;
                // cout<<1;
                if (c[i] == c[v])
                {
                    continue;
                }
                add(c[i], c[v], j.W);
                f[c[v]]=min(f[c[v]],j.W);
                // cout<<c[v]<<endl;
            }
        }
        // cout<<num<<endl;
        // kru();
        for(int i=1;i<num;i++){
            ans+=f[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}