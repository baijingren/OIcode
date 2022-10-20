#include <bits/stdc++.h>
using namespace std;
const int qwe = 100005;
int v, n, c;
int vv[qwe], f[qwe], cc[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d%d", &v, &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &vv[i + 1], &cc[i + 1]);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= 1; j--)
        {
            if (j >= cc[i])
            {
                f[j] = max(f[j], f[j - cc[i]] + vv[i]);
            }
            if (f[j] >= v)
            {
                ans = min(ans, j);
            }
        }
    }
    if (f[c] >= v)
    {
        printf("%d", c - ans);
    }
    else
    {
        printf("Impossible");
    }

    return 0;
}