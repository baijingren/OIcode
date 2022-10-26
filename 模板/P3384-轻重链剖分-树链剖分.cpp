#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe];
int dfn[qwe],id[qwe],siz[qwe],son[qwe],cnt=0;
vector<int> e[qwe];
void dfs(int u,int fa){
    dfn[u]=++cnt;
    id[cnt]=u;
    siz[u]=1;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]){
            son[u]=v;
        }
    }
}
void dfss(int u,int fa,int tp){
    if(son[u]){
        dfss(son[u],u,tp);
    }
    for(int v:e[u]){
        if(v==fa || v==son[u]){
            continue;
        }
        dfss(v,u,v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){

    }
}
