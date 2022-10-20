#include<bits/stdc++.h>
#define int long long
using namespace std;
const int qwe=1e5+5;
const int mod=999911659;
//2×3×4679×35617
int MD[]={2,3,4679,35617};
int n,g,cnt=0;
int a[qwe];
int t[qwe];
int I[qwe],_I[qwe];
int _pow(int x,int y,int md){
    long long b=x,c=1;
    while(y){
        if(y&1){
            c=(c*b)%md;
        }
        b=(b*b)%md;
        y>>=1;
    }
    return c%md;
}
int C(int x,int y,int md){
    if(y>x){
        return 0;
    }
    return I[x]*_I[y]%md*_I[x-y]%md;
}
int lucas(int x,int y,int md){
    if(y==0){
        return 1;
    }
    return lucas(x/md,y/md,md)*C(x%md,y%md,md)%md;
}
void init(int md){
    I[0]=1;
    for(int i=1;i<=md-1;i++){
        I[i]=I[i-1]*i%md;
    }
    _I[md]=0;_I[md-1]=_pow(I[md-1],md-2,md);
    for(int i=md-2;i>=0;--i){
        _I[i]=(_I[i+1]*(i+1))%md;
    }
}
int ans;
signed main(){
    scanf("%lld%lld",&n,&g);
    if(g%mod==0){
        printf("0");
        return 0;
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            t[++cnt]=i;
            if(i*i!=n){
                t[++cnt]=n/i;
            }
        }
    }
    for(int i=0;i<4;i++){
        init(MD[i]);
        for(int j=1;j<=cnt;j++){
            a[i]=(a[i]+lucas(n,t[j],MD[i])%MD[i])%MD[i];
        }
    }
    for(int i=0;i<4;i++){
        int k=(mod-1)/MD[i];
        int kk=_pow(k,MD[i]-2,MD[i]);
        ans+=(a[i]*k%(mod-1)*kk%(mod-1))%(mod-1);
        ans%=(mod-1);
    }
    printf("%lld",_pow(g,ans,mod));
}