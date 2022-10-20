#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qwe=1000005;
ll n,cnt;
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
ll po(int a,int b){
    int ans = 1, base = a;
    while (b != 0) {
        if (b & 1 != 0)
            ans *= base;
            base *= base;
            b >>= 1;
    }
    return ans;
}
int main(){
    scanf("%lld",&n);
    shai(n);
    for(int i=1;i<=cnt;i++){
        cnt=0;
        if(r[i]>n) break;
        for(int j=1;j<=n;j++){
            int k=po(r[i],j)
            if(k>n) break;
            cnt+=(n/k);
        }
        printf("%d%d",&)
    }
    return 0;
}