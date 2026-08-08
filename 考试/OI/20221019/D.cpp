#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
const int mod = 1e9 + 7;
int m, Q, n;
ll a[qwe];
ll f[qwe];
ll inv[qwe];
void dfs(ll x, ll y, ll pre, ll cnt, ll ml)
{
    a[x] = (a[x] + ml) % mod;
    if (x == 22)
    {
        return;
    }
    if(y*pre>m){
        return;
    }
    dfs(x + 1, y * pre, pre, cnt + 1, ml * inv[cnt + 1] % mod);
    for (ll i = pre + 1; y * i <= m; i++)
    {
        dfs(x + 1, y * i, i, 1, ml);
    }
}
ll pw(ll x, ll y)
{
    int b = 1;
    while (y)
    {
        if (y & 1)
        {
            b = (b * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return b;
}
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> Q;
    for (int i = 1; i <= 25; i++)
    {
        inv[i] = pw(i, mod - 2);
    }
    dfs(0, 1, 2, 0, 1);
    for (int i = 1; i <= Q; i++)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "0\n";
            continue;
        }
        ll ans = -1;
        ll cur = 1;
        for (int j = 0; j <= 22; j++)
        {
            cur = (cur * (n - j + 1) % mod) % mod;
            ans = (ans + (cur * a[j] % mod * inv[j + 1] % mod)) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}