#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int n,s,cnt=0,SUM=0,p,st,ed,t;
int hd[qwe],f[qwe][20],a[qwe][2],dis[qwe],d[qwe],fa[qwe],w[qwe];
bool dd[qwe];
struct EDGE{
    int to,nxt,w;
}edge[qwe*2];
void add(int u,int v,int ww){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    edge[cnt].w=ww;
    w[edge[cnt].to]=ww;
    hd[u]=cnt;
}
void bfs(int x,bool y){
    queue<int> q;
    memset(f,0,sizeof(f));
    // memset(vis,0,sizeof(vis));
    q.push(x);
    // vis[x]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=hd[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(d[v]) continue;
            d[v]=d[u]+1;
            dis[v]=dis[u]+edge[i].w;
            f[v][0]=u;
            for(int j = 1;j <= t;j++){
                f[v][j]=f[f[v][j-1]][j-1];
            }
            q.push(v);
        }
        ed=u;
    }
    for(int i=1;i<=n;i++){
        // cout<<SUM<<' '<<dis[i]<<' '<<i<<endl;
        if(SUM<dis[i]){
            SUM=dis[i];
            p=i;
        }
    }
}
void lon(int x){
    while(x){
        dd[x]=1;
        x=f[x][0];
    }
}
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
int fnd(){
    int mn=INT_MAX;
    for(int i=1;i<=n;i++){
        if(dd[i]) continue;
        int lc=lca(i,p);
        mn=min(mn,dis[i]-dis[lc]);
    }
    return mn;
}
int fndr(int x,int len){
    int ans=0;
    while(fa[x]){
        int to=fa[x];
        for(int i=hd[to];i;i=edge[i].nxt){
            int u=edge[i].to;
            if(u==x){
                ans+=edge[i].w;
                if(ans>len){
                    return u;
                }
                break;
            }
        }
        x=to;
    }
}
int fndl(int u,int len){
    int ans=0;
    while(u!=ed){
        ans+=w[u];
        if(ans>len){
            return u;
        }
        u=f[u][0];
    }
}
bool chk(int x){
    int l=fndl(ed,x),r=fndr(st,x);
    // cout<<x<<' '<<l<<' '<<r<<endl;
    return a[l]-a[r]<=s;
}
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<edge[i].to<<' '<<edge[i].nxt<<' '<<edge[i].w<<endl;
    // }
    t=log2(n);
    bfs(1,0);
    st=p;
    SUM=0;
    cout<<endl;
    bfs(p,1);
    // ed=p;
    cout<<st<<' '<<ed<<' '<<p<<' ';
    // cout<<SUM<<endl;
    lon(p);
    int l=fnd(),r=SUM;
    while(l<r){
        int mid=(l+r)/2;
        if(chk(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}