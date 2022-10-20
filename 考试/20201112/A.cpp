#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
#define fr(i) edge[i].from
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define w(i) edge[i].w
// const int qwe=2e3+5;
int n, m, cnt=0;
int hd[qwe],fa[qwe],v[qwe],f[qwe],dist[qwe],r[qwe];
bool vis[qwe];
struct Edge{
    int to,nxt,w,from;
} edge[qwe],tr[qwe];
int fnd(int x){
    return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
void add(int u,int v,int w){
    cnt++;
    to(cnt)=v;
    fr(cnt)=u;
    nxt(cnt)=hd[u];
    w(cnt)=w;
    hd[u]=cnt;
}
void adtr(int u,int v,int w){
    cnt++;
    tr[cnt].nxt=hd[u];
    tr[cnt].to=v;
    tr[cnt].w=w;
    tr[cnt].from=u;
    hd[u]=cnt;
}
bool cmp(Edge x,Edge y){
    return x.w>y.w;
}
void merge(int x,int y){
    int a=fnd(x),b=fnd(y);
    if(a==b) return;
    // fa[a]=b;
    if(r[a]>r[b]){
        swap(a,b);
    }
    fa[a]=b;
    if(r[a]==r[b]){
        r[b]++;
    }
}
void kru(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    memset(r,0,sizeof(r));
    sort(edge+1,edge+m+1,cmp);
    cnt=0;
    memset(hd,0,sizeof(hd));
    for(int i=1;i<=m;i++){
        int f=fr(i),v=to(i);
        int x=fnd(f),y=fnd(v);
        if(x==y){
            continue;
        }
        adtr(x,y,w(i));
        adtr(y,x,w(i));
        merge(x,y);
    }
}
void dfs(int u){
    for(int i=hd[u];i;i=tr[i].nxt){
        int V=tr[i].to;
        if(vis[V]) continue;
        vis[V]=1;
        f[V]=u;
        v[V]=tr[i].w;
        dist[V]=dist[u]+1;
        dfs(V);
    }
}
int query(int x,int y){
    int a=fnd(x),b=fnd(y);
    if(a!=b) return -1;
    int ans=INT_MAX;
    if(dist[x]<dist[y]){
        swap(x,y);
    }
    while(dist[x]>dist[y]){
        ans=min(ans,v[x]);
        x=f[x];
    }
    while(x!=y){
        ans=min(ans,min(v[x],v[y]));
        x=f[x];
        y=f[y];
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int u,vv,w;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&vv,&w);
        fr(i)=u,to(i)=vv,w(i)=w;
        // add(u,vv,-w);
        // add(vv,u,-w);
    }
    memset(hd,0,sizeof(hd));
    kru();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dist[i]=1;
            vis[i]=1;
            v[i]=0;
            f[i]=0;
            dfs(i);
        }
    }
    int Q,x,y;
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }
}