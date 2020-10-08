#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n, m, A, b;
int a[qwe][qwe], v[qwe][qwe];
int mv[2][5] = {
	{0, 0, 0, 1, -1},
	{0, 1, -1, 0, 0}
};
bool vis[qwe][qwe];
struct PNT
{
	int x, y, id, t;
} bp[qwe];
queue<int> qx, qy;

int main()
{
	scanf("%d%d%d%d", &n, &m, &A, &b);
	int x, y;
	for(int i = 1; i <= A; i++)
	{
		scanf("%d%d", &x, &y);
		qx.push(x);
		qy.push(y);
		a[x][y] = 0;
		vis[x][y] = 1;
	}
	for(int i = 1; i <= b; i++)
	{
		scanf("%d%d", &bp[i].x, &bp[i].y);
		bp[i].id = i;
		v[bp[i].x][bp[i].y] = bp[i].id;
	}
	int bs = b;
	while(!qx.empty() && !qy.empty())
	{
		int ux = qx.front(), uy = qy.front();
		qx.pop(), qy.pop();
		for(int i = 1; i <= 4; i++)
		{
			int vx = ux + mv[0][i], vy = uy + mv[1][i];
			if(vx >= 0 && vy > 0 && vx <= n && vy <= n && !vis[vx][vy])
			{
				qx.push(vx);
				qy.push(vy);
				a[vx][vy] = a[ux][uy] + 1;
				vis[vx][vy] = 1;
				if(v[vx][vy])
				{
					bp[v[vx][vy]].t = a[vx][vy];
					bs--;
				}
			}
		}
	}
	for(int i = 1; i <= b; i++)
	{
		printf("%d\n", bp[i].t);
	}
	return 0;
}
