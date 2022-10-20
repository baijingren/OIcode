#include<bits/stdc++.h>
using namespace std;
const int qwe=200005;
int t,n,m,cnt=1,tot;
int hd[qwe],du[qwe],ans[qwe];
bool vis[qwe],f[qwe];
stack<int> s;
struct EDGE{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
    return;
}
void dfs(int u,int in){
    for(int i=hd[u];i;i=edge[i].nxt){
        if(f[i]) continue;
        int v=edge[i].to;
        // hd[u]=edge[i].nxt;
        f[i]=f[i^1]=1;
        dfs(v,i);
        // i=hd[u];
    }
    // s.push(u);
    ans[++tot]=in;
    return;
}
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    int p;
    scanf("%d",&t);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        du[u]++;
        if(t==1){
            add(v,u);
            du[v]++;
        }else if(t==2){
            cnt++;
        }
        if(i==1) p=u;
    }
    dfs(p,1);
    for(int i=1;i<=m;i++){
        if(f[i]){
            printf("NO\n");
            return 0;
        }
    }
}