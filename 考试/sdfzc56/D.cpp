#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,T;
vector<int> e[qwe];
int a[qwe],b[qwe];
void dfs(int u,int fa){
    
}
void init(){
    memset(c,0,sizeof(c));

}
int main(){
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",b+i);
        }
        dfs(1,0);
    }
}