#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int G, v, n;
int dp[qwe][qwe], wei[qwe], ka[qwe], a[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &G, &v);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
      scanf("%d %d %d", &a[i], &wei[i], &ka[i]);
    }
    for(int i = 1; i <= n; i++)
    {
      for(int j = G; j >= a[i]; j--)
      {
        for(int k  = v; k >= wei[i]; k--)
        {
          if(j >= a[i] && k >= wei[i])
          {
            dp[j][k] = max(dp[j][k], dp[j - a[i]][k - wei[i]] + ka[i]);
          }
        }
      }
    }
    printf("%d", dp[G][v]);
}
