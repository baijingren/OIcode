#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=4e5+5;
int n,m,q;
// int a[qwe];

int dfn[qwe],low[qwe],num=0,fa[qwe],b[qwe];
int cnt=0;
// bool vis[qwe];
stack<int> s;
vector<pair<int,int>> e[qwe],edge[qwe];
// vector<int> dcc[qwe];
void tarjan(int u,int f){
    dfn[u]=low[u]=++num;
    // s.push(u);
    // if(u==root && !e[u].size()){
    //     dcc[++cnt].push_back(u);
    // }
    // int flag=0;
    for(auto v:e[u]){
        if(v.first==f) continue;
        if(!dfn[v.first]){
            fa[v.first]=u;
            tarjan(v.first,u);
            b[v.first]=v.second;
            low[u]=min(low[u],low[v.first]);
            // if(low[v.first]>=low[u]){
                // flag++;
            // }
        }
        else{
            low[u]=min(low[u],low[v.first]);
        }
        if(low[v.first]>=dfn[u]){
            edge[u].push_back(v);
            edge[v.first].push_back(make_pair(u,v.second));
        }
    }
    for(auto v:e[u]){
        if(fa[v.first]==u||dfn[v.first]<=dfn[u]){
            continue;
        }
        solve(u,v.first,v.second);
    }
}

int cntt=0;
int sum[qwe];
void solve(int u,int v,int w){
    ++cntt;
    int mn,pre,i;
    while(i!=fa[u]){
        sum[i]=pre;
        pre+=b[i];
        i=fa[i];
    }
    sum[cntt]=sum[u];
    sum[u]=0;
    while(i!=fa[u]){
        mn=min(sum[i],sum[cntt]-sum[i]);
        edge[cntt].push_back(make_pair(i,mn));
        edge[i].push_back(make_pair(cntt,mn));
        i=fa[i];
    }
}

int dep[qwe],size[qwe],dis[qwe],son[qwe],d[qwe];
void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    size[u]=1;
    int mx=-1;
    for(auto v:edge[u]){
        if(v.first==f){
            continue;
        }
        dis[v.first]=dis[u]+v.second;
        dfs1(v.first,u);
        size[u]+=size[v.first];
        if(size[v.first]>mx){
            son[u]=v.first;
            mx=size[v.first];
        }
    }
}
void dfs2(int u,int f){
    d[u]=f;
    if(!son[u]) return;
    dfs2(son[u],f);
    for(auto v:edge[u]){
        if(v.first!=son[u] && v.first!=fa[u]){
            dfs2(v.first,v.first);
        }
    }
}

int lca(int u,int v){
    while(d[u]!=d[v]){
        if(dep[d[u]]<dep[d[v]]){
            swap(u,v);
        }
        u=fa[d[u]];
    }
}
int find(int u,int f){
    int res;
    while(d[u]!=d[f]){
        res=d[u];
        u=fa[d[u]];
    }
    return u=f?res:son[u];
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(make_pair(v,w));
        e[v].push_back(make_pair(u,w));
    }
    tarjan(1,0);
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
    }
    return 0;
}