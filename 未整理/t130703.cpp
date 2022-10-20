#include <bits/stdc++.h>
using namespace std;
const int qwe = 300005;
int m, n, a, b, fa[qwe], ans;
char s;
int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        fa[i + n] = i + n;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("\n%c %d %d", &s, &a, &b);
        int u = fnd(a), v = fnd(b);
        if (s == 'S')
        {
            if (u == fnd(b + n) || v == fnd(a + n))
            {
                printf("0");
                return 0;
            }
            fa[u] = v;
            fa[fnd(a + n)] = fnd(b + n);
        }
        if (s == 'D')
        {
            if (u == v || fnd(a + n) == fnd(b + n))
            {
                printf("0");
                return 0;
            }
            fa[u] = fnd(b + n);
            fa[v] = fnd(a + n);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
            ans++;
    }
    printf("1");
    for (int i = 1; i <= ans; i++)
    {
        printf("0");
    }
    return 0;
}