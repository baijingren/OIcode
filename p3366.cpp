#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const int qwe = 1000005;
int cnt, hd[qwe], ans, dis[qwe], n, m;
bool vis[qwe];
struct Edge
{
	int to, nxt, w;
} edge[qwe];
void pls(int u, int v, int w)
{
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = hd[u];
	edge[cnt].w = w;
	hd[u] = cnt;
}
void prim()
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	for (int i = hd[1]; i ; i = edge[i].nxt)
	{
		dis[edge[i].to] = min(dis[edge[i].to], edge[i].w);
	}
	int o = 1;
	while (o < n)
	{
		int mn = inf, a = 1;
		vis[a] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && mn > dis[i])
			{
				mn = dis[i];
				a = i;
			}
		}
		ans += mn;
		for (int i = hd[a]; i ; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dis[v] > edge[i].w&&!vis[i])
			{
				dis[v] = edge[i].w;
			}
		}
		o++;
	}
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int uu, vv, ww;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &uu, &vv, &ww);
		pls(uu, vv, ww);
		pls(vv, uu, ww);
	}
	prim();
	printf("%d", ans);
	return 0;
}
