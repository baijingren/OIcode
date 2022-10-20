#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,ans=0;
struct Node{
    int x,y;
    explicit Node(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    bool operator<(const Node &a) const {
        return this->y>a.y;
    }
};
vector<Node> e[qwe];
priority_queue<Node> q;
int dis[qwe];
bool vis[qwe];
void dij(){
    memset(dis,0x3f,sizeof(dis));
    q.emplace(1,0);
    dis[1]=0;
    while(!q.empty()){
        int u=q.top().x;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto V:e[u]){
            int v=V.x;
            if(dis[v]>dis[u]+V.y){
                dis[v]=dis[u]+V.y;
                if(!vis[v]){
                    q.emplace(v,dis[v]);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    dij();
    for(int i=1;i<=n;i++){
        for(auto V:e[i]){
            int v=V.x;
            if(dis[i]+V.y==dis[v]){
                ans++;
            }
        }
    }
    cout<<dis[n]<<' '<<ans;
    return 0;
}