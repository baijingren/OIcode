#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,m;
int a[qwe];
ll c[18];
int ans=INT_MAX,cnt=0;
int popc(ll x){
    int sum=0;
    while(x){
		sum+=x&1;
		x>>=1;
	}
    return sum;
}
void dfs(ll x,int k){
    if(x==0){
        ans=min(cnt,ans);
        return;
    }
    if(k==2){
        ans=min(ans,cnt+popc(x));
        return;
    }
    if(c[k]<=x){
        cnt++;
        dfs(x-c[k],k-1);
        cnt--;
    }
    dfs(x,k-1);
}
int main(){
    scanf("%d",&T);
    ll x=1;
    for(int i=1;i<=16;i++){
        c[i]=x*i;
        x*=i;
    }
    // for(int i=1;i<=16;i++){
    //     cout<<c[i]<<endl;
    // }
    while(T--){
        scanf("%lld",&n);
        ans=INT_MAX;
        cnt=0;
        dfs(n,14);
        printf("%d\n",ans);
    }
    return 0;
}