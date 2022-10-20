#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n;
ll a[qwe],ans[qwe],sum[qwe];
int de[qwe],fa[qwe];
bool vis[qwe];
int fnd(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=fnd(fa[x]);
}
void merge(int a,int b){
    int x=fnd(a),y=fnd(b);
    if(x!=y){
        fa[x]=y;
        sum[y]+=sum[x];
        sum[x]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[i]=i;
        sum[i]=a[i];
    }
    for(int j=1;j<=n;j++){
        cin>>de[j];
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        // cout<<ans<<'\n';
        ::ans[i]=ans;
        vis[de[i]]=1;
        if(vis[de[i]-1]){
            merge(de[i]-1,de[i]);
        }
        if(vis[de[i]+1]){
            merge(de[i]+1,de[i]);
        }
        int x=fnd(de[i]);
        ans=max(ans,sum[x]);
    }
    for(int i=1;i<=n;i++){
        cout<<::ans[i]<<'\n';
    }
    return 0;
}