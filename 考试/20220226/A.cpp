#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cctype>
#include<climits>
#include<ctime>
#include<map>
using namespace std;
const int N=505,M=2e5+5;
int n,m,t;
int q[N];
long long ans=LLONG_MAX;
struct Node
{
    int a,b;
}s[N];
long long calc()
{
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&q[i]>0) sum+=t;
        sum+=1ll*s[i].a*q[i]+1ll*q[i]*(q[i]-1)/2*(2*q[i]-1)/3*s[i].b;
    }
    ans=min(ans,sum);
    return sum;
}
void sa()
{
    for(double T=1;T>=1e-8;T*=0.998)
    {
        int x=rand()%n+1,y=rand()%n+1,cntx,cnty;
        int now=calc();
        while(q[x]==0&&q[y]==0) x=rand()%n+1,y=rand()%n+1;
        if(q[y]==0) q[x]--,q[y]++,cntx=1,cnty=-1;
        else q[x]++,q[y]--,cntx=-1,cnty=1;
        int nxt=calc();
        int del=nxt-now;
        if(exp(-del/T)<(double)rand()/RAND_MAX) q[x]+=cntx,q[y]+=cnty;
    }
}
bool cmp(Node x,Node y)
{
    if(x.b==y.b) return x.a+x.b<y.a+y.b;
    return x.b<y.b;
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++) scanf("%d%d",&s[i].a,&s[i].b);
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++) q[i]=m/n;
    q[n]+=m-m/n*n;
    while((double)clock()/CLOCKS_PER_SEC<0.95) sa();
    printf("%lld\n",ans);
    return 0;
}