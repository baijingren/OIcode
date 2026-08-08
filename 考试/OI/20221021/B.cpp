#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=1e9+7;
int n,Q;
int deg[qwe];
int f[qwe],g[qwe];
vector<int> e[qwe];
void dfs(int u,int fa){
    f[u]=deg[u];
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        f[u]=(f[u]+f[v])%mod;
    }
}
void dfs2(int u,int fa){
    if(u!=1){
        g[u]=(g[fa]+f[fa]-f[u])%mod;
    }
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs2(v,u);
    }
}
void dfs3(int u,int fa){
    f[u]=(f[u]+f[fa])%mod;
    g[u]=(g[u]+g[fa])%mod;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs3(v,u);
    }
}
int t;
queue<int> q;
int dep[qwe];
int h[30][qwe];
void init(){
    t=log2(n);
    q.push(1);
    dep[1]=1;
    while(!q.empty()){
        int  u=q.front();
        q.pop();
        for(int v:e[u]){
            if(dep[v]){
                continue;
            }
            dep[v]=dep[u]+1;
            h[0][v]=u;
            for(int i=1;i<=t;i++){
                h[i][v]=h[i-1][h[i-1][v]];
            }
            q.push(v);
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    for(int i=t;i>=0;i--){
        if(dep[h[i][x]]>=dep[y]){
            x=h[i][x];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=t;i>=0;i--){
        if(h[i][x]!=h[i][y]){
            x=h[i][x],y=h[i][y];
        }
    }
    return h[0][x];
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>Q;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1,0);
    dfs2(1,0);
    dfs3(1,0);
    init();
    for(int i=1;i<=Q;i++){
        int u,v;
        int ans=0;
        cin>>u>>v;
        int L=lca(u,v);
        // cerr<<"L:"<<L<<endl;
        ans=((ans+f[u]-f[L]+g[v]-g[L])%mod+mod)%mod;
        cout<<ans<<'\n';
        // cerr<<ans<<'\n';
    }
    return 0;
}