#include<bits/stdc++.h>
using namespace std;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
const int qwe=5e5+5;
int n,t,ans=0,cnt=0;
int hd[qwe],ma[qwe];
bool vis[qwe];
bool mp[205][205];
int mv[2][4]{
    {1,-1,0,0},
    {0,0,1,-1}
};
struct Node{
    int x,y;
} a[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}
bool dfs(int u){
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(!vis[v]){
            vis[v]=1;
            if(!ma[v]||dfs(ma[v])){
                ma[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        // scanf("%d%d",&a[i].x,&a[i].y);
        mp[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==1||mp[i][j]){
                continue;
            }
            for(int k=0;k<4;k++){
                int x=i+mv[0][k],y=j+mv[1][k];
                if(x<=0 || y<=0 || x>n || y>n || mp[x][y]) continue;
                add((i-1)*n+j,(x-1)*n+y);
            }
        }
    }
    // for(int i=1;i<=n*n;i++){
    //     if(dfs(i)){
    //         ans++;
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==1) continue;
            memset(vis,0,sizeof(vis));
            if(dfs((i-1)*n+j)){
                ans++;
            }
        }
    }
    printf("%d",ans);
}