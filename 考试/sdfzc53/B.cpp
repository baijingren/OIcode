#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int edge[qwe],ans[qwe],cntt=0;
vector<int> e[qwe];
int cnt=0,num=0;
int dfn[qwe],low[qwe];
stack<int> s;
vector<int> dcc[qwe];
bool c[qwe];
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    int flag=0;
    for(auto v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
            if(low[v]>=dfn[u]){
                flag++;
                if(u!=1 || flag>1){
                    c[u]=1;
                }
                num++;
                int k;
                do{
                    k=s.top();
                    s.pop();
                    dcc[num].push_back(k);
                }while(v!=k);
                dcc[num].push_back(u);
            }
        }
        else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-'){
            y=-1;
        }
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*y;
}
int main(){
    // scanf("%d%d",&n,&m);
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int u,v;
        // scanf("%d%d",&u,&v);
        u=read();
        v=read();
        edge[v]++;
        edge[u]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(n-1>m){
        for(int i=1;i<=n;i++){
            if(edge[i]==0){
                cntt++;
                ans[cntt]=i;
            }
        }
    }
    int k=m-(n-2);
    tarjan(1);
    for(int i=1;i<=num;i++){
        for(int v:dcc[i]){
            if(!c[v]){
                if(edge[v]==k){
                    ans[++cntt]=v;
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     // for(int j:dcc[i]){
    //     //     printf("%d ",j);
    //     // }
    //     // printf("\n");
    //     printf("%d ",c[i]);
    // }
    // cout<<endl;
    sort(ans+1,ans+cntt+1);
    printf("%d\n",cntt);
    for(int i=1;i<=cntt;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}