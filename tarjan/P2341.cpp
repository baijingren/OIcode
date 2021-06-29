#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int n,m,hd[qwe],cnt=0,vis[qwe],dnf[qwe],low[qwe],r;
struct EDGE{
    int nxt,to;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
    return;
}
stack<int> s;
void tarjan(int x){
    dnf[x]=low[x]=++r;
    vis[x]=1;
    s.push(x);
    for(int i=hd[x];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dnf[v]){
            tarjan(v);
        }else if(vis[i]){
            low[x]=min(dnf[v],low[x]);
        }
    }
    if(dnf[x]==low[x]){
        
    }
}
int main(){
    scanf("%d %d", &n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
    }
}