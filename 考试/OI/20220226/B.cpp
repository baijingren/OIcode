#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int t,n;
long long power(long long b,long long p,long long mod)
{
    long long mul=1;
    while(p)
    {
        if(p&1) mul=mul*b%mod;
        p>>=1;
        b=b*b%mod;
    }
    return mul;
}
long long a[N],b[N],p[N];
map<int,int> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]),mp[p[i]]=-1;
        for(int i=1;i<=n;i++)
        {
            long long mul=1,sum=((p[i]-b[1])%p[i]+p[i])%p[i];
            for(int j=1;j<=i;j++) mul=mul*a[j]%p[i];
            for(int j=2;j<=i;j++) sum=((sum*a[j]%p[i]-b[j]%p[i])%p[i]+p[i])%p[i];
            if(sum!=0&&mul==0)
            {
                flag=1;
                break;
            }
            if(sum==0&&mul==0) continue;
            sum=sum*power(mul,p[i]-2,p[i])%p[i];//a[2]a[1]f[0]-p[2]q[2]=-a[2]b[1]-b[2]-->f[0]=(-a[2]b[1]-b[2])/(a[2]a[1])(mod p[2])
            if(mp[p[i]]==-1) mp[p[i]]=sum;
            else if(mp[p[i]]!=sum)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) printf("No\n");
        else printf("Yes\n");
    }
}
/*
a[1]f[0]+b[1]=p[1]q[1]
a[2]f[1]+b[2]=p[2]q[2]-->a[2](a[1]f[0]+b[1])+b[2]=p[2]q[2]-->a[2]a[1]f[0]-p[2]q[2]=-a[2]b[1]-b[2]
...
裴蜀定理判断是否有整数解
完（笑）
*/