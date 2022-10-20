// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
// const int qwe=1005;
const int X=205,Y=3005;
const ll mod=998244353;
ll n,m,ans=1;
ll cnt[X];
ll f[X][Y],a[X][Y];
ll read(){
    char x=getchar();
    ll num=0,f=1;
    while(x<'0'||x>'9'){
        if(x=='-'){
            f=-1;
        }
        x=getchar();
    }
    while(x>='0'&&x<='9'){
        num*=10;
        num+=(x-'0');
        x=getchar();
    }
    return num*f;
}
int main(){
    // scanf("%lld%lld",&n,&m);
    n=read(),m=read(); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // scanf("%lld",&a[i][j]);
            a[i][j]=read();
            cnt[i]=(a[i][j]+cnt[i]+mod)%mod;
        }
        ans=(ans*(cnt[i]+1))%mod;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //     }
    // }
    //容斥（原理后期补上）
    ans=(ans+mod-1)%mod;
    for(int i=1;i<=m;i++){
        // f[i][j][k]前i行选j个节n点，当前列选k个节点
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int j=1;j<=n;j++){
            for(int k=0;k<=2*(j-1);k++){
                f[j][k]=(f[j][k]+f[j-1][k]*(cnt[j]-a[j][i]))%mod;
				f[j][k+1]=(f[j][k+1]+f[j-1][k])%mod;
				f[j][k+2]=(f[j][k+2]+f[j-1][k]*a[j][i])%mod;
            }
        }
        for(int j=n+1;j<=2*n;j++){
            ans=(ans-f[n][j]+mod)%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}