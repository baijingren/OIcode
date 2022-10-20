#include<bits/stdc++.h>
using namespace std;

const int qwe=4e6+5;
int n,m;
vector<int> e[qwe];
int d[qwe];

int num=0,cnt=0;
int dfn[qwe],low[qwe];
bool vis[qwe];
vector<int> scc[qwe];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++num;
    s.push(u);
    vis[u]=1;
    for(auto v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        cnt++;
        int v;
        do{
            v=s.top();
            s.pop();
            vis[v]=0;
            d[v]=cnt;
            scc[cnt].push_back(v);
        }while(u!=v);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&x,&b,&y);
        e[a+n*(x&1)].push_back(b+n*(!y));
        e[b+n*(y&1)].push_back(a+n*(!x));
    }
    // tarjan(1);
    for(int i=1;i<=n*2;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]==d[i+n]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    for(int i=1;i<=n;i++){
        printf("%d ",d[i]<d[i+n]?1:0);  
    }
    return 0;
}