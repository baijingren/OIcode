#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n;
int cnt[qwe], f[qwe];
int a[qwe][3];
int main()
{
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x][cnt[x]] = i;
        cnt[x]++;
    }
    // cout << 1;
    f[1] = a[1][1] + a[1][2];
    for (int i = 2; i <= n; i++)
    {
        int ans = INT_MAX;
        // cout << 2;
        for (int j = 1; j <= 2; j++)
        {
            for(int k = 1; k <= 2; k++)
            {
                ans = min(ans, abs(a[i][j] - a[i - 1][k]));
                cout << ans << endl;
                // cout << 3;
            }
        }
        f[i] = f[i - 1] + ans;
        // cout << 4;
    }
    printf("%d", f[n]);
    // cout << 5;
    return 0;
}
