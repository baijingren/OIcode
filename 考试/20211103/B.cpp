#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n, m, cnt=0,ans;
int hd[qwe], num[qwe];
// bool vis[qwe];
bitset<qwe> vis;
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    hd[u]=cnt;
}
void dfs(int u,bool y){
    for(int i=hd[u];i;i++){
        int v=edge[i].to;
        if(y==1){
            if(vis[v]) continue;
        }
        vis[v]=1;
        num[v]=num[u]+1;
        ans=max(ans,num[v]);
        dfs(v,y);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    printf("%d ",ans);
    dfs(1,1);
    printf("%d",ans);
    return 0;
}