#include <bits/stdc++.h>
using namespace std;
int m, n;
int xp[4] = {1, -1, 0, 0};
int yp[4] = {0, 0, 1, -1};
int a[5005][5005],dis[5005][5005];
char s;
bool vis[5005][5005];
struct xy
{
    int x, y;
};
xy me, ed;
queue<int> qx, qy;
void bfs(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    qx.push(x);
    qy.push(y);
    vis[x][y] = true;
    dis[x][y] = 0;
    while (!qx.empty() && !qy.empty())
    {
        int ux = qx.front(), uy = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + xp[i], vy = uy + yp[i];
            if (vx>=0&&vy>=0&&vx<n&&vy<n&&!vis[vx][vy]&&a[vx][vy]!=1) {
                dis[vx][vy] = dis[ux][uy] + 1;
                qx.push(vx);
				qy.push(vy);
				vis[vx][vy] = true;
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &s);
            if (s == '*')
            {
                a[i][j] = 0;
            }
            if (s == '#')
            {
                a[i][j] = 1;
            }
            if (s == 'S')
            {
                me.x = i;
                me.y = j;
            }
            if (s == 'T')
            {
                ed.x = i;
                ed.y = j;
            }
        }
    }
    bfs(me.x, me.y);
    printf("%d",dis[ed.x][ed.y]);
    return 0;
}