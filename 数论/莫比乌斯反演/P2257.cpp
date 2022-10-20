#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e7+5;
// const int qwe=1e6+5;
int n,m,T;
ll ans;
int v[N],mu[N],p[N],f[N],vis[N],sum[N];
int cnt=0;
void mp(){
    mu[1]=1;
    for(int i=2;i<=(N-5)/2;i++){
        if(v[i]==0){
            // v[i]=i;
            p[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt && i*p[j]<=((N-5)/2);j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                break;
            }
            mu[i*p[j]]=-mu[i];
        }
    }
    return;
}
void init(){
    for(int i=1;i<=cnt;i++){
        for(int j=1;j*p[i]<=(N-5)/2;j++){
            f[j*p[i]]+=mu[j];
        }
    }
    for(int i=1;i<=(N-5)/2;i++){
        sum[i]=sum[i-1]+f[i];
    }
    return;
}
int main(){
    scanf("%d",&T);
    mp();
    init();
    while(T--){
        ans=0;
        scanf("%d%d",&n,&m);
        // for(int t=1;t<=n;t++){
            // ans+=(n/t)*(m/t)*f[t];
        // }
        for(int l=1,r=0;l<=min(n,m);l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(ll)(sum[r]-sum[l-1])*(ll)(n/l)*(ll)(m/l);
        }
        printf("%lld\n",ans);
    }
    return 0;
}