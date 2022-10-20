#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int D, G;
int dp[qwe];
struct A
{
    int t, f, h;
} a[qwe];
bool cmp(A x, A y)
{
    return x.t < y.t;
}
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d%d", &D, &G);
    for (int i = 1; i <= G; i++)
    {
        scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
    }
    sort(a + 1, a + G + 1, cmp);
    dp[0] = 10;
    for (int i = 1; i <= G; i++)
    {
        for (int j = D; j >= 0; j--) // i个垃圾，j高度，
        {
            if (dp[j] >= a[i].t)
            {
                if (j + a[i].h >= D)
                {
                    printf("%d", a[i].t);
                    return 0;
                }
                dp[j + a[i].h] = max(dp[j + a[i].h], dp[j]);
                dp[j] += a[i].f;
            }
        }
    }
    printf("%d", dp[0]);
    return 0;
}