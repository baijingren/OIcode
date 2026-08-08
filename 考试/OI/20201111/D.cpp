#include<bits/stdc++.h>
using namespace std;
#define nxt(i) edge[i].nxt
#define to(i) edge[i].to
const int qwe=1e6+5;
int n,cnt=0,ans=0;
int hd[qwe];
bool vis[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}
int dfs(int u,int fa){
    int w=-1;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(v==fa) continue;
        int k=dfs(v,u);
        if(k==-1){
            w=1;
        }
        if(k==1&&w!=1){
            w=0;
        }
    }
    if(w==1) ans++;
    return w;
}
int main(){
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    if(dfs(1,0)==-1){//
        ans++;
    }
    printf("%d",ans);
}