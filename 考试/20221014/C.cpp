#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
vector<int> e[qwe];
int in[qwe];
void dfs(int u,int fa){
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
    }
}
void bfs(int st){

}
void sol(){
    for(int i=1;i<=n;i++){

    }
}
int main(){
    freopen("spfa.in","r",stdin);
    freopen("spfa.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    
    return 0;
}