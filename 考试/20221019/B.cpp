#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e6 + 3;
ll n, m;
ll read()
{
    char c = getchar();
    ll x = 0, y = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            y = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x + c - '0';
        c = getchar();
    }
    return x * y;
}
ll pw(ll x, ll y)
{
    ll a = x, b = 1;
    while (y)
    {
        if (y & 1)
        {
            b = (b * a) % mod;
        }
        y >>= 1;
        a = (a * a) % mod;
    }
    return b;
}
int main()
{
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    // n = read();
    // m = read();
    cin>>n>>m;
    if (n <= 60 && (1ll << n) < m)
    {
        cout << "1 1\n";
        return 0;
    }
    ll tmp = pw(2, n % (mod - 1));
    ll a = 1, res = 0;
    ll b = 0;
    for (int i = 1; i < mod && i < m; i++)
    {
        a = a * (tmp + mod - i) % mod;
    }
    for (int i = 1; ((m - 1) >> i) > 0; i++)
    {
        res = (res + ((m - 1) >> i)) % (mod - 1);
    }
    if (m >= mod)
    {
        a = 0;
    }
    a = a * pw((mod + 1) >> 1, res) % mod;
    b = pw(2, (n % (mod - 1) * ((m - 1) % (mod - 1)) - res + mod - 1) % (mod - 1));
    cout << (b - a + mod) % mod << ' ' << b << '\n';
    return 0;
}