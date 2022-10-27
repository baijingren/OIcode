#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T,n,m;
int dfn[qwe],id[qwe],cnt=0;
int nxt[qwe];
vector<int> e[qwe];
void dfs(int u){
    dfn[++cnt]=u;
    id[u]=cnt;
    int nw=cnt;
    for(int v:e[u]){
        dfs(v);
        nxt[nw]=+=cnt;
        nw=cnt;
    }
    nxt[nw]=-1;
}
bool vis[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int k;
            for(int j=1;j<=k;j++){
                int x;
                cin>>x;
                e[i].push_back(x);
            }
        }
        cin>>m;
        int tmp=m;
        while(tmp){

        }
    }
    return 0;
}