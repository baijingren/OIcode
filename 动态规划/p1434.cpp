#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int R, C;
int a[qwe][qwe], f[qwe][qwe];
int mv[3][5] = {
    {0, 0, 0, 1, -1},
    {0, 1, -1, 0, 0}};
queue<int> qx, qy;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &R, &C);
    int mx = INT_MIN, mxx = 0, mxy = 0;
    int mn = INT_MAX, mnx = 0, mny = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > mx)
            {
                mx = a[i][j];
                mxx = i;
                mxy = j;
            }
            if (a[i][j] < mn)
            {
                mn = a[i][j];
                mnx = i;
                mny = j;
            }
        }
    }
    qx.push(mnx);
    qy.push(mny);
    f[mnx][mny] = 1;
    while (!qx.empty() && !qy.empty())
    {
        int ux = qx.front(), uy = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 1; i <= 4; i++)
        {
            int vx = ux + mv[0][i], vy = uy + mv[1][i];
            if (vx > 0 && vy > 0 && vx <= R && vy <= C)
            {
                if (a[ux][uy] < a[vx][vy])
                {
                    f[vx][vy] = max(f[vx][vy], f[ux][uy] + 1);
                    qx.push(vx);
                    qy.push(vy);
                }
            }
        }
    }
    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         for (int k = 1; k <= 4; k++)
    //         {
    //             if(a[i][j] < a[mv[0][k]][mv[1][k]])
    //             {
    //                 f[i][j] = max(f[i][j], f[mv[0][k]][mv[1][k]] + 1);
    //             }
    //         }
    //     }
    // }
    printf("%d", f[mxx][mxy]);
    return 0;
}