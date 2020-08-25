#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m, c;
int dp[qwe];
int a[qwe][qwe], s[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    long long mx = INT_MIN;
    long long px = 1, py = 1;
    for (int i = c; i <= n; i++)
    {
        for (int j = c; j <= m; j++)
        {
            if (s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c] > mx)
            {
                mx = s[i][j] + s[i - c][j - c] - s[i - c][j] - s[i][j - c];
                px = i - c + 1, py = j - c + 1;
            }
        }
    }
    printf("%lld %lld", px, py);
    return 0;
}