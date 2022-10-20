#include <bits/stdc++.h>
using namespace std;
const int qwe = 5e5 + 5;
int a[qwe];
int f[qwe][2];
int n, sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    // for (int l = 1; l <= n - i + 1; l++)
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            {
                f[i][(l - 1) % 2] = max(-f[i + 1][l % 2] + a[i], -f[i][l % 2] + a[i + l - 1]);
            }
        }
    }
    cout << (sum - f[1][(n - 1) % 2]) / 2 << ' ' << (sum + f[1][(n - 1) % 2]) / 2 << '\n';
    return 0;
}