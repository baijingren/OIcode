#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe=1e6+5;
ll n,mul=1;
ll b[qwe],c[qwe],a[qwe],m[qwe];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&b[i],&c[i]);
        mul*=b[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        m[i]=mul/b[i];
        ll x=0,y=0;
        exgcd(m[i],b[i],x,y);
        if(x<0){
            ans=ans+c[i]*m[i]*(x+b[i]);
        }else{
            ans=ans+c[i]*m[i]*x;
        }
    }
    // cout<<mul;
    printf("%lld",ans%mul);
}