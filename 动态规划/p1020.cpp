#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n;
int a[qwe], b[qwe], le[qwe], len[qwe], dpa[qwe], dpb[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    // scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    // {
    //     scanf("%d %d", &a[i], &b[i]);
    // }
    n = 1;
    while (scanf("%d", &a[n]) != EOF)
    {
        n++;
    }
    n--;
    int sum = 1;
    int sumb = 1;
    le[1] = a[1];
    len[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (le[sum] >= a[i])
        {
            le[++sum] = a[i];
        }
        else
        {
            int p1 = upper_bound(le + 1, le + 1 + sum, a[i], greater<int>()) - le;
            le[p1] = a[i];
        }
        if (len[sumb] < a[i])
        {
            len[++sumb] = a[i];
        }
        else
        {
            int p2 = lower_bound(len + 1, len + 1 + sumb, a[i]) - len;
            len[p2] = a[i];
        }
    }
    printf("%d\n%d", sum, sumb);
    return 0;
}