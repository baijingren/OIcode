#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
const int QWE = 1005;
int T, M;
int a[qwe], b[qwe];
int f[QWE][QWE];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &T, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &a[i + 1], &b[i + 1]);
    }
    f[0][0] = 0;
    for (int i = 0; i <= M; i++)
    {
        f[i][0] = 0;
    }
    for (int i = 0; i <= T; i++)
    {
        f[0][i] = -INT_MAX;
    }
    // for (int i = 0; i <= M; i++)
    // {
    //     f[i][0] = 0;
    // }
    // for (int i = 0; i <= T; i++)
    // {
    //     f[0][i] = 0;
    // }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j >= a[i])
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d", f[M][T]);
    return 0;
}