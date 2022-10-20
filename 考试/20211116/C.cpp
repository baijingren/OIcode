#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define to(i) edge[i].to
#define w(i) edge[i].w
#define nxt(i) edge[i].nxt
const int qwe=1e6+5;
ll n,cnt=0,sum=0;
int hd[qwe];
ll fir[qwe],sec[qwe],trd[qwe],s1[qwe],s2[qwe];
ll d[qwe],f[qwe],ds[qwe],d1[qwe],d2[qwe];
struct Edge{
    int to,nxt,w;
} edge[qwe];
void add(int u,int v,int w){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    w(cnt)=w;
    hd[u]=cnt;
}
void dfs(int u,int fa){
    ll sum=0;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa) continue;
        dfs(v,u);
        if(fir[v]+w(i)>sum){
            sum=fir[v]+w(i);
            s1[u]=v;
        }
    }
    fir[u]=sum;
    sum=0;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa||v==s1[u]) continue;
        if(fir[v]+w(i)>sum){
            sum=fir[v]+w(i);
            s2[u]=v;
        }
    }
    sec[u]=sum;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa||v==s1[u]||v==s2[u]) continue;
        trd[u]=max(trd[u],fir[v]+w(i));
    }
}
void dfs2(int u,int fa){//直径
    d[u]=fir[u]+sec[u];
    ll num=0;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa) continue;
        if(v==s1[u]){
            f[v]=max(f[u]+w(i),sec[u]+w(i));
        }
        else{
            f[v]=max(f[u]+w(i),fir[u]+w(i));
        }
        dfs2(v,u);
        d[u]=max(d[u],d[v]);;
        if(d[v]>sum){
            sum=d[v];
            ds[u]=v;
        }
    }
    d1[u]=sum;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa||v==ds[u]) continue;
        d2[u]=max(d2[u],d[v]);
    }
}
void dfs3(int u,int fa,ll &ans){
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v=fa) continue;
        ll res=d[v];
        if(v==ds[u]){
            ll sum=d2[u];
            if(v==s1[u]){
                sum=max(sum,sec[u]+max(f[u],trd[u]));
            }
            else{
                sum=max(sum,fir[u]+max(f[u],sec[u]));
            }

        }
        else{
            ll sum=d1[u];
            if(v==s1[u]){
                sum=max(sum,sec[u]+max(f[u],trd[u]));
            }
            else{
                sum=max(sum,fir[u]+max(f[u],sec[u]));
            }
            ans=max(ans,sum+res);
        }
        dfs3(v,u,ans);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    ll ans=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        printf("%d",fir[i]);
    }
    dfs2(1,0);
    dfs3(1,0,ans);
    printf("%lld\n",ans);
}