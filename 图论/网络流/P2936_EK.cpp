#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e5+5;
int n,s = 1,t = 26;

int hd[qwe], cnt = 1;
struct Edge{
    int nxt, to, w;
} edge[qwe];
void add(int u,int v,int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

int lst[qwe],flow[qwe];
void init(){
    memset(lst, -1, sizeof(lst));
    flow[s] = INT_MAX;
}
bool bfs(){
    init();
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == t){
            break;
        }
        for(int i = hd[u]; i; i = edge[i].nxt){
            int v = edge[i].to;
            if(edge[i].w > 0 && lst[v] == -1){
                q.push(v);
                flow[v] = min(flow[u],edge[i].w);
                lst[v] = i;
            }
        }
    }
    return lst[t] != -1;
}

int ans = 0;

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        char a, b;
        int w;
        cin >> a >> b >> w;
        add(a - 'A' + 1, b - 'A' + 1, w);
        add(b - 'A' + 1, a - 'A' + 1, 0);
    }
    while(bfs()){
        ans += flow[t];
        for(int i = t; i != s; i = edge[lst[i] ^ 1].to){
            edge[lst[i]].w -= flow[t];
            edge[lst[i] ^ 1].w += flow[t];
        }
    }
    cout<<ans<<endl;
    return 0;
}