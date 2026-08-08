#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
typedef long long ll;
int n,k,cnt=0;
ll hd[qwe],a[qwe],dis[qwe];
ll f[qwe][25];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}
void build(int u){
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(dis[v]) continue;
        dis[v]=dis[u]+1;
        build(v);
        for(int j=1;j<=k;j++){
    // cout<<2;
            f[u][j]+=f[v][j-1];
        }
    }
}
void dfs(int u){
    // if(d>k){
    //     return ans;
    // }
    // cout<<1;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=to(i);
        // cout<<nxt(i);
        if(dis[v]<=dis[u]) continue;
            // for(int j=1;j<=k;j++){
            // for(int j=k;j>=1;j--){
            for(int j=k;j>=2;j--){
                f[v][j]-=f[v][j-2];
            }
            for(int j=1;j<=k;j++){
            // for(int j=k;j>=1;j--){
                f[v][j]+=f[u][j-1];
            }
            dfs(v);
        // if(fa==v) continue;
        // dfs(v,u,d+1);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++){
        f[i][0]=0;
        // scanf("%d",&f[i][1]);
        scanf("%lld",&f[i][0]);
    }
    dis[1]=1;
    build(1);
    dfs(1);
    for(int i=1;i<=n;i++){
        ll ans=0;
        for(int j=0;j<=k;j++){
            ans+=f[i][j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}