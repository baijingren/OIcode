#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n, m, ans = 0;
int a[qwe][qwe];
int mv[2][5] = {
	{0, 0, 0, 1, -1},
	{0, 1, -1, 0, 0}
};
bool vis[qwe][qwe];
bool chk(int x, int y)
{
	int c=0;
	if(a[x][y]==1)c++;
	if(a[x+1][y]==1)c++;
	if(a[x][y+1]==1)c++;
	if(a[x+1][y+1]==1)c++;
		// cout << x << ' ' << y << ' ' << c << endl;
	if(c == 3)
	{
		return true;
	}
	return false;
}
void bfs(int x, int y)
{
	queue<int> qx, qy;
	qx.push(x);
	qy.push(y);
	vis[x][y] = 1;
	while(!qx.empty() && !qy.empty())
	{
		int ux = qx.front(), uy = qy.front();
		qx.pop(), qy.pop();
		for(int i = 1; i <= 4; i++)
		{
			int vx = ux + mv[0][i], vy = uy + mv[1][i];
			if(vx <= n && vy <= m && vx >= 0 && vy >= 0 && !vis[vx][vy] && a[vx][vy] == 1)
			{
				vis[vx][vy] = 1;
				qx.push(vx);
				qy.push(vy);
				a[vx][vy] = 0;
			}
		}
	}

}
int main()
{
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	scanf("%d%d ", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char c;
			scanf("%c", &c);
			if(c == '.')
			{
				a[i][j] = 0;
			}
			else if(c == '#')
			{
				a[i][j] = 1;
			}
		}
		scanf(" ");
	}
	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1;j <= m ;j++)
	// 	{
	// 		printf("%d ", a[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(chk(i, j))
			{
				// cout << i << ' ' << j << endl;
				// cout << a[i][j] << ' ' << a[i][j + 1] << ' ' << a[i + 1][j] << ' ' << a[i + 1][j + 1] << endl;
				printf("Bad placement.");
				return 0;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!vis[i][j] && a[i][j])
			{
				bfs(i, j);
				ans++;
				// cout << i << ' ' << j;
			}
		}
	}
	printf("There are %d ships.\n", ans);
	return 0;
}