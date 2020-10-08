#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int m, n, gp = -1, G;
int a[qwe], w[qwe], num[qwe];
int dp[qwe], g[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for (int i = 1;i <= n; i++)
    {
        scanf("%d %d %d", &a[i], &w[i], &G);
        gp = max(G, gp);
        num[G]++;
        g[G][num[G]] = i;
    }
    for (int i = 1; i <= gp; i++)
    {
        for (int j = m;j >= 0; j--)//背包容量
        {
            for (int k = 1; k <= num[i]; k++)//小组物品
            {
                if(j>=a[g[i][k]])
                {
                    dp[j] = max(dp[j], dp[j - a[g[i][k]]] + w[g[i][k]]);
                }
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}