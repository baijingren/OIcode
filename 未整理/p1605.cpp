#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
bool map[15][15], a[15][15];//map为总地图，a记录是否访问
int n, m, d[5] = { -1,0,1,0,-1 }; 
int begx, begy, endx, endy, cnt;
int t, zx, zy;
void dfs(int x, int y)
{
	if (x == endx && y == endy)
	{
		cnt++;
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		int l = x + d[k]; int r = y + d[k + 1];
		if (l >= 1 && r >= 1 && l <= n && r <= m && !map[l][r] && !a[l][r])
		{
			a[l][r] = true;
			dfs(l, r);
			a[l][r] = false;
		}
	}
	return;
}
int main()
{
	cin >> n >> m >> t >> begx >> begy >> endx >> endy;
	map[begx][begy] = true;
	while (t--)
	{
		cin >> zx >> zy;
		map[zx][zy] = true;
	}
	dfs(begx, begy);
	printf("%d", cnt);
	return 0;
}