#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int T;
ll a,b,c;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=y;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        ll x=0,y=0,k;
        k=exgcd(a,b,x,y);
        if(c%k==0){
            a/=k,b/=k,c/=k;
            x*=c,y*=c;
            ll xmn=()
        }
        else{
            printf("-1");
        }
    }
}