#include <bits/stdc++.h>
using namespace std;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
const int qwe = 305;
int n, m, T, cnt = 0, ans = 0;
bool vis[qwe][qwe];
int a[qwe][qwe];
int mv[2][8] = {
    {1, 1, 2, 2, -1, -1, -2, -2},
    {2, -2, -1, 1, -2, 2, -1, 1}};
pair<int, int> ma[qwe][qwe];
bool dfs(int ux, int uy)
{
    for (int k = 0; k < 8; k++)
    {
        int x = ux + mv[0][k], y = uy + mv[1][k];
        if (a[x][y] || x <= 0 || y <= 0 || x > n || y > m || vis[x][y])
            continue;
        vis[x][y] = 1;
        if (dfs(ma[x][y].first,ma[x][y].second) || (!ma[x][y].first && !ma[x][y].second))
        {
            ma[x][y] = make_pair(ux, uy);
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 1; i <= T; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] || (i + j) % 2)
                continue;
            memset(vis, 0, sizeof(vis));
            if (dfs(i, j))
            {
                ans++;
            }
        }
    }
    printf("%d\n", n * m - T - ans);
    return 0;
}