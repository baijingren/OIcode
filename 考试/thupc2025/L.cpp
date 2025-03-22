#include<bits/stdc++.h>
using namespace std;
const int qwe = 5e4+5;
int n, m, c;
struct Edge{
    int nxt, w;
    int u, v;
    bool vis;
};

int cnt = 0, hd[qwe], cnte = 0;
Edge edge[qwe];
Edge e[qwe];
void add(Edge* edge, int u, int v, int w, int cnt){
    edge[++cnt].nxt = w;
    edge[cnt].w = w;
    edge[cnt].u = u;
    edge[cnt].v = v;
    hd[u] = cnt;
}


int r[qwe];

set<int> col[qwe];
int dep[qwe];
bool visc[qwe];
bool dfs(int u){
    bool ret = 0;
    for(int i = hd[u]; i; i = edge[i].nxt){
        int v = edge[i].v;
        if(visc[v]){
            edge[i].vis = 1;
            visc[v] = 1;
            ret = 1;
            continue;
        }
        if(dfs(v) == 1){
            edge[i].vis = 1;
            visc[v] = 1;
            ret = 1;
        }
    }
    return ret;
}

int main(){
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++){
        cin >> r[i];
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(edge, u, v, w, cnt);
    }
    dfs(1);
    memset(hd, 0, sizeof(hd));
    for(int i = 1; i <= cnt; i++){
        if(edge[i].vis == 0){
            continue;
        }
        add(e, edge[i].u, edge[i].v, edge[i].w, cnte);
    }
    
    return 0;
}