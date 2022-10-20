#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int qwe=1e6+5;
int n,m;
struct Node{
    ll w,v;
} a[qwe];
ll f[qwe];
int main(){
    // freopen("sell.in","r",stdin);
    // freopen("sell.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].w,&a[i].v);
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].w;j--){
            f[j]=max(f[j],f[j-a[i].w]+a[i].v);
        }
    }
    printf("%lld",f[m]);
    return 0;
}