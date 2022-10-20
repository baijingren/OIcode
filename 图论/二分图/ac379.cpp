#include<bits/stdc++.h>
using namespace std;
const int qwe=205;
int n,m,ans;
int ma[qwe*2];
bool vis[qwe*2];
bitset<qwe*2> e[qwe*2];
bool dfs(int u){
    for(int v=1;v<=n;v++){
        if(e[u][v]==1){
            if(vis[v]) continue;
            vis[v]=1;
            // dfs(v);
            if(!ma[v]||dfs(ma[v])){
                ma[v]=u;
                return 1;
            }

        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(e[i][k]&&e[k][j]){
                    e[i][j]=1;
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(e[i][j]){
    //             e[i][j+n]=1;
    //             e[i][j]=0;
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)){
            ans++;
        }
    }
    printf("%d",n-ans);
}