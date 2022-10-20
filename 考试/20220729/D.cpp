#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,q;
vector<int> e[qwe];
struct Edge{
    int to,nxt,u;
} edge[qwe];
int cnt_edge=1,hd[qwe];
void add(int u,int v){
    cnt_edge++;
    edge[cnt_edge].nxt=hd[u];
    edge[cnt_edge].to=v;
    edge[cnt_edge].u=u;
    hd[u]=cnt_edge;
}
bool bridge[qwe];
int dfn[qwe],low[qwe],cnt=0;
void tarjan(int u, int in_edge)
{
    dfn[u]=low[u]=++cnt;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bridge[i]=bridge[i^1]=1;
            }
        }
        else if(i!=(in_edge^1)){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int c[qwe];
int tot=0;
vector<int> dcc[qwe],to[qwe];
void dfs(int u){
    c[u]=tot;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(c[v]){
            continue;
        }
        if(bridge[i]){
            to[v].emplace_back(tot);
            continue;
        }
        dfs(v);
    }
}
queue<int> qt;
int dep[qwe],f[qwe];
bool vis[qwe];
bool sol1(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    if(vis[u] || vis[v]){
        return 0;
    }
    while(dep[u]!=dep[v]){
        if(vis[f[u]]){
            return 0;
        }
        u=f[u];
    }
    if(u==v){
        return 1;
    }
    while(u!=v){
        if(vis[f[u]] || vis[f[v]]){
            return 0;
        }
        u=f[u];
        v=f[v];
    }
    return 1;
}
bool sol2(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    if(vis[u] || vis[v]){
        return 0;
    }
    while(dep[u]!=dep[v]){
        if(vis[f[u]]){
            return 0;
        }
        u=f[u];
    }
    if(u==v){
        return 1;
    }
    while(u!=v){
        if(vis[f[u]] || vis[f[v]]){
            return 0;
        }
        u=f[u];
        v=f[v];
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    tarjan(1,0);
    for(int i=1;i<=n;i++){
        if(!c[i]){
            tot++;
            dfs(i); 
        }
    }
    for(int i=1;i<=n;i++){
        int x=edge[i].u,y=edge[i].to;
        int u=c[x],v=c[y];
        if(u!=v){
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
    }
    qt.push(1);
    dep[1]=1;
    f[1]=0;
    while(!qt.empty()){
        int u=qt.front();
        qt.pop();
        for(int v:e[u]){
            if(dep[v]){
                continue;
            }
            dep[v]=dep[u]+1;
            f[v]=u;
            qt.push(v);
        }
    }
    bool t,k;
    cin>>q;
    for(int i=1;i<=q;i++){
        int op,a,b,x,y;
        cin>>op>>a>>b>>x;
        if(op==1){
            cin>>y;
            if(c[a]==c[b]){
                cout<<"yes\n";
                continue;
            }
                for(int j:to[x]){
                    vis[j]=1;
                }
            // if(c[a]==c[x]){
            //     t=1;
            // }
            // if(c[b]==c[x]){
            //     for(int j:to[x]){
            //         vis[j]=1;
            //     }
            //     t=1;
            // }
            // if(c[a]==c[y]){
                for(int j:to[y]){
                    vis[j]=1;
                }
            //     k=1;
            // }
            // if(c[b]==c[y]){
            //     for(int j:to[y]){
            //         vis[j]=1;
            //     }
            //     k=1;
            // }
            // if(!t){
            //     vis[c[x]]=1;
            // }
            // if(!k){
            //     vis[c[y]]=1;
            // }
            if(sol1(c[a],c[b])){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
            for(int j:to[x]){
                vis[j]=0;
            }
            for(int j:to[y]){
                vis[j]=0;
            }
            // distag(x,y);
        }
        else if(op==2){
            if(c[a]==c[b]){
                cout<<"yes\n";
                continue;
            }
            // tag(x);
            for(int j:to[x]){
                vis[j]=1;
            }
            if(sol2(c[a],c[b])){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
            for(int j:to[x]){
                vis[j]=0;
            }
            // distag(x);
        }
    }
    return 0;
}