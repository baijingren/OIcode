#include<bits/stdc++.h>
using namespace std;
const int qwe = 105;
int n, m, ans = 0;
int a[qwe][qwe];
int mv[2][5] = {
	{0, 0, 0, 1, -1},
	{0, 1, -1, 0, 0}
};
bool vis[qwe][qwe];
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
			if(vx > 0 && vy > 0 && vx <= n && vy <= m)
			{
				/*
				if(a[vx][vy] && ! vis[vx][vy])
				{
					qx.push(vx);
					qy.push(vy);
					vis[vx][vy] = 1;
				}
				*/
				if(a[vx][vy] != 0)
				{
					qx.push(vx);
					qy.push(vy);
					a[vx][vy] = 0;
					vis[vx][vy] = 1;
				}
				
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= m; j++)
		{
			/*
			int c;
			scanf("%d", &c);
			if(c != 0)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
			*/
			scanf("%1d", &a[i][j]);
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
				/*
				for(int q = 1; q <= n; q++)
				{
					for(int w = 1; w <= m; w++)
					{
						printf("%d",a[q][w]);
					}
					printf("\n");
				}
				cout << endl << endl;
				*/
			}
		}
	}
	printf("%d", ans);
	return 0;
}
