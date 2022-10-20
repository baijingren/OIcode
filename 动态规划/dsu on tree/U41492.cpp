#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6 + 5;
int n, m, cnt = 0, dfn = 0, sum = 0;
int a[qwe], size[qwe], hd[qwe], dep[qwe], son[qwe], col[qwe];
int ans[qwe];
bool vis[qwe];
struct Edge
{
    int to, nxt;
} edge[qwe];
void add(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    hd[u] = cnt;
}
void update(int u, int fa, int val, int bn)
{
    if (val == 1 && !vis[col[u]])
    { //if(val == 1){
        vis[col[u]] = 1;
        sum++;
    }
    if (val == -1)
    {
        vis[col[u]] = 0;
        sum--;
    }
    for (int i = hd[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (v == fa || v == bn)
            continue;
        update(v, u, val, bn);
    }
}
void dfs1(int u, int f)
{
    size[u] = 1;
    int mx = 0;
    for (int i = hd[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (v == f)
            continue;
        dfs1(v, u);
        if (size[v] > mx)
        {
            mx = size[v];
            son[u] = v;
        }
        size[u] += size[v];
    }
}
void dfs2(int u, int fa, bool ison)
{
    for (int i = hd[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (v == fa || v == son[u])
            continue;
        dfs2(v, u, 0);
    }
    if (son[u])
    {
        dfs2(son[u], u, 1);
    }
    update(u, fa, 1, son[u]);//update(u, fa, 1, 0)
    ans[u] = sum;
    if (!ison)
    {
        update(u, fa, -1, 0);
        sum = 0;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &col[i]);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    scanf("%d", &m);
    int q;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q);
        printf("%d\n", ans[q]);
    }
}