#include "bits/stdc++.h"
using namespace std;
const int qwe=1e6+5;
int n,m,p,Q;
int to[qwe],in[qwe];
vector<int> e[qwe];
int dist[qwe][2];
bool vis[qwe][2];
int ans[qwe];
int cnt1=0,cnt2=0;
struct Node{
    int x,f;
    explicit Node(){}
    explicit Node(int a,int b){
        x=a;
        f=b;
    }
} a[qwe];
void bfs(int s,bool f){
    queue<Node> q;
    while(!q.empty()){
        q.pop();
    }
    dist[s][f]=0;
    vis[s][f]=1;
    q.emplace(s,0);
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        dist[u.x][f]=u.f;
        for(int v:e[u.x]){
        // for(int i=0;i<e[u.x].size();i++){
            // int v=e[u.x][i];
            if(vis[v][f]){
                continue;
            }
            vis[v][f]=1;
            q.emplace(v,u.f+1);
        }
    }
}
int cnt[qwe];
int tmp[qwe],cntt;
void calc(int s,bool f,int mod){
    memset(cnt,0,sizeof(cnt));
    if(in[s]==0){
        for(int i=1;i<=n;i++){
            cnt[dist[i][f]]++;
        }
        for(int i=1;i<=Q;i++){
            if(a[i].x<qwe)
                ans[a[i].f]+=cnt[a[i].x];
        }
    }
    else{
        cntt=0;
        for(int i=1;i<=n;i++){
            if(vis[i][f]){
                tmp[++cntt]=dist[i][f];
            }
        }
        sort(tmp+1,tmp+n+1);
        int cur=1;
        for(int i=1;i<=n;i++){
            while(cur<=cntt && tmp[cur] <= a[i].x){
                cnt[tmp[cur]%mod]++;
                cur++;
            }
            ans[a[i].f]+=cnt[a[i].x%mod];
        }
    }
}
int sz[qwe],mp[qwe][2];
queue<int> q;
int main(){
    freopen("garden.in","r",stdin);
    freopen("garden.out","w",stdout);
    memset(dist,-1,sizeof(dist));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>p;
    p++;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        u++,v++;
        if(sz[u]<2){
            mp[u][sz[u]++]=v;
        }
        if(sz[v]<2){
            mp[v][sz[v]++]=u;
        }
    }
    for(int i=1;i<=n;i++){
        to[i]=mp[i][0];
        to[i+n]=(sz[i]<2)?mp[i][0]:mp[i][1];
        if(mp[to[i]][0]==i){
            to[i]+=n;
        }
        if(mp[to[i+n]][0]==i){
            to[i+n]+=n;
        }
        in[to[i]]++;
        in[to[i+n]]++;
    }
    for(int i=1;i<=n*2;i++){
        e[to[i]].emplace_back(i);
    }
    // for(int i=1;i<=n*2;i++){
    //     cerr<<i<<':';
    //     for(auto v:e[i]){
    //         cerr<<v<<' ';
    //     }
    //     cerr<<endl;
    // }
    bfs(p,0);
    bfs(p+n,1);
    // queue<int> q;
    // while(!q.empty()){
    //     q.pop();
    // }
    for(int i=1;i<=n*2;i++){
        if(!in[i]){
            q.emplace(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        in[to[u]]--;
        if(!in[to[u]]){
            q.push(to[u]);
        }
    }
    for(int i=1;i<=n*2;i++){
        if(in[i]){
            if(vis[i][0]){
                cnt1++;
            }
            if(vis[i][1]){
                cnt2++;
            }
        }
    }
    cin>>Q;
    // cerr<<Q<<endl;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        // x++;
        a[i].x=x;
        a[i].f=i;
    }
    sort(a+1,a+Q+1,[](Node a,Node b){
        return a.x<b.x;
    });
    // for(int i=1;i<=n*2;i++){
    //     cerr<<i<<' '<<dist[i][0]<<' '<<dist[i][1]<<endl;
    // }
    calc(p,0,cnt1);
    calc(p+n,1,cnt2);
    for(int i=1;i<=Q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}