#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int m,n,cnt=1,tot=0;
int hd[qwe],dfn[qwe],low[qwe],bridge[qwe];
bool bdg[qwe];
struct EDGE{
    int nxt,to,now;
} edge[qwe];
void add(int u,int v){//从0开始建边
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    edge[cnt].now=u;
    hd[u]=cnt;
    return;
}
void tarjan(int u, int in_edge){
    // cout<<3;
    dfn[u]=low[u]=++tot;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bridge[i]=bridge[i^1]=1; 
                // printf("%d %d %d %d\n", i,i^1,in_edge,in_edge^1);
            }
        }else if(i!=(in_edge^1)){
            low[u]=min(low[u],dfn[v]);
        }
    }
    return;
}
bool cmp(EDGE x, EDGE y){
    if(x.now!=y.now)
        return x.now<y.now;
    else
        return x.to<y.to;
}
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    // freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d%d",&n,&m);
    // memset(hd,-1,sizeof(hd));
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        // cout<<0;
        add(u,v);
        add(v,u);
        // cout<<1;
    }
    for(int i=1;i<=n;i++){
        // cout<<2;
        if(!dfn[i])
            tarjan(i,0);
    }
    sort(edge,edge+cnt+1,cmp);
    // for(int i = 1; i <= cnt; i++){
    //     printf("%d %d %d %d\n",i,edge[i].now,edge[i].to,bridge[i]);
    // }
    for(int i=0;i<=cnt;i+=2){
        if(bridge[i])
            printf("%d %d\n",edge[i].now,edge[i].to);
    }
    return 0;
}
