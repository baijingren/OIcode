#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
struct Edge{
    int nxt, to, u;
    double w;
    bool operator> (const Edge& b) const{
        return w > b.w;
    }
};

Edge edge[qwe];
int cnt = 0, hd[qwe];
void add(int u, int v, double w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    edge[cnt].w = w;
    hd[u] = cnt;
}

int fa[qwe];
int fnd(int u){
    if(fa[u] == u){
        return fa[u];
    }
    return fa[u] = fnd(fa[u]);
}
void add(int u, int v){
    int x = fnd(fa[u]), y = fnd(fa[v]);
    fa[y] = x;
}

priority_queue<Edge, vector<Edge>, greater<Edge> > q;
int ans = 0;
void bfs(){
    for(int i = 1; i <= cnt; i++){
        q.push(edge[i]);
    }
    while(q.size()){
        auto tmp = q.top();
        q.pop();
        int u = tmp.u;
        int v = tmp.to;
        while(fnd(fa[v]) == fnd(fa[u])){
            tmp = q.top();
            q.pop();
            u = tmp.u;
            v = tmp.to;
        }
        if(q.empty()){
            break;
        }
        add(u, v);
        ans += tmp.w;
    }
}

pair<int, int> pos[qwe];
double distance(pair<int, int> a, pair<int, int> b){
    return sqrt((1.0 * a.first - b.first) * (1.0 * a.first - b.first) 
                + (1.0 * a.second - b.second) * (1.0 * a.second - b.second));
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pos[i].first >> pos[i].second;
    }
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            double w = distance(pos[i], pos[j]);
            add(i, j, w);
            add(j, i, w);
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}