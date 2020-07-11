#include <bits/stdc++.h>
using namespace std;
const int qwe = 10005;
struct Cty
{
    int nor, sou;
} cty[qwe];
int n, a[qwe], mp[qwe], f[qwe];
bool cmp(Cty x, Cty y)
{
    return x.nor < x.sou;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &cty[i].nor, &cty[i].sou);
        mp[cty[i].nor] = i;
        f[i] = 0x7fffffff;
    }
    sort(cty + 1, cty + n + 1, cmp);
    int len = 0;
    f[++len] = cty[1].sou;
    for (int i = 1; i <= n; i++)
    {
        if (cty[i].sou >= f[len])
        {
            f[++len] = cty[i].sou;
            continue;
        }
        int l = upper_bound(f + 1, f + len, cty[i].sou) - f;
        f[l] = cty[i].sou;
    }
    printf("%d", len);
    return 0;
}
