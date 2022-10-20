#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n;
// char sa[qwe], sb[qwe];
int sa[qwe], sb[qwe];
int f[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d ", &n);
    // scanf("%s", sa);
    // scanf("%s", sb);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sa[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sb[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (sa[i] == sb[j])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    printf("%d", f[n][n]);
    return 0;
}