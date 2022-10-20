#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5;
int n,m,cnt,tot,top,ans;
int hd[M],dfn[N],low[N],sum[N],s[N];
bool vis[N];
struct EDGE{
    int to,nxt;
} edge[M];
void add(int u, int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
    return 0;
}
void add_su(int u, int v){

}
void tarjan(int u){
    dfn[u]=low[u]=++tot;
    vis[u]=1;
    s[++top]=u;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
       ans++;
       int y;
        do{
            y=s[top--];
            vis[y]=0;
            c[y]=ans;
            v[ans].push_back(y);
            sum[ans]++;
        }while(y!=u);
    }
    return;
}
// void
int main(){
    scanf("%d", &n, &m);
    for(int i = 1; i <= n ;i++){
        int u, v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    int num=0;
    for(int i = 1; i<=n;i++){
        if(!dfn[i]){
            num++;
            tarjan(i);
        }
        if(num>=2){
            printf("0");
            return 0;
        }
    }
    num = 0;
    for(int i = 1; i<=n; i++){
        if(dfn[i]==low[i]){
            su[++num]=i;
        }
    }
    // printf("%d",)
}