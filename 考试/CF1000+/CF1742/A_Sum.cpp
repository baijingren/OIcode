#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans, mx;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        ans = a + b + c;
        mx = max(a, max(b, c));
        if (ans - mx == mx)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}