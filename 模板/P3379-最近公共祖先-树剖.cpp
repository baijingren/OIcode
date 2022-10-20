#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,s;
int son[qwe];
vector<int> e[qwe];
void dfs(int u,int fa){
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
    }
}
void dfs2(int u,int fa,int k){
    if(son[u]){
        dfs2(son[u],u,u)
    }
    for(int v:e[u]){
        if(v==fa || v==son[u]){
            continue;
        }
        dfs2(v,u,v);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(s,0);
    dfs2(s,0,s);
}