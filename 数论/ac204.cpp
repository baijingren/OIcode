#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qwe=1e6+5;
ll n;
ll a,ai,m,mi;
ll exgcd(ll a,ll b,ll &x,ll &y){
    ll ans;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ans=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return ans;
}
int main(){
    scanf("%lld",&n);
    scanf("%d%d",&a,&m);
    for(int i=1;i<n;i++){
        ll x,y;
        // scanf("%d%d", &a[i],&m[i]);
        scanf("%d%d",&ai,&mi);
        ll d=exgcd(a,-ai,x,y);
        if((mi-m)%d!=0){
            printf("-1\n");
            return 0;
        }
        x=x*(mi-m)/d;
        ll md=abs(ai/d);
        x=((x%md)+md)%md;
        m=x*a+m;
        a=abs(a/d*ai);
    }
    // exgcd()
    printf("%lld",m);
    return 0;
}