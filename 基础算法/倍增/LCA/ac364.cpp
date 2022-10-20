#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=4e5+1;
int n,m,cnt=1,t,Q,cntc,tot,num,ans;
int hd[N],d[N],hc[N],dfn[N],low[N],c[N];
int f[N][21];
bool bridge[N],cc[N];
struct EDGE
{
    int to,nxt;
} edge[M],ec[M];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
    return;
}
void addc(int u,int v){
    cntc++;
    ec[cntc].to=v;
    ec[cntc].nxt=hc[u];
    hc[u]=cntc;
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
void tarjan(int u,int in_edge){
    dfn[u]=low[u]=++tot;
    for(int i=hd[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v,i);
            low[u] = min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bridge[i]=bridge[i^1]=1;
            }
        }else if(i!=(in_edge^1)){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void dfs(int u){
    c[u]=num;
    for(int i=hd[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(c[v]||bridge[i]) continue;
        dfs(v);
    }
}
void df(int u,int ed){
    if(u==ed) return;
    for(int i=hc[u];i;i=ec[i].nxt){
        int v=ec[i].to;
        if(d[v]>d[u]) continue;
        if(!cc[i]){
            cc[i]=1;
            ans--;
        }
        df(v,ed);
    }
}
void clear(){
    // int n,m,cnt=1,t,Q,cntc,tot,num,ans;
    cnt=-1,t=0,Q=0,cntc=0,tot=0,num=0,ans=0;
    // int hd[qwe],d[qwe],hc[qwe],dfn[qwe],low[qwe],c[qwe],fa[qwe];
    memset(hd,-1,sizeof(hd));
    memset(d,0,sizeof(d));
    memset(hc,0,sizeof(hc));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(c,0,sizeof(c));
    // int f[qwe][51];
    memset(f,0,sizeof(f));
    // bool bridge[qwe],vis[qwe],cc[qwe];
    memset(bridge,0,sizeof(bridge));
    memset(cc,0,sizeof(cc));
    // queue<int> q;
    while (!q.empty()){
        q.pop();
    }
}
int main(){
    // freopen("/home/baijingren/Desktop/编程/test.in", "r", stdin);
    int T=0;
    while(1){
        clear();
        // memset(hd,0,sizeof(hd));
        scanf("%d%d",&n,&m);
        if(n==0&&m==0){
            return 0;
        }
        T++;
        printf("Case %d:\n",T);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        tarjan(1,0);
        for(int i=1;i<=n;i++){
            if(!c[i]) num++,dfs(i);
        }
        for(int i=0;i<=cnt;i+=2){
            int x=edge[i^1].to,y=edge[i].to;
            // cout<<x<<' ' <<y<<endl;
            if(c[x]==c[y]) continue;
            addc(c[x],c[y]);
            addc(c[y],c[x]);
        }
        q.push(1);
        d[1]=1;
        t=log2(n);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = hc[u];i;i=ec[i].nxt){
                int v=ec[i].to;
                if(d[v]) continue;
                d[v]=d[u]+1;
                f[v][0]=u;
                for(int j = 1;j <= t;j++){
                    f[v][j]=f[f[v][j-1]][j-1];
                }
                q.push(v);
            }
        }
        // for(int i = 1;i<=n;i++){
        //     cout<<i<<' '<<d[i]<<endl;
        // }
        ans=cntc/2;
        // cout<<ans<<endl;;
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            if(c[u]==c[v]) {
                printf("%d\n",ans);
                continue;
            }
            int l=lca(c[u],c[v]);
            df(c[u],l);
            df(c[v],l);
            printf("%d\n",ans);
        }
        printf("\n");
    }
}