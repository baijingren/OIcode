#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int T;
ll a,b,c;
ll ans;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
void lcm(ll x,ll y,ll &l,ll &r,ll &k){
    k=gcd(x,y);
    l=x/k;
    r=y/k;
}
void calc(ll cur){
    ans=0;
    ll l,r,k=0;
    lcm(a,b,l,r,k);
    if(cur==c){
        ans=0;
        return;
    }
    ans=(c-cur)/(a*b/k);
    if((c-cur)%(a*b/k)){
        ans++;
    }
}
signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(c<0){
            a=-a;
            b=-b;
            c=-c;
        }
        if(a*b<0LL){
            if(c%__gcd(a,b)){
                printf("0\n");
            }
            else{
                printf("ZenMeZheMeDuo\n");
            }
            continue;
        }
        if(a==0){
            if(c%b==0 && c/b>0){
                printf("ZenMeZheMeDuo\n");
                continue;
            }
            else{
                printf("0\n");
                continue;
            }
        }
        else if(b==0){
            if(c%a==0 && c/a>0){
                printf("ZenMeZheMeDuo\n");
                continue;
            }
            else{
                printf("0\n");
                continue;
            }
        }
        if(a+b==c){
            printf("1\n");
            continue;
        }
        int cur=c;
            for(int i=1;i<=c/a;i++){
                if((c-i*a)%b==0){
                    cur=i*a;
                    break;
                }
            }
            calc(cur);
            if(ans>65535){
                printf("ZenMeZheMeDuo\n");
            }
            else{
                printf("%lld\n",ans);
            }
    }
    return 0;
}