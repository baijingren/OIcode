#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[10000005];
long long ans;
int jud(long long x)
{
    long long f=0,cnt=1;
    for (int i = 1; i <= n; i++)
    {
        if(f+a[i]<=x) f+=a[i];
        else
        {
            cnt++;
            f = a[i];
        }
    }
    return cnt;
}
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d",&n,&m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d",&a[i]);
        ans += a[i];
    }
    long long l=0,r=ans;
    while (l<r)
    {
        long long mid=(l+r)/2;
        if(jud(mid)>m) l=mid+1;
        else r=mid;
    }
    printf("%lld",l);
    return 0;
}