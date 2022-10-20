#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qwe=10005;
ll n,ans,m=INT_MIN;
ll r[]={2,3,5,7,11,13,17,19,23,29,31,37};
void dfs(ll u,ll mx,ll p,ll pr){
    if(pr>m||(pr==m&&p<ans)){
        m=pr;
        ans=p;
    }
    if(u==9){
        return;
    }
    for(ll i=1;i<=mx;i++){
        if(p*r[u]>n){
            break;
        }
        p*=r[u];
        dfs(u+1,i,p,pr*(i+1));
    }
}
int main(){
    scanf("%lld",&n);
    dfs(0,31,1,1);
    printf("%lld",ans);
}