#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005], c[100005], cnt = 0,mn,rec,aa,bb,cc;
int main()
{
    freopen("order.in", "r", stdin);
    freopen("order.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n / 7 + 1; i++)
    {
        for (int j = 1; j < (n-7*i) / 4 + 1; j++)
        {
            for (int k = 1; k < (n-7*i-4*j) / 3 + 1; k++)
            {
                if (i * 7 + j * 4 + k * 3 == n)
                {
                    rec = min(i, j);
                    rec = min(rec, k);
                    if (mn > rec)
                    {
                        continue;
                    }
                    mn = rec;
                    cnt++;
                    a[cnt] = i;
                    b[cnt] = j;
                    c[cnt] = k;
                }
            }
        }
    }
    if (cnt==0)
    {
        printf("-1");
        return 0;
    }

    int mx=0;
    for (int i = 0; i <= cnt; i++)
    {
        if (a[i]+b[i]+c[i]>mx)
        {
            mx = a[i] + b[i] + c[i];
            aa = a[i];
            bb = b[i];
            cc = c[i];
        }
    }
    printf("%d %d %d", aa, bb, cc);
    return 0;
}