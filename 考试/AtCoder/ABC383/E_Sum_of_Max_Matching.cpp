#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m, k;
int a[qwe], b[qwe];
struct Edge{
    int nxt, to, w;
};

Edge edge[qwe];
int hd[qwe], cnt = 0;
void add(int u, int v, int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

int main(){
    cin >> n >> m >> k;
    for(int i =1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u ,v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= k; i++){
        cin >> a[i] >> b[i];
    }
}