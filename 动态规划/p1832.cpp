#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, num = 0;
int dp[qwe], s[qwe];
bool a[qwe], v[qwe];
void sushu()
{
    memset(v, 1, sizeof(v));
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 1)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 1)
        {
            s[++num] = i;
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    sushu();
    dp[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = s[i];j <= n; j++)
        {
            dp[j] = dp[j] + dp[j - s[i]];
        }
    }
    printf("%d", dp[n]);
}