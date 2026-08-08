#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,m,x,y;
ll a[qwe];
ll ans;
int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        for(int i=1;i<=n;i++){
            if(a[i-1]+x<=m){
                a[i]=a[i-1]+x;
            }
            else{
                a[i]=a[i-1]-y;
            }
            ans+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}