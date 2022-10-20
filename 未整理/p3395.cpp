#include <bits/stdc++.h>
using namespace std;
const int qwe = 5005;
int T, n;
int a[qwe][qwe], mp[qwe][qwe];
int mv[2][5] = {
	{0, 0, 0, 1, -1},
	{0, 1, -1, 0, 0}};
bool vis[qwe][qwe];
struct PNT
{
	int x, y;
} A[qwe];
queue<int> qx, qy;
int main()
{
	scanf("%d", &T);
	for (int asd = 1; asd <= T; asd++)
	{
		memset(vis, 0, sizeof(vis));
		memset(mp, 0, sizeof(mp));
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n - 2; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			A[i].x = x;
			A[i].y = y;
		}
		qx.push(1);
		qy.push(1);
		vis[1][1] = 1;
		int v;
		while (!qx.empty() && !qy.empty())
		{
			int ux = qx.front(), uy = qy.front();
			qx.pop(), qy.pop();
			if (v == 0)
			{
				v = a[ux][uy];
			}
			v--;
			for (int i = 1; i <= 4; i++)
			{
				int vx = ux + mv[0][i], vy = uy + mv[1][i];
				if (vx > 0 && vy > 0 && vx <= n && vy <= n && !vis[vx][vy] && mp[vx][vy] == 0)
				{
					qx.push(vx);
					qy.push(vy);
					vis[vx][vy] = 1;
					a[vx][vy] = a[ux][uy] + 1;
				}
			}
			if (v == 0)
			{
				mp[A[a[ux][uy] + 1].x][A[a[ux][uy] + 1].y] = 1;
			}
		}
		if (vis[n][n] == 1)
		{
			printf("Yes\n");
			continue;
		}
		printf("No");
	}
	return 0;
}
