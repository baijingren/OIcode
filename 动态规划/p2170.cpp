#include<bits/stdc++.h>
using namespace std;
const int qwe = 100005;
int n, m, k, cnt, ans;
int s[qwe], f[qwe], t[qwe], dp[qwe];
int fnd(int x)
{
    if(f[x] == x)
    {
        return f[x];
    }
    return f[x] = fnd(f[x]);
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for(int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
    for (int i = 1; i <= k; i++)
    {
	    scanf("%d %d", &a, &b);
        int ua = fnd(a), ub = fnd(b);
        if(ua != ub)
        {
            f[ua] = f[ub];
        }
    }
    for(int i = 1; i <= n; i++)
    {
	    f[i]  = fnd(f[i]);
    }
	for(int i = 1; i<= n; i++)
	{
		t[f[i]]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(t[i])
		{
			s[++cnt] = t[i];
		}
	}
	dp[0] = 1;
	for(int i = 1; i <= cnt; i++)
	{
		for(int j = n - s[i]; j >= 0; j--)
		{
			if(dp[j])
			{
				dp[j + s[i]] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
    {
        if(dp[i] && abs(ans - m) > abs(i - m))
        {
        	ans=i;
        }
    }
    printf("%d",ans);
    return 0;
}
