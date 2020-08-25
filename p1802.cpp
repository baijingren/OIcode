#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
long long dp[qwe];
int le[qwe], wn[qwe], ue[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &le[i], &wn[i], &ue[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= ue[i]; j--)
        {
            dp[j] = max(dp[j] + le[i], dp[j - ue[i]] + wn[i]);
        }
        for (int j = ue[i] - 1; j >= 0; j--)
        {
            dp[j] += le[i];
        }
    }
    printf("%lld", 5 * dp[m]);
    return 0;
}