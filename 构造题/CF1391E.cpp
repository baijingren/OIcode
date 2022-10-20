#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,T;
vector<int> e[qwe];
void dfs(int u){
    
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
    }
}