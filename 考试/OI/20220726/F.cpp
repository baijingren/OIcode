#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
struct Node{
    int x,y;
    explicit Node(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    bool operator<(const Node &a) const{
        return y<a.y;
    }
};
vector<Node> e[qwe];
priority_queue<Node> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
}