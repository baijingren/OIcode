#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n, p, cnt;
int b[qwe], c[qwe], u[qwe], hd[qwe], o[qwe];
bool vis[qwe];
bool v = false;
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
queue<int> q;
int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++)
	{
		o[i] = 0;
		scanf("%d%d", &c[i], &u[i]);
		if(c[i] >= 1)
		{
			q.push(i);
			vis[i] = 1;
		}
		else
		{
			c[i] = c[i] - u[i];
		}
	}
	int x, y, w;
	for(int i = 1; i <= p; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		o[x] = 1;
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(c[u] <= 0)
		{
			continue;
		}
		for(int i = hd[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			//b[v]--;
			//if(!b[v])
			//{
			//	q.push(v);
			//}
			c[v] += edge[i].w * c[u];
			if(!vis[v])
			{
				q.push(v);
				vis[v] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(c[i] > 0 && !o[i])
		{
			printf("%d %d\n", i, c[i]);
			v = 1;
		}
	}
	if(v == 0)
	{
		printf("NULL");
	}
	return 0;
}
