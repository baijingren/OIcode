#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    __int128 ans = ((__int128)1) * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
    // printf("%d", ans);
    cout<<format("{}\n", ans);
    return 0;
}