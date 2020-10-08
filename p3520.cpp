#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n, m, cnt, cntt;
int hd[qwe], b[qwe], f[qwe], s[qwe];
bool vis[qwe];
struct EDGE
{
	int to, nxt;
} edge[qwe];
void add(int u, int v)
{
	cnt++;
	edge[cnt].nxt = hd[u];
	edge[cnt].to = v;
	hd[u] = cnt;
	return;
}
void dfs(int x, int y)
{
	//s.push(x);
	cntt++;
	s[cntt] = x;
	b[x] = b[x] - 2;
	cout<<1;
	for(int i = hd[x]; i; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(vis[i])
		{
			continue;
		}
		vis[i] = 1;
		vis[i ^ 1] = 1;
		if(v == y)
		{
			cntt++;
	//		s.push(y);
			s[cntt] = y;
			return;
		}
		dfs(v, y);
		return;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y, a, c;
		scanf("%d %d %d %d", &x, &y, &a, &c);
		if(a == c)
		{
			continue;
		}
		add(x, y);
		add(y, x);
		b[x]++;
		b[y]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] % 2 == 1)
		{
			printf("NIE");
			return 0;
		}
	}
	int v = 0;
	for(int i = 1; i <= n; i++)
	{
		while(b[i])
		{
			dfs(i, i);
			v++;
			f[v] = cntt;
		}
	}
	cout<<1;
	int j = 1;
	printf("%d", v);
	for(int i = 1; i <= v; i++)
	{
		printf("%d ", f[i] - f[i - 1] - 1);
		for(;j <= f[i]; j++)
		{
	//		int h =s.top();
	//		s.pop();
	//		printf("%d ", h);
			printf("%d ", s[j]);
		}
		printf("\n");
	}
	return 0;
}
