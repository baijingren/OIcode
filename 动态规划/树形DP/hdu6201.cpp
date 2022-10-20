#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,cnt=0,T,t;
int hd[qwe],div[qwe],d[qwe],f[qwe][30];
struct EDGE{
    int to,nxt,w;
} edge[qwe];
void add(int u,int v,int w){
    cnt++;
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
int lca(int x,int y){
    if(x<y){
        swap(x,y);
    }
    for(int j=1;j<=t;j++){
        if(d[f[x][j]]<=d[y]) x=f[x][j];
    }
    if(x==y) return x;
    for(int j=1;j<=t;j++){
        if(f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
    }
    return 0;
}
void dfs(){
    return;
}
int dist(int u,int v){
    int l=lca(u,v);

}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n);
        t=log2(n);
        for(int i=1;i<=n;i++){
            scanf("%d",&div[i]);
        }
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        // f[u][v]=f[u][son[v]]+div[son[v]]-edge[x].w-div[v];
        // int ans=div[v]-div[u]-dist(u,v);
    }
}