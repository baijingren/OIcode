#include<bits/stdc++.h>
using namespace std;
const int qwe = 500005;
const int mod = 80112002;
int n, m, cnt = 0, ans = 0;
int hd[qwe], f[qwe], b[qwe], o[qwe];
struct EDGE
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
queue<int> q;
int main()
{
	scanf("%d%d", &n, &m);
	int x, y;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		add(x, y);
		b[y]++;
		o[x]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == 0)
		{
			q.push(i);
			f[i]++;
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = hd[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			f[v] = (f[v] + f[u]) % mod;
			b[v]--;
			if(!b[v])
			{
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(o[i] == 0)
		{
			ans = (ans + f[i]) % mod;
		}
	}
	printf("%d", ans);
	return 0;
}
