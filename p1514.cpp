#include<bits/stdc++.h>
using namespace std;
int main()
{
	scanf("%d %d", &n,&m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[1][i] == 0)
		{
			bfs(1, i);
		}
	}
	bool v = false;
	for(int i = 1; i <= n; i++)
	{
		if(vis[n][i] == 0)
		{
			cnt++;
		}
	}
	if(v == false)
	{
		printf("0\n%d", cnt);
		return 0;
	}
	int l = 1;
	while(l <= m)
	{
		int mx = 0;
		for(int i = 1; i <= m ; i++)
		{
			if(b[1][i] <= l)
			{
				mx = max(mx, c[1][i]);
			}
		}
	}
