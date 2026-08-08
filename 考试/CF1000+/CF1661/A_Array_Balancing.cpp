#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,m,ans;
ll a[qwe],b[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ll ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&b[i]);
        }
        // ans=min(dfs(1,0),dfs(1,1));
        for(int i=1;i<=n;i++){
            int k=a[i]+b[i];
            a[i]=min(a[i],b[i]);
            b[i]=k-a[i];
        }
        for(int i=1;i<n;i++){
            ans+=abs(a[i]-a[i+1]);
            ans+=abs(b[i]-b[i+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}