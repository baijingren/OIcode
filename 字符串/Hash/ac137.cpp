#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6 + 5;
const int mod = 92083;
int n, cnt = 0;
int sn[6], hd[qwe], nxt[qwe];
int hs[qwe][6];
int hash_(int *a)
{
    int cnr = 0, cny = 1;
    for (int i = 0; i < 6; i++)
    {
        cnr = (cnr + a[i]) % mod;
        cny = (ll)cny * a[i] % mod;
    }
    return (cnr + cny) % mod;
}
bool chk(int *x, int *y)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            bool v = 1;
            for (int k = 0; k < 6; k++)
            {
                if (x[(i + k) % 6] != y[(j + k) % 6])
                {
                    v = 0;
                    break;
                }
            }
            if (v)
            {
                return 1;
            }
            v = 1;
            for (int k = 0; k < 6; k++)
            {
                if (x[(i + k) % 6] != y[(j - k) % 6])
                {
                    v = 0;
                    break;
                }
            }
            if (v)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool insert(int *a)
{
    int ha = hash_(a);
    for (int i = hd[ha]; i; i = nxt[i])
    {
        if (chk(hs[i], a))
        {
            return 1;
        }
    }
    cnt++;
    memcpy(hs[cnt], a, 6 * sizeof(int));
    nxt[cnt] = hd[ha];
    hd[ha] = cnt;
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &sn[j]);
        }
        if (insert(sn))
        {
            printf("Twin snowflakes found.");
            return 0;
        }
    }
    printf("No two snowflakes are alike.");
    return 0;
}