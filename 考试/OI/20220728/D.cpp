#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,tot=0;
vector<int> e[qwe],scc[qwe],ed[qwe];
int dfn[qwe],low[qwe],cnt=0,c[qwe];
bool vis[qwe];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    vis[u]=1;
    for(int v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        tot++;
        int v=0;
        do{
            v=s.top();
            s.pop();
            c[v]=tot;
            scc[tot].push_back(v);
        }while(u!=v)
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!)
    }
}