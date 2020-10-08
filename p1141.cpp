#include <bits/stdc++.h>
using namespace std;
const int pnt = 1005;
int n, m;
int s[1000005];
int a[pnt][pnt];
int mv[2][5] = {
    {0, 0, 0, 1, -1},
    {0, 1, -1, 0, 0}};
bool vis[pnt][pnt];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        int ans = 0;
        scanf("%d%d", &x, &y);
        if(vis[x][y])
        {
            printf("%d", s[vis[x][y]]);
            continue;
        }
        queue<int> qx, qy;
        qx.push(x);
        qy.push(y);
        vis[x][y] = i;
        while (!qx.empty() && !qy.empty())
        {
            int ux = qx.front(), uy = qy.front();
            qx.pop(), qy.pop();
            ans++;
            for (int i = 1; i <= 4; i++)
            {
                int vx = ux + mv[0][i], vy = uy + mv[1][i];
                if (vx > 0 && vy > 0 && vx <= n && vy <= n)
                {
                    if (a[ux][uy] != a[vx][vy] && !vis[vx][vy])
                    {
                        qx.push(vx);
                        qy.push(vy);
                        vis[vx][vy] = i;
                    }
                }
            }
        }
        printf("%d\n", ans);
        s[i] = ans;
    }
}