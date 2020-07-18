#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int a[qwe], m, n;
int f[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    printf("%d", m-f[m]);
    return 0;
}