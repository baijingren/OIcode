#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
char s[qwe], ss[qwe];
int dp[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i <= n; i++)
    {
        ss[n - i + 1] = s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i] == ss[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", n - dp[n][n]);
}