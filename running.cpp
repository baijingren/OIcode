#include <bits/stdc++.h>
using namespace std;
int n, q, cnt;
void dfs(int x, int y, int z)
{
    if (y == n)
    {
        cnt++;
        return;
    }
    if (y > n)
    {
        return;
    }
    if (x == n + 1)
    {
        return;
    }    
    for (int i = n; i >= 1; i--)
    {
        if (i > z)
        {
            continue;
        }
        // rec[x][cnt]=i;
        dfs(x + 1, y + i, i);
    }
}
int main()
{
    freopen("running.in", "r", stdin);
    freopen("running.out", "w", stdout);
    scanf("%d %d", &n, &q);
    dfs(1, 0, 0x3f3f3f3f);
    printf("%d\n", cnt % q % (int(1e9) + 7));
    // for (int i = 0; i < cnt; i++)
    // {
    //     for (int j = 1; j<= n; j++)
    //     {
    //         printf("%d ", rec[j][i]);
    //     }
    //     printf("\n");
    // }
    return 0;
}