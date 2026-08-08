#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe=1e6+5;
int n;
ll ans=0;
int c=0;
// int a[qwe],w[qwe];
struct Node{
    int v,w;
} k[qwe];
bool vis[qwe];
void dfs(int x,ll s,ll cnt){
    c++;
    ans=max(ans,cnt);
    if(x>n) return;
    // cout<<cnt<<' ';
    for(int i=1;i<=n;i++){
        if(k[i].v<s) continue;
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,s+k[i].w,cnt+(k[i].v-s));
            vis[i]=0;
        }
    }
}
bool cmp(Node x,Node y){
    return x.w<y.w;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&k[i].v,&k[i].w);
    }
    sort(k+1,k+n+1,cmp);
    dfs(1,0,0);
    cout<<c<<endl;
    printf("%lld",ans);
}