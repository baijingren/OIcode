#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
int a[qwe],in[qwe],out[qwe];
vector<int> e[qwe];
void dfs(int u){

}
queue<int> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        // scanf("%d",&a[i]);
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        in[v]++;
        out[u]++;
    }
    for(int i=1;i<=n;i++){
        if()
    }
}