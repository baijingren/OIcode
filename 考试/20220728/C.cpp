#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
vector<int> e[qwe], scc[qwe];
int dfn[qwe], low[qwe], cnt = 0;
stack<int> s;
bool vis[qwe];
int tot = 0;
int c[qwe];
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    vis[u] = 1;
    s.push(u);
    for (int v : e[u])
    {
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        tot++;
        int v = 0;
        do
        {
            v = s.top(), s.pop();
            vis[v] = 0;
            c[v] = tot;
            scc[tot].push_back(v);
        } while (u != v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        // e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, 0);
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}