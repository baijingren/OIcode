#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
const ll mod=998244353;
int T;
int n,m;
int a[qwe];
void init(){
    a[1]=1;
    for(int i=2;i<=1000;i++){
        ll ans=(ll)a[i-1]*i;
        // cout<<ans<<endl;
        ans%=mod;
        a[i]=(int)ans;
    }
}

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d",&n);
        if(n%2==1){
            printf("0\n");
        }
        else{
            printf("%lld\n",(a[n/2]%mod*a[n/2]%mod)%mod);
        }
    }
    return 0;
}