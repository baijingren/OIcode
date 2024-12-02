#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
struct Edge{
    int nxt, to, w;
    bool operator>(const Edge& b) const{
        return w > b.w;
    }
};

Edge edge[qwe];
int cnt = 0, hd[qwe];
void add(int u, int v, int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

priority_queue<Edge, vector<Edge>, greater<Edge> > q;
bool vis[qwe];
int ans = 0;
void dfs(int u){
    vis[u] = 1;
    for(int i = hd[u]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(vis[v]){
            continue;
        }
        q.push(edge[i]);
    }
    Edge minEdge = q.top();
    while(vis[minEdge.to] && q.size()){
        q.pop();
        minEdge = q.top();
    }
    if(q.empty()){
        return;
    }
    ans += minEdge.w;
    dfs(minEdge.to);
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int w;
            cin >> w;
            if(i == j)
                continue;
            add(i, j ,w);
            add(j, i, w);
        }
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}