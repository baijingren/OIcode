#include<bits/stdc++.h>
using namespace std;
const int qwe = 3e4+5;
int n,s = 0, ans, t;
bool vis[qwe];

int hd[qwe],cnt = 1;
struct Edge{
    int to,nxt,w;
} edge[qwe];
void add(int u,int v,int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt;
}

int dfs(int u = s, int flow = INT_MAX){
    if(u == t){
        return flow;
    }
    vis[u] = 1;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v = edge[i].to, c;
        if(edge[i].w > 0 && !vis[v] &&  (c = dfs(v, min(edge[i].w,flow))) != -1){
            edge[i].w -=c;
            edge[i^1].w += c;
            return c;
        }
    }
    return -1;
}

int main(){
    cin>>n;
    t = 8*n + 1;
    for(int i = 1; i <= 2 * n;i++){
        add(s,i,1);
        add(i,s,0);
    }
    for(int i=1;i<=n*2;i++){
        int a;
        cin>>a;
        add(i,a+4*n,10);
        add(a+4*n,i,0);
        cin>>a;
        add(i,a+4*n,10);
        add(a+4*n,i,0);
    }
    for(int i = 4*n + 1; i<=5*n;i++){
        add(i,t,2);
        add(t,i,0);
    }
    int c;
    while((c = dfs()) != -1){
        memset(vis, 0, sizeof(vis));
        ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}