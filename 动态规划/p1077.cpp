#include <bits/stdc++.h>
using namespace std;
int n, m;
int md = 1000007;
const int qwe = 100005;
int dp[qwe], a[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= min(a[i], j); k++)
            {
                // dp[j] = max(dp[j], dp[j - k] + 1);
                dp[j] = dp[j] + dp[j - k];
                dp[j] = dp[j] % md;
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}