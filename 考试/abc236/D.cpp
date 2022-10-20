#include <bits/stdc++.h>
using namespace std;
int n;
int a[25][25];
bool vis[25];
int ans = 0;
void dfs(int x, int k)
{
    if (x == 2 * n + 1)
    {
        cout<<k<<' ';
        ans = max(ans, k);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            for (int j = 1; j <= 2 * n; j++)
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                    // k ^= a[i][j];
                    dfs(x+1, k^a[i][j]);
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n - i; j++)
        {
            if (i != j)
            {
                scanf("%d", &a[i][j]);
                a[j][i] = a[i][j];
            }
        }
    }
    dfs(1,0);
    printf("%d",ans);
    return 0;
}