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

class SegmentTree{
private:
	int t[qwe];
	void pushup(int rt){

	}
public:
	void build(int rt, int l, int r){
		if(l == r){
			t[rt] = w[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		pushup(rt);
		return;
	}
	void addPoint(int rt, int l, int r, int x, int w){

	}
	void addInterval(int rt, int l, int r, int L, int R, int w){

	}
	ll queryPoint(int rt, int l, int r, int x){

	}
	ll queryInterval(int rt, int l, int r, int L, int R){

	}
};

int s[qwe];
int main()
{
	scanf("%d %d %d %d", &n, &m, &r, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
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

	}
	for (int i = 1; i <= m; i++)
	{
		int op, u, v, w;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d %d %d", &u, &v, &w);
			int x = u, y = v;
			if(x == y){

				continue;
			}
			while (x != y)
			{
				if(top[x] == top[y]){
					if(dep[x] < dep[y]){
						swap(x, y);
					}
					for(; x != y;){

						x = fa[x];
					}

					break;
				}
				while (dep[x] > dep[y])
				{

					x = fa[top[x]];
				}
				while (dep[y] > dep[x])
				{

					y = fa[top[y]];
				}
				while (dep[x] == dep[y] && x != y)
				{
					
					x = fa[top[x]];

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
					}
					printf("%d\n", ans % p);
					break;
				}
				while (dep[x] > dep[y])
				{
					x = fa[top[x]];
				}
				while (dep[y] > dep[x])
				{
					y = fa[top[y]];
				}
				while (dep[x] == dep[y] && x != y)
				{
					x = fa[top[x]];
					y = fa[top[y]];
				}
			}
			if(x == y){
			}
			printf("%d\n", ans % p);
		}
		else if (op == 3)
		{
			scanf("%d %d", &u, &w);
			v = btm[u];
		}
		else if (op == 4)
		{
			scanf("%d", &u);
			v = btm[u];
			printf("%d\n", 1ll * ans % p);
		}
	}
	return 0;
}