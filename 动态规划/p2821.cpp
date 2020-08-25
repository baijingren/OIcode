#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    int ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
    printf("%d", ans);
    return 0;
}