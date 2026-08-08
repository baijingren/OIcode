#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int n,m;
int c[qwe],W[qwe],V[qwe],sum[qwe],val[qwe];
vector<int> e[qwe],edge[qwe];
int cnt=0,low[qwe],dfn[qwe];
stack<int> s;
bool vis[qwe];
int tot=0;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    vis[u]=1;
    for(int v:edge[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int y;
        tot++;
        do{
            y=s.top();
            s.pop();
            sum[tot]+=W[y];
            val[tot]+=V[y];
            c[y]=tot;
            vis[y]=0;
        }while(u!=y);
    }
}
int siz[qwe],id[qwe],tim=0;
void dfs(int u,int fa){
    siz[u]=1;
    id[u]=++tim;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>W[i];
    }
    for(int i=1;i<=n;i++){
        cin>>V[i];
    }
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        edge[i].emplace_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int v:e[i]){
            if(c[i]!=c[v]){
                e[i].emplace_back(v);
            }
        }
    }
    dfs(1,0);
    for(int i=1;i<=tim;i++){
        for(int j=1;j<=)
    }
}