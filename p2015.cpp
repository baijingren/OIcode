#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, q, cnt = 0;
int hd[qwe], a[qwe];
int f[qwe][qwe];
struct EDGE
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
    return;
}
void dfs(int u, int fa)
{
    for(int i = hd[u]; i; i = edge[i].nxt)
    {
		int v = edge[i].to;
        if(v == fa)
        {
            continue;
        }
		dfs(v, u);
        a[u] += a[v]+1;
		for(int j = min(a[u], q); j; j--)
        {
            for(int k = min(a[v], j-1); k >= 0; k--)
            {
				f[u][j] = max(f[u][j], f[u][j-k-1] + f[v][k] + edge[i].w);
            }
        }
			
	}
    return;
}
int main()
{
    freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &q);
    int uu, vv, ww;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        add(uu, vv, ww);
        add(vv, uu, ww);
    }
    dfs(1, -1);
    printf("%d", f[1][q]);
    return 0;
}