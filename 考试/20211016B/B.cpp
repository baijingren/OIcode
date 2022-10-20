#include <bits/stdc++.h>
using namespace std;
const int qwe = 3e3 + 5;
int n,M;
int m[qwe], s[qwe];
int dp[qwe];
int main()
{
    scanf("%d%d", &n,&M);
    s[0] = M;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m[i]);
        s[i] = s[i - 1] + m[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i - j] + s[j], dp[i]);
        }
        dp[i] += M;
    }
    printf("%d", dp[n]-M);
}