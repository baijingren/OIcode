#include<bits/stdc++.h>
using namespace std;
const int qwe=5e6+5;
int n,m,s,cnt,t;
int hd[qwe], d[qwe];
int f[qwe][25];
struct EDGE{
    int nxt,to;
} edge[qwe];
void add(int u, int v){
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    hd[u]=cnt;
    return;
}
queue<int> q;
int lca(int x,int y){
    if(d[x]<d[y]) swap(x,y);
    for(int i=t;i>=0;i--){
        if(d[f[x][i]]>=d[y]) x=f[x][i];
    }
    if(x == y) return x;
    for(int i=t;i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
int main(){
    // freopen("/home/bai/code/test.in", "r", stdin);
    scanf("%d%d%d", &n,&m,&s);
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    q.push(s);
    d[s]=1;
    t=log2(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = hd[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(d[v]) continue;
            d[v]=d[u]+1;
            f[v][0]=u;
            for(int j = 1;j <= t;j++){
                f[v][j]=f[f[v][j-1]][j-1];
            }
            q.push(v);
        }
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}