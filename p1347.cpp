#include<bits/stdc++.h>
using namespace std;
const int pnt = 105;
const int lne = 1000005;
int n, m;
int b[pnt], o[pnt], hd[lne];
struct EDGE
{
	int to, nxt;
} edge[lne];
void add(int u, int v)
{
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = hd[u];
	hd[u] = cnt;
	return;
}
queue<int> q;
int main()
{
	scanf("%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		add(x, y);
		b[y]++;
		o[x]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = hd[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			b[v]--;
			if(!b[v])
			{
				q.push(v);
			}
		}
	}
	return 0;
}
