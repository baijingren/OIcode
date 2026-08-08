#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
ll a[qwe];
map<ll,ll> mp;

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int f=0;
        ll x;
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(mp[x-m] || mp[x+m]){
                f=1;
            }
            mp[x]=1;
        }
        if(!f){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}