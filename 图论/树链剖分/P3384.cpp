#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6 + 5;
struct Edge
{
	int to, nxt, u, w;
};

int n, m, r, p;
int w[qwe];

int cnt = 0, hd[qwe];
Edge edge[qwe];
void add(int u, int v)
{
	edge[++cnt].nxt = hd[u];
	edge[cnt].to = v;
	edge[cnt].u = u;
	hd[u] = cnt;
}

int siz[qwe], son[qwe], dep[qwe], fa[qwe];
void dfs1(int u)
{
	son[u] = -1;
	for (int i = hd[u]; i; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if (v == fa[u])
		{
			continue;
		}
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		siz[u] += siz[v];
		if (son[u] == -1 || siz[v] >= siz[son[u]])
		{
			son[u] = v;
		}
	}
}
int dfn[qwe], top[qwe], rnk[qwe], btm[qwe];
int Cnt = 0;
int dfs2(int u, int rt)
{
	top[u] = rt;
	Cnt++;
	dfn[u] = Cnt;
	rnk[Cnt] = u;
	btm[u] = Cnt;
	if (son[u] != -1)
	{
		int tmp = dfs2(son[u], rt);
		btm[u] = max(btm[u], tmp);
	}
	for (int i = hd[u]; i; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if (v == son[u] || v == fa[u])
		{
			continue;
		}
		int tmp = dfs2(v, v);
		btm[u] = max(btm[u], tmp);
	}
	return btm[u];
}

ll t[qwe], d[qwe];
void addt(int u, int w)
{
	int x = u, tmp = u * w;
	while(x <= n)
	{
		// cerr << x << ' ';
		t[x] += w;
		d[x] += tmp;
		x += (x & (-x));
	}
}
void addT(int u, int v, int w)
{
	addt(u, w);
	addt(v + 1, -w);
}
ll query(int u)
{
	int x = u;
	ll ans = 0;
	while (x)
	{
		// cerr << -1;
		ans += t[x];
		x -= (x & (-x));
	}
	return ans;
}
ll queryt(int u){
	int x = u;
	ll ans = 0;
	while(x){
		// cerr << -1;
		ans += d[x];
		x -= (x & (-x));
	}
	return ans;
}
ll queryT(int u, int v)
{
	return query(v) * (v + 1) - query(u - 1) * u - queryt(v) + queryt(u - 1);
}

int s[qwe];
int main()
{
	scanf("%d %d %d %d", &n, &m, &r, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		// addt(i, w[i]);
	}
	// cerr << 0;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dep[0] = 0;
	fa[r] = 0;
	dep[r] = 1;
	dfs1(r);
	dfs2(r, r);
	for(int i = 1; i <= n; i++){
		addT(dfn[i], dfn[i], w[i]);
	}
	// cerr << Cnt << endl;
	// for(int i = 1; i <= n; i++){
	// 	cerr << top[i] << ' ';
	// }
	// cerr << endl;

	for (int i = 1; i <= m; i++)
	{
		int op, u, v, w;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d %d %d", &u, &v, &w);
			int x = u, y = v;
			if(x == y){
				addT(dfn[x], dfn[x], w);
				continue;
			}
			while (x != y)
			{
				// cerr << 1;
				if(top[x] == top[y]){
					if(dep[x] < dep[y]){
						swap(x, y);
					}
					for(; x != y;){
						addT(dfn[x], dfn[x], w);
						x = fa[x];
					}
					addT(dfn[x], dfn[x], w);
					break;
				}
				while (dep[x] > dep[y])
				{
					addT(dfn[top[x]], dfn[x], w);
					// addT(dfn[x] + 1, -w);
					x = fa[top[x]];
				}
				while (dep[y] > dep[x])
				{
					addT(dfn[top[y]], dfn[y], w);
					// addT(dfn[y] + 1, -w);
					y = fa[top[y]];
				}
				while (dep[x] == dep[y] && x != y)
				{
					addT(dfn[top[x]], dfn[x], w);
					// addT(dfn[x] + 1, -w);
					x = fa[top[x]];
					addT(dfn[top[y]], dfn[y], w);
					// addT(dfn[y] + 1, -w);
					y = fa[top[y]];
				}
			}
		}
		else if (op == 2)
		{
			scanf("%d %d", &u, &v);
			int x = u, y = v, ans = 0;
			while (x != y)
			{
				// cerr << 2;
				if(top[x] == top[y]){
					if(dep[x] < dep[y]){
						swap(x, y);
					}
					for(; x != y; x = fa[x]){
						ans += queryT(dfn[x], dfn[x]);
					}
					ans += queryT(dfn[x], dfn[x]);
					printf("%d\n", ans % p);
					break;
				}
				while (dep[x] > dep[y])
				{
					ans += queryT(dfn[top[x]], dfn[x]);
					x = fa[top[x]];
				}
				while (dep[y] > dep[x])
				{
					ans += queryT(dfn[top[y]], dfn[y]);
					y = fa[top[y]];
				}
				while (dep[x] == dep[y] && x != y)
				{
					ans += queryT(dfn[top[x]], dfn[x]);
					x = fa[top[x]];
					ans += queryT(dfn[top[y]], dfn[y]);
					y = fa[top[y]];
				}
			}
			if(x == y){
				ans += queryT(dfn[x], dfn[x]);
				// printf("%d\n", ans % p);
			}
			// for(int i = 1; i <= n; i++){
			// 	// cerr << t[i] << ' ' << d[i] << endl;
			// 	cerr << rnk[i] << ':' << queryT(i, i) << endl;
			// }
			printf("%d\n", ans % p);
		}
		else if (op == 3)
		{
			// cerr << 3;
			scanf("%d %d", &u, &w);
			v = btm[u];
			// cerr << "red:" << btm[u] << endl;
			addT(dfn[u], v, w);
		}
		else if (op == 4)
		{
			// cerr << 4;
			scanf("%d", &u);
			v = btm[u];
			// cerr << btm[u] << endl;
			// for(int i = 1; i <= n; i++){
			// 	// cerr << t[i] << ' ' << d[i] << endl;
			// 	cerr << rnk[i] << ':' << queryT(i, i) << endl;
			// }
			ll ans = queryT(dfn[u], v);
			// cerr << "a";
			printf("%d\n", 1ll * ans % p);
		}
	}
	return 0;
}