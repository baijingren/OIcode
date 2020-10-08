#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
int a[qwe], dp[qwe], b[5][qwe];
// int dp[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[1][i] = b[1][i - 1];
        b[2][i] = b[2][i - 1];
        if (a[i] == 1)
        {
            b[1][i]++;
        }
        else
        {
            b[2][i]++;
        }
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        // for (int j = 1; j <= i; j++)
        for (int j = 0; j < i; j++)
        {
            if (abs((b[1][i] - b[1][j]) - (b[2][i] - b[2][j])) <= m || b[1][i] - b[1][j] == 0 || b[2][i] - b[2][j] == 0)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d", dp[n]);
    return 0;
}