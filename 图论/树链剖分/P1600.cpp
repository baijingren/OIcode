#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,t;
int a[qwe],dep[qwe],w[qwe];
int f[qwe][21];
vector<int> e[qwe];
queue<int> q;
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    for(int i=t;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            x=f[x][i];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=t;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int dfs(int u){
    for(int i=1)
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    q.push(1);
    dep[1]=1;
    t=log2(n)+1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:e[u]){
            if(dep[v]) continue;
            q.push(v);
            dep[v]=dep[u]+1;
            f[v][0]=u;
            for(int i=1;i<=t;i++){
                f[v][i]=f[f[v][i-1]][i-1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        
    }
}