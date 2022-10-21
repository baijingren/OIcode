#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=998244353;
int n,m,K;
int a[qwe],cnt=0;
int ans=0;
void work(){
    a[++cnt]=1;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            a[++cnt]=i;
        }
    }
}
int pw(int x,int y){
    int ans=1;
    while(y){
        if(y&1){
            ans*=x;
        }
        y>>=1;
        x*=x;
    }
    return ans;
}
void dfs(int x,int s,int st){
    if(x>=2*m){
        if(s<=K){
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=st;i<=cnt;i++){
        dfs(x+1,s*a[i],1);
    }
}
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    K=pw(n,m);
    work();
    // cerr<<cnt<<endl;
    dfs(0,1,1);
    cout<<ans%mod<<endl;
    cerr<<ans%mod<<endl;
    return 0;
}