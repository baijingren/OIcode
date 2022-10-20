#include <bits/stdc++.h>
using namespace std;
const int qwe = 2e5 + 5;
int n, ans;
int dp[qwe], d[qwe];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            y=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x*=10;
        x+=(ch-'0');
        ch=getchar();
    }
    return x*y;
}
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    // scanf("%d", &n);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        // scanf("%d", &d[i]);
        d[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (d[i] >= d[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(dp[i], ans);
    }
    for(int i=1;i<=n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(d[i]<=d[j]){
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(dp[i], ans);
    }
    printf("%d", n - ans);
}