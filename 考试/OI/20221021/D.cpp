#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
const int B = 131;
const int mod = 1e9 + 7;
int Q;
int n, m;
char a[qwe], b[qwe];
ll hsa[qwe], hsb[qwe];
ll f[qwe], g[qwe];
ll ta[qwe], tb[qwe];
ll pw[qwe];
void init()
{
    pw[0] = 1;
    for (int i = 1; i < qwe; i++)
    {
        pw[i] = (1ll * pw[i - 1] * B) % mod;
    }
    // n = a.length(), m = b.length();
    n = strlen(a + 1);
    m = strlen(b + 1);
    reverse(b + 1, b + m + 1);
    hsa[0] = 1;
    hsb[0] = 1;
    ta[n + 1] = 1;
    tb[m + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        hsa[i] = (1ll * hsa[i - 1] * B + (a[i] - 'a' + 1)) % mod;
    }
    for (int i = 1; i <= m; i++)
    {
        hsb[i] = (1ll * hsb[i - 1] * B + (b[i] - 'a' + 1)) % mod;
    }
    for (int i = n; i >= 1; i--)
    {
        ta[i] = (1ll * ta[i + 1] * B + (a[i] - 'a' + 1)) % mod;
    }
    for (int i = m; i >= 1; i--)
    {
        tb[i] = (1ll * tb[i + 1] * B + (b[i] - 'a' + 1)) % mod;
    }
}
int calh(ll hs[], int l, int r)
{
    return (hs[r] + mod - (1ll * hs[l - 1] * pw[r - l + 1]) % mod) % mod;
}
int calt(ll t[], int l, int r)
{
    return (t[l] + mod - (1ll * t[r + 1] * pw[r - l + 1]) % mod) % mod;
}
int main()
{
    freopen("palindrome.in", "r", stdin);
    freopen("palindrome.out", "w", stdout);
    scanf("%*s %s %s", a + 1, b + 1);
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < i + 2; j++)
        {
            int l = 0, r = min(i, n - j + 1);
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (calh(hsa, i - mid, j + mid) == calt(ta, i - mid, j + mid))
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            f[i - l + 1]++;
            f[i + 1]--;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j < i + 2; j++)
        {
            int l = 0, r = min(i, m - j + 1);
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (calh(hsb, i - mid, j + mid) == calt(tb, i - mid, j + mid))
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            g[i - l + 1]++;
            g[i + 1]--;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        f[i + 1] += f[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        g[i + 1] += g[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        f[i + 1] += f[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        g[i + 1] += g[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = 0, r = min(n - x, m - y)+1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (calh(hsa, x, x + mid) == calh(hsb, y, y + mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        cout << l + f[x + l] - f[x] + g[y + l] - g[y] << '\n';
        // cerr << l + f[x + l] - f[x] + g[y + l] - g[y] << '\n';
    }
    return 0;
}