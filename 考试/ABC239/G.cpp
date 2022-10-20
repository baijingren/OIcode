#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe];
vector<int> e[qwe];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    return 0;
}