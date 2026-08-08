#include<bits/stdc++.h>
using namespace std;
// const int qwe=1e6+5;
const int N=5e4+5;
const int M=25;
int n,m,q;
int c[N];
bool win_or_lose[M][M];
vector<int> e[N];
bitset<N> son[N];
queue<int> qe,qb;
void dfs(int u,int fa){
    son[u][u]=1;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        son[u]=(son[u]|son[v]);
        // cerr<<'a';
        // for(int i=1;i<=n;i++){
        //     cerr<<son[u][i];
        // }
        // cerr<<endl;
    }
}
bool battle(int u,int p,int fa){
    while(!qe.empty() && !win_or_lose[qe.front()][c[u]]){
        qe.pop();
    }
    if(qe.empty()){
        return 0;
    }
    if(qe.size() && u==p){
        return 1;
    }
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        if(son[v][p]){
            return battle(v,p,u);
        }
    }
    return 0;
}
int main(){
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&win_or_lose[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cerr<<son[i][j];
    //     }
    //     cerr<<endl;
    // }
    for(int i=1;i<=q;i++){
        int k,p;
        scanf("%d%d",&k,&p);
        for(int i=1;i<=k;i++){
            // scanf("%d",&d[i]);
            int x;
            scanf("%d",&x);
            qe.push(x);
        }
        printf("%d\n",battle(1,p,0));
        while(!qe.empty()){
            qe.pop();
        }
    }
}