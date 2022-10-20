#include<bits/stdc++.h>
using namespace std;
const int pnt = 5005;
const int lne = 1000005;
int m, cnt=1, n;
int hd[lne], b[pnt];
int a[pnt][pnt];
bool vis[lne];
stack<int> s;
struct EDGE{
	int to,nxt;
}
void add(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=hd[u];
	hd[u]=cnt;
}
// void dfs(int x)
// {
// 	for(int i = 1; i <= n; i++)
// 	{
// 		if(a[x][i])
// 		{
// 			a[x][i]--;
// 			a[i][x]--;
// 			dfs(i);
// 		}
// 	}
// 	s.push(x);
// 	return;
// }
void dfs(int u){
	for(int i=hd[u];i;i=edge[cnt].nxt){
		int v=edge[cnt].to;
		if(vis[1]) continue;
		vis[i]=vis[i^1]=1;
		dfs(v);
	}
	s.push(u);
	return;
}
int main()
{
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		n = max(n, x);
		n = max(n, y);
		add(x,y);
		add(y,x);
		// a[x][y]++;
		// a[y][x]++;
		b[x]++;
		b[y]++;
	}
	int v = 1;
	for(int i = 1; i <= n; i++)
	{
		if(b[i] % 2 == 1)
		{
			v = i;
			break;
		}
	}
	dfs(v);
	while(!s.empty())
	{
		printf("%d\n", s.top());
		s.pop();
	}
	return 0;
}
