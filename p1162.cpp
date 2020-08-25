#include <bits/stdc++.h>
using namespace std;
int n, mp[40][40];
bool vis[40][40];
queue<int> qx, qy;
int xp[4] = {1, -1, 0, 0};
int yp[4] = {0, 0, 1, -1};
void bfs(int x, int y)
{
    qx.push(x);
    qy.push(y);
    vis[x][y] = true;
    int vx, vy, ux, uy;
    while (!qx.empty() && !qy.empty())
    {
        ux = qx.front(), uy = qy.front();
        for (int i = 0; i < 4; i++)
        {
            vx = ux + xp[i], vy = uy + yp[i];
            if (vx >= 0 && vy >= 0 && vx < n && vy < n && !vis[vx][vy])
            {
                qx.push(vx);
                qy.push(vy);
                vis[vx][vy] = true;
            }
        }
    }
    return;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 1)
            {
                vis[i][j] = true;
            }
        }
    }
    bfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] != true)
            {
                mp[i][j] = 2;
            }
            printf("%d ", mp[i][j]);
        }
    }
    return 0;
}