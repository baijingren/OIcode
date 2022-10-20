#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n;
int a[qwe], f[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    int mx = INT_MIN;
    for (int i = 2; i < 2 * n; i++)
    {
        for (int j = i - 1; i - j < n && j >= 1; j--)
        {
            for (int k = j; k < i; k++)
            {
                f[j][i] = max(f[j][i], f[j][k] + f[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
            }
            if (f[j][i] > mx)
            {
                mx = f[j][i];
            }
        }
    }
    printf("%d", mx);
    return 0;
}