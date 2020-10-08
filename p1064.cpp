#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
int mv[qwe], mp[qwe], av[qwe][3], ap[qwe][3], f[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    int v, p, q;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &v, &p, &q);
        if (!q)
        {
            mv[i] = v;
            mp[i] = v * p;
        }
        else
        {
            av[q][0]++;
            av[q][av[q][0]] = v;
            ap[q][av[q][0]] = v * p;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; mv[i] != 0 && j >= mv[i]; j--)
        {
            f[j] = max(f[j], f[j - mv[i]] + mp[i]);
            if (j >= mv[i] + av[i][1])
            {
                f[j] = max(f[j], f[j - mv[i] - av[i][1]] + mp[i] + ap[i][1]);
            }
            if (j >= mv[i] + av[i][2])
            {
                f[j] = max(f[j], f[j - mv[i] - av[i][2]] + mp[i] + ap[i][2]);
            }
            if (j >= mv[i] + av[i][1] + av[i][2])
            {
                f[j] = max(f[j], f[j - mv[i] - av[i][1] - av[i][2]] + mp[i] + ap[i][1] + ap[i][2]);
            }
        }
    }
    printf("%d", f[n]);
}