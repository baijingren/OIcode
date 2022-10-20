#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int Mod = 998244353;
ll n, T;
ll fpow(int x, int p)
{
    ll tmp = x;
    ll ans = 1;
    while (p)
    {
        if (p & 1)
        {
            // ans *= tmp;
            ans = (ans * tmp) % Mod;
            // cout << endl
            //      << ans << endl;
        }
        // tmp *= tmp;
        tmp = (tmp * tmp) % Mod;
        p >>= 1;
    }
    return ans % Mod;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        // printf("%lld\n", (fpow(2, n - 1) % Mod * (n - 1) % Mod * n % Mod) % Mod);
        
    }
}