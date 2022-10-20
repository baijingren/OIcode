#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,q;
int a[qwe];
vector<int> e[qwe];
int query(int l,int r){
    
}
queue<int> q;
void bfs(int u){
    
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs();
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d",query(l,r));
    }
    return 0;
}