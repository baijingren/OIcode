#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int qwe=1e6+5;
int n,k;
vector<PII> e[qwe];
int son[qwe];
int id[qwe],dfn[qwe],cnt=0;;
int siz[qwe];
void dfs(int u,int fa){
    siz[u]=1;
    dfn[u]=++cnt;
    id[cnt]=u;
    for(auto V:e[u]){
        int v=V.first;
        if(v==fa){
            continue;
        }
        dep[v]=dep[u]+V.second;
        dfs(v,u);
        siz[v]+=siz[u];
        
    }
}
void dfss(int u,int fa){
    for(auto V:e[u]){
        int v=V.first;
        if(v==fa || v==son[u]){
            continue;
        }
        dfss(v,u);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    dfs(1,0);
    dfss(1,0);
    cout<<ans<<'\n';
    return 0;
}