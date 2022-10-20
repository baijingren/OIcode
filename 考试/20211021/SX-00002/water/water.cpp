#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
// typedef unsigned long long ll;
const int qwe=1e6+5;
// __int128 n;
int n,m,cnt=0;
int hd[qwe],in[qwe],out[qwe],d[qwe];
ll tot[2];
ll ans[2][qwe];
int vis[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    hd[u]=cnt;
}
queue<int> q;
ll gcd(ll x,ll y){
    if(y%x==0) return x;
    if(x==1){
        return y;
    }
    return gcd(y%x,x);
}
void pls(ll x,ll y,ll &a,ll &b){
    if(a!=0&&y!=0){
        ll fz=x*b+a*y,fm=y*b;
        ll mod=gcd(fz,fm);
        a=fz/mod,b=fm/mod;
    }
    else{
        ll mod=gcd(x,y);
        a=x/mod,b=y/mod;
    }
}
int main(){
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&d[i]);
        for(int j=1;j<=d[i];j++){
            scanf("%d",&v);
            add(i,v);
            in[v]++;
            out[i]++;
        }
    }
    for(int i=1;i<=m;i++){
            q.push(i);
            ans[0][i]=1;
            ans[1][i]=1;
    }
    while(!q.empty()){
        int u=q.front();
        int b=ans[0][u],c=ans[1][u]*d[u];
        q.pop();
        for(int i=hd[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            pls(b,c,ans[0][v],ans[1][v]);
            vis[v]++;
            if(vis[v]==in[v]){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(out[i]==0){
            printf("%lld %lld\n",ans[0][i],ans[1][i]);
            pls(ans[0][i],ans[1][i],tot[0],tot[1]);
        }
    }
    return 0;
}