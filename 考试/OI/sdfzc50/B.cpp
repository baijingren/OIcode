#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
#define ll long long
long long n,x,y,z;
long long ans=0;
int cnt=0,hd[qwe];
struct Edge{
    int to,nxt;
    ll w;
} edge[qwe];
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define w(i) edge[i].w
void add(int u,int v,int w){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    w(cnt)=w;
    hd[u]=cnt;
}
#define PII pair<ll,ll>
#define X first
#define Y second
priority_queue<PII> q;
ll dis[qwe];
bool vis[qwe];
void dij(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=1;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int u=q.top().Y;
        q.pop();
        // if(vis[u]){
            // continue;
        // }
        // vis[u]=1;
        for(int i=hd[u];i;i=nxt(i)){
            int v=to(i);
            if(dis[v]>dis[u]+w(i)){
                dis[v]=dis[u]+w(i);
                // mx=max(mx,w(i));
                // if(!vis[v]){
                    q.push(make_pair(dis[v],v));
                // }
            }
        }
    }
}
int main(){
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&x,&y,&z);
    ll as=min({x,y,z}),sd=max({x,y,z}),asd=x+y+z;
    x=as,z=sd,y=asd-as-sd;
    if(x==1){
        printf("%lld",n);
        return 0;
    }
    for(int i=0;i<x;i++){
        add(i,(i+y)%x,y);
        add(i,(i+z)%x,z);
    }
    dij();
    for(int i=0;i<x;i++){
        if(dis[i]<=n){
            ans+=((n-dis[i])/x)+1;
        }
    }
    printf("%lld",ans);
    return 0;
}