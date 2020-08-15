#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n;
int a[qwe];
int dp[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // cout<<1;
    }
    for(int i = 1;i <= n; i++)//区间
    { 
        // for(int j = 1; )
        // dp[i][j] = dp[i - 1][j] + a[j] * i;
        // dp[i] = a[j];
        // dp[1][i] = a[i];
        // dp[i] = max(a[i] * i, a[n - i] * i);
        // cout<<2;
        for(int  j = 0; j <= i; j++)//开头
        {
            // cout<<3;
            int l = i - j;
            dp[i][j] = max(dp[i - 1][j] + a[n - l + 1] * i, dp[i - 1][j - 1] + a[j] * i);
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    printf ("%d", ans);
}