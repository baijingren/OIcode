#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qwe=1000005;
ll l,u,cnt;
ll r[qwe];
bool v[qwe];
void shai(ll n){
    cnt=0;
    memset(v,0,sizeof(v));
    memset(r,0,sizeof(r));
    for(ll i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            r[cnt++]=i;
        }
        for(ll j=0;j<cnt;j++){
            if(r[j]>v[i]||r[j]>n/i) break;
            v[r[j]*i]=1;
        }
    }
}
// void shai(ll n) {
//     memset(num, 0, sizeof num);
//     cnt = 0;
//     for (ll i = 2; i <= n; ++ i) {
//         if (!num[i]) r[cnt ++ ] = i;
//         for (ll j = 0; r[j] * i <= n; ++ j) {
//             num[r[j] * i] = true;
//             if (i % r[j] == 0) break;
//         }
//     }
// }
int main(){
    while(scanf("%lld%lld",&l,&u)!=EOF){
        shai(50000);
        memset(v,0,sizeof(v));
        for(ll i=0;i<cnt;i++){
            ll p=r[i];
            for(ll j=max(2*p,(l+p-1)/p*p);j<=u;j+=p){
                v[j-l]=1;
            }
        }
        // for(ll i=1;i<=u;i++){
        //     cout<<i<<' '<<num[i]<<endl;
        // }
        cnt=0;
        for(ll i=0;i<=u-l;i++){
            // cout<<i<<' '<<num[i]<<' '<<i+l<<endl;
            if(v[i]==0&&i+l>1){
                r[cnt++]=i+l;
            }
        }
        // for(ll i=0;i<cnt;i++){
        //     cout<<r[i]<<endl;
        // }
        if(cnt<2){
            printf("There are no adjacent primes.\n");
            continue;
        }
        ll mxid,mnid,mx=INT_MIN,mn=INT_MAX;
        for(ll i=0;i<cnt-1;i++){
            // if(num[i-l]==1) continue;
            ll m=r[i+1]-r[i];
            if(m<mn){
                mn=m;
                mnid=i;
            }
            if(m>mx){
                mx=m;
                mxid=i;
            }
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",r[mnid],r[mnid+1],r[mxid],r[mxid+1]);
        /*
        */
    }
    return 0;
}