#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
const int QWE = 1005;
int n, m;
int a[qwe], b[qwe];
int f[QWE][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i + 1]);
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 1;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     f[0][i] = 0;
    // }
    // for (int i = 0; i <= m; i++)
    // {
    //     f[i][0] = 0;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     f[0][i] = 0;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= a[i])
            {
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d", f[n][m]);
    return 0;
}