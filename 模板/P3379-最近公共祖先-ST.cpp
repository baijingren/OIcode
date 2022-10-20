#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,s,t;
int vis[qwe],dep[qwe];
int f[qwe][21];
vector<int> e[qwe];
queue<int> q;
int query(int x,int y){
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
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    t=log2(n);
    q.push(s);
    vis[s]=1;
    dep[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:e[u]){
            if(dep[v]){
                continue;
            }
            // vis[v]=1;
            f[v][0]=u;
            dep[v]=dep[u]+1;
            for(int i=1;i<=t;i++){
                f[v][i]=f[f[v][i-1]][i-1];
            }
            q.push(v);
        }
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",query(u,v));
    }
    return 0;
}