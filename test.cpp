#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], b[100005], c[100005], cnt = 0,mn,rec,aa,bb,cc;
long long main()
{
    scanf("%lld", &n);
    for (long long i = 1; i < n / 7 + 1; i++)
    {
        for (long long j = 1; j < (n-7*i) / 4 + 1; j++)
        {
            for (long long k = 1; k < (n-7*i-4*j) / 3 + 1; k++)
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

    long long mx=0;
    for (long long i = 0; i <= cnt; i++)
    {
        if (a[i]+b[i]+c[i]>mx)
        {
            mx = a[i] + b[i] + c[i];
            aa = a[i];
            bb = b[i];
            cc = c[i];
        }
    }
    printf("%lld %lld %lld", aa, bb, cc);
    return 0;
}