#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, cnt;
int hd[qwe];
int a[qwe][qwe], dp[qwe];
struct Edge
{
    int to, nxt, w;
} edge[qwe];
void add(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    edge[cnt].w = w;
    hd[u] = cnt;
    return;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            // int s;
            scanf("%d", &a[i][j]);
            // // add(i, j, s);
            // a[i][j] = s;
            // s = 0;
            dp[i]=1e9;
        }
    }
    // memset(dp, 0x3f, sizeof(dp));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++) //从i到j的最小花费
        {
            dp[i] = min(dp[i], a[i][j] + dp[j]);
            // for (int k = i; k <= j; k++)
            // {
            //     dp[i][j] = max(dp[i][k], dp[k + 1][j]);
            // }
            // if (f[j]==0||f[j]>f[i]+x)
            //     f[j]=f[i]+x;
        }
    }
    printf("%d", dp[1]);
    return 0;
}