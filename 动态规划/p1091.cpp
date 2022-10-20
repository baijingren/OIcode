#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n;
int a[qwe], lo[qwe], dp[qwe], dpb[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum = 1;
    int sumb = 1;
    lo[1] = a[1];
    dp[1] = 1;
    // topa = 1;
    // topb = 1;
    // da[1] = a[1];
    // ba[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // if (lo[sum] < a[i])
        // {
        //     sum++;
        //     lo[sum] = a[i];
        //     continue;
        // }
        // int l = 0, r = sum;
        // while (l < r)
        // {
        //     int mid  = (l + r) / 2;
        //     if (lo[mid] > a[i])
        //     {
        //         r = mid;
        //     }
        //     else
        //     {
        //         l = mid + 1;
        //     }
        // }
        // lo[l] = a[i];
        // dp[i] = sum;
        int pos = lower_bound(lo + 1, lo + sum + 1, a[i]) - lo;
        lo[pos] = a[i];
        if (pos > sum)
        {
            sum++;
        }
        dp[i] = sum;
        // pos = lower_bound(da + 1, da + topa + 1, a[j]) - da;
        // da[pos] = a[j];
        // if (pos > topa)
        // {
        //     topa++;
        // }
        // ba[j] = topa;
    }
    // cout << sum;
    // memset(lo, 0, sizeof(lo));
    int lon[qwe];
    lon[1] = a[n];
    dpb[n] = 1;
    // lo[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        // if (lon[sum] < a[i])
        // {
        //     sum++;
        //     lon[sum] = a[i];
        //     continue;
        // }
        // int l = 0, r = sum;
        // while (l < r)
        // {
        //     int mid  = (l + r) / 2;
        //     if (lon[mid] > a[i])
        //     {
        //         r = mid;
        //     }
        //     else
        //     {
        //         l = mid + 1;
        //     }
        // }
        // lon[l] = a[i];
        // dpb[i] = sum;
        int pos = lower_bound(lon + 1, lon + sumb + 1, a[i]) - lon;
        lon[pos] = a[i];
        if (pos > sumb)
        {
            sumb++;
        }
        dpb[i] = sumb;
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
    { 
        cout << ans <<' ';
      ans = max(dp[i] + dpb[i], ans);
      cout << i << ' ' << dp[i] << ' ' << dpb[i]  << ' ' << ans << endl;
    }
    printf("%d", n - ans + 1);
    return 0;
}
