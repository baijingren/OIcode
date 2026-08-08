#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, t;
int a[qwe], s[qwe];
int main()
{
    a[0] = INT_MIN;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = (a[i] ^ t);
    }
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int y = lower_bound(a + 1, a + n + 1, s[i]) - a;
        if (a[y] == s[i])
        {
            int z = upper_bound(a + 1, a + n + 1, s[i]) - a;
            ans += (z - y);
        }
    }
    printf("%d", ans);
    return 0;
}