#include <bits/stdc++.h>
using namespace std;
const int qwe = 3005;
int n, m;
int a[qwe];
int dpmn[qwe][qwe], dpmx[qwe][qwe], num[qwe][qwe];
int main()
{
    scanf("%d%d", &n, &m);
    memset(dpmn, 0x06, sizeof(dpmn));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        // s[i] = s[i - 1] + a[i];
    }
    int ans = INT_MIN, ansb = INT_MAX;
    for (int p = 0; p < n; p++)
    {
        // for (int i = 1; i <= 2 * n; i++)
        // {
        //     s[i] = s[i - 1] + a[i];
        // }
        for (int l = 1 + p; l <= n + p; l++)
        {
            for (int r = l; r <= n + p; r++)
            {
                num[l][r] = num[l][r - 1] + a[r];
                num[l][r] = num[l][r] % 10;
                if (num[l][r] < 0)
                {
                    num[l][r] += 10;
                }
            }
        }
        for(int i=1+p;i<=n+p;i++) dpmx[i][0]=dpmn[i][0]=num[1+p][i];
        for (int j = 1; j <= m; j++)
        {
            for (int i = j + 1 + p; i <= n + p; i++)
            {
                // if (j == 0)
                // {
                //     dpmn[i][j] = dpmx[i][j] = num[1][i];
                //     continue;
                // }
                for (int k = 1 + p; k < i; k++)
                {
                    dpmn[i][j] = min(dpmn[k][j - 1] * num[k + 1][i], dpmn[i][j]);
                    dpmx[i][j] = max(dpmx[k][j - 1] * num[k + 1][i], dpmx[i][j]);
                }
            }
        }
        ans = max(ans, dpmx[n + p][m - 1]);
        ansb = min(ansb, dpmn[n + p][m - 1]);
    }
    printf("%d\n%d", ansb, ans);
    return 0;
}