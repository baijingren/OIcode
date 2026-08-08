#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define MP make_pair
const int qwe=1e6+5;
int n,m;
vector<PII> e[qwe];
int siz[qwe];
void dfs(int u,int fa){
    for(auto V:e[u]){
        int v=V.first;
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
    int sum=1;
    for(auto V:e[u]){
        int v=V.first;
        if(v==fa){
            continue;
        }
        int to=min(m,siz[v]);
        for(int i=sum;i>=0;i--){
            for(int j=to;j>=0;j--){
                
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[a].push_back(MP(b,c));
        e[b].push_back(MP(a,c));
    }
    for(int i=1;i<=n;i++){
        
    }
}