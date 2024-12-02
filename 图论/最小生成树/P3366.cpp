#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
struct Edge{
    int nxt, to, w;
    bool operator< (const Edge& b)const {
        return this->w < b.w;
    }
    bool operator> (const Edge& b)const {
        return this->w > b.w;
    }
};

int cnt = 0, hd[qwe];
Edge edge[qwe];
void add_edge(int u, int v, int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

bool vis[qwe];
int ans = 0;
int cnt_pnt = 0;
priority_queue<Edge, vector<Edge>, greater<Edge> > q;   
void dfs(int u){
    vis[u] = 1;
    cnt_pnt++;
    for(int i = hd[u]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(vis[v]){
            continue;
        }
        q.push(edge[i]);
    }
    Edge mn = q.top();
    while(vis[mn.to] && q.size()){
        // dfs(mn.to);
        q.pop();
        mn = q.top();
    }
    if(q.empty()){
        return;
    }
    ans += mn.w;
    dfs(mn.to);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dfs(1);
    if(cnt_pnt != n){
        cout << "orz" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}