#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define int long long
#define ll long long
int cnt1 = 1, cnt2 = 1;
ll n, ans = 1, m;
ll pw(int x, int y)
{
    int res = 1, tmp = x;
    while (y)
    {
        if (y & 1)
        {
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        y >>= 1;
    }
    return res%mod;
}
signed main()
{
    scanf("%lld", &n);
    if (n <= 3)
    {
        printf("%lld", n);
        return 0;
    }
    while (1)
    {
        // printf("%lld %lld %lld %lld\n",n,cnt1,m,cnt2);
        if (m != 0 && m <= 3)
            break;
        if(n<=3) break;
        ll k = n / 2;
        if (m == n + 1 || m == n - 1)
        {
            cnt1 = cnt1 * 2 + cnt2;
        }
        if (n % 2 == 0 && m == n + 1)
        {
            n = k;
            m = k + 1;
        }
        else if (n % 2 == 0 && m == n - 1)
        {
            n = k;
            m = k - 1;
        }
        else if (n % 2 == 0 && m == 0)
        {
            cnt1 *= 2;
            cnt2 = cnt1;
            n = k;
        }
        else if (n % 4 == 1)
        {
            n = k;
            m = k + 1;
        }
        else if (n % 4 == 3)
        {
            n = k + 1;
            m = k;
        }
        if (m != 0 && n % 2 == 1)
        {
            swap(n, m);
            swap(cnt1, cnt2);
        }
        cnt1 %= (mod-1);
        cnt2 %= (mod-1);
    }
    ans *= pw(n, cnt1);
    if (m != 0)
    {
        ans *= pw(m, cnt2);
        ans %= mod;
    }
    printf("%lld", ans % mod);
    return 0;
}