
#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n;
int a[qwe], dpf[qwe], dpb[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dpf[i] = max(dpf[i - 1] + a[i], a[i]);
    }
    // for (int i = n; i >= 1; i++)
    // {
    //     dpb[i] = max(dpb[i + 1] + a[i], a[i]);
    // }
    // printf("%d", dpf[n] + dpb[n]);
    int s = 0;
    int ans = INT_MIN, mx = INT_MIN;
    for (int i = n; i > 1; i--)
    {
        s = max(s + a[i], a[i]);
        mx = max(mx, s);
        if (ans < mx + dpf[i - 1])
        {
            ans = mx + dpf[i - 1];
        }
    }
    printf("%d", ans);
    return 0;
}