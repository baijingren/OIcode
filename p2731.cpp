#include<bits/stdc++.h>
using namespace std;
const int pnt = 5005;
const int lne = 1000005;
int m, cnt, n;
int hd[lne], b[pnt];
int a[pnt][pnt];
stack<int> s;
void dfs(int x)
{
	for(int i = 1; i <= n; i++)
	{
		if(a[x][i])
		{
			a[x][i]--;
			a[i][x]--;
			dfs(i);
		}
	}
	s.push(x);
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
		a[x][y]++;
		a[y][x]++;
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
