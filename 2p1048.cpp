#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int t, m;
int tim[qwe], wei[qwe];
int dp[qwe];
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &t, &m);
    for(int i = 1; i <= m; i++)
    {
      scanf("%d %d", &tim[i], &wei[i]);
    }
    dp[0] = 0;
    for(int i = 1; i <= m; i++)
    {
      for(int j = t; j >= 1; j--)
      {
        if(j - tim[i] >= 0)
        {
          dp[j] = max(dp[j], dp[j - tim[i]] + wei[i]);
        }
        else
        {
          dp[j] = dp[j];
        }
      }
    }
    printf("%d", dp[t]);
    return 0;
}
