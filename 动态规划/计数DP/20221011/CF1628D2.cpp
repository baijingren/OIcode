#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=1e9+7;
#define ll long long
ll n,m,k;
int T;
ll a[qwe],b[qwe];
ll dp[qwe];
ll pw(ll x,ll y){
    ll a=1,c=x;
    while(y){
        if(y&1){
            a=(a*c)%mod;
        }
        c=(c*c)%mod;
        y>>=1;
    }
    return a;
}
ll C(ll x,ll y){
    if(x<y || x<0 || y<0){
        return 0;
    }
    return ((a[x]*b[y])%mod*b[x-y])%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n>>m>>k;
        a[0]=1;
        for(ll i=1;i<=n;i++){
            a[i]=a[i-1]*i%mod;
        }
        b[n]=pw(a[n],mod-2);
        b[0]=1;
        for(ll i=n-1;i>=1;i--){
            b[i]=(b[i+1]*(i+1))%mod;
        }
        dp[0]=1;
        for(ll i=1;i<=n;i++){
            dp[i]=dp[i-1]*((mod+1)/2)%mod;
        }
        for(int i=1;i<n;i++){
            ans=(ans+(C(n-i-1,m-i)*dp[n-i]%mod*i%mod)%mod)%mod;
        }
        if(m==n){
            ans=n;
        }
        cout<<ans*k%mod<<'\n';
    }
    return 0;
}