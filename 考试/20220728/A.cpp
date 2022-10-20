#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
vector<int> e[qwe];
int dfn[qwe],low[qwe];
int cnt=0,ans=0;
void tarjan(int u, int fa)
{
    dfn[u]=low[u]=++cnt;
    for(int v:e[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans++;
            }
        }
        else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void init(){
    ans=0;
    cnt=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        init();
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i,0);
            }
        }
        cout<<ans<<'\n';
    }
}