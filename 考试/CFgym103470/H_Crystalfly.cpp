#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int qwe=1e6+5;
int T,n;
ll a[qwe],t[qwe],f[qwe],g[qwe];

int cnt=0,hd[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
void add(int u,int v){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}

void dfs(int u,int fa){
    g[u]=a[u];
    ll ans1=INT_MIN,ans2=INT_MIN;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa){
            continue;
        }
        dfs(v,u);
        g[u]+=f[v]-a[v];
        ll tmp=g[v]-f[v]+a[v];
        if(tmp>ans1){
            ans2=ans1;
            ans1=tmp;
        }
        else if(tmp>ans2){
            ans2=tmp;
        }
    }
    f[u]=g[u];
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa){
            continue;
        }
        f[u]=max(f[u],g[u]+a[v]);
        if(t[v]==3){
            if(g[v]-f[v]+a[v]==ans1){
                f[u]=max(f[u],g[u]+a[v]+ans2);
            }
            else{
                f[u]=max(f[u],g[u]+a[v]+ans1);
            }
        }
    }
    // cout<<u<<' '<<f[u]<<endl;
}
void init(){
    // memset(a,0,sizeof(a));
    // memset(hd,0,sizeof(hd));
    // memset(t,0,sizeof(t));
    // cnt=0;
    // memset(f,0,sizeof(f));
    // memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        f[i]=g[i]=0;
        hd[i]=0;
    }
    cnt=0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&t[i]);
        }
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs(1,0);
        printf("%lld\n",f[1]);
    }
}
