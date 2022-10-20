#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
    scanf("%lld%lld",&n,&m);
    ll ans=n*m,r;
    for(int i=1;i<=n;i=r+1){
        if(m/i==0) break;
        r=min(m/(m/i),n);
        ans-=(m/i)*(i+r)*(r-i+1)/2;
    }
    printf("%lld",ans);
}