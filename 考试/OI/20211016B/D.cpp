#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e4 + 5;
int n, ans, m;
int dp[qwe][qwe][3], d[qwe];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    dp[1][1][0] = 0;
    dp[1][1][1] = d[1];
    for (int i = 1; i <= n; i++) {
        // dp[0][0]=dp[1][0];
        dp[i][0][0] = max(max(dp[i - 1][1][1], dp[i - 1][1][0]), dp[i - 1][0][0]);
        dp[i][1][0] = max(dp[i - 1][2][0], dp[i - 1][2][1]);
        // dp[0][1]=
        dp[i][1][1] = dp[i - 1][0][0] + d[i];
        // for (int j = 2; j <= m; j++)
        for (int j = m; j >= 2; j--) {
            dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
            dp[i][j][1] = dp[i - 1][j - 1][1] + d[i];
        }
    }
    printf("%d", dp[n][0][0]);
}