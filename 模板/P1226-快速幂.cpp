#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,p;
ll pw(ll a,ll b){
    ll ans=1,k=a;
    while(b){
        if(b&1){
            ans=(ans*k)%p;
        }
        k=(k*k)%p;
        b>>=1;
    }
    return ans%p;
}
int main(){
    scanf("%lld%lld%lld",&a,&b,&p);
    ll ans=pw(a,b);
    printf("%lld^%lld mod %lld=%lld",a,b,p,ans);
    return 0;
}