#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe],f[qwe];
int fnd(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=fnd(f[x]);
}
void merge(int x,int y){
    int u=fnd(x),v=fnd(y);
    if(u==v){
        return;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
    }
}