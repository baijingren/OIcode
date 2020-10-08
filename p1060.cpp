#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n, m;
int a[qwe], w[qwe], dp[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a[i], &w[i]);
        w[i] *= a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= a[i]; j--)
        {
            // if (j >= a[i])
            // {
                dp[j] = max(dp[j], dp[j - a[i]] + w[i]);
            // }
        }
    }
    printf("%d", dp[n]);
    return 0;
}