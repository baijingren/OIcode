#include<bits/stdc++.h>
using namespace std;
const int qwe=2e5+1;
int n,m;
int f[qwe],d[qwe],num[qwe];
int fnd(int x){
    if(f[x]==x) return x;
    int fa=fnd(f[x]);
    d[x]+=d[f[x]];
    return f[x]=fa;
}
void merge(int u, int v){
    int x=fnd(u),y=fnd(v);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
    }
}