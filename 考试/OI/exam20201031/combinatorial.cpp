#include<bits/stdc++.h>
using namespace std;
int t, k;
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    // freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d%d", &t, &k);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &m, &n);
        // if(n == m)
        // {
        //     printf("1");
        //     continue;
        // }
        int ma = m;
        if (m >= n / 2)
        {
            ma = n - m;
        }
        if(k <= ma)
        {
            printf("%d\n", k - ma);
            continue;
        }
        for(int i = 1; i <= ma; i++)
        {
            if(k % i == 0 && i != 1)
            {
                k /= i;
            }
            if(k == 1)
            {
                printf("%d", m - i);
                continue;
            }
        }
        printf("0");
    }
    return 0;
}
