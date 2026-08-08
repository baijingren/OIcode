#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define PII pair<ll,int>
const int M=5e5+5;
const int N=2e5+5;
int n,m;
struct Edge{
    int to;
    ll t,c;
    explicit Edge(){}
    explicit Edge(int a,ll c,ll d){
        to=a;
        t=c;
        this->c=d;
    }
    bool operator<(const Edge &a) const {
        return this->t>a.t;
    }
};
vector<Edge> e[N];
// priority_queue<Edge> q;
ll dis[N],val[N];
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII>> q;
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    // val[s]=0;
    q.emplace(0,s);
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto V:e[u]){
            int v=V.to;
            if(dis[v]>max(dis[u],V.t)){
                dis[v]=max(dis[u],V.t);
                q.emplace(dis[v],v);
            }
        }
    }
}
void dijj(int s){
    memset(val,0x3f,sizeof(val));
    memset(vis,0,sizeof(vis));
    q.emplace(0,s);
    val[s]=0;
    // vis[s]=1;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto V:e[u]){
            int v=V.to;
            if(dis[n]>=V.t && val[v]>val[u]+V.c){
                val[v]=val[u]+V.c;
                q.emplace(val[v],v);
            }
        }
    }
}
signed main(){
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        ll c,t;
        cin>>u>>v>>t>>c;
        e[u].emplace_back(v,t,c);
        e[v].emplace_back(u,t,c);
    }
    dij(1);
    dijj(1);
    // for(int i=1;i<=n;i++){
    //     cerr<<i<<':'<<dis[i]<<' '<<val[i]<<endl;
    // }
    cout<<dis[n]<<' '<<val[n]<<endl;
    return 0;
}