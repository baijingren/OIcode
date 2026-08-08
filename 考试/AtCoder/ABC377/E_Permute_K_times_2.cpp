#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
ll m;
int n;
int vis[qwe];
int a[qwe], b[qwe], p[qwe];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            break;
        }
        if (i == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    memcpy(p, a, (n + 1) * sizeof(int));
    for (int i = 1; i <= m - (m % 2); i+=2)
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[a[i]];
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != a[i])
            {
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = b[b[i]];
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != b[i])
            {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}