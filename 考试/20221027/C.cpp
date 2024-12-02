#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T,n,m;
int dfn[qwe],id[qwe],cnt=0;
int nxt[qwe];
int fa[qwe];
vector<int> e[qwe];
void dfs(int u){
    dfn[++cnt]=u;
    id[u]=cnt;
    int nw=cnt;
    for(int v:e[u]){
        dfs(v);
        nxt[nw]=++cnt;
        nw=cnt;
    }
    nxt[nw]=-1;
}
int v[qwe];
int main(){
    freopen("bill.in","r",stdin);
    freopen("bill.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            e[i].clear();
            for(int j=1;j<=k;j++){
                int x;
                cin>>x;
                e[i].push_back(x);
                fa[x]=i;
            }
        }
        memset(v,0,sizeof(v));
        cnt=0;
        int ans=0,temp=0;
        cin>>m;
        int tmp=m;
        dfs(1);
        while(tmp){
            v[id[tmp]]=1;
            tmp=fa[tmp];
        }
        while(m){
            for (int i=id[m];i!=-1;i=nxt[i]){
                if(i>temp){
                    ans+=v[i-temp];
                    v[i-temp]=0;
                }
            }
            m=fa[m];
            temp++;
        }
        cout<<ans<<endl;
    }
    return 0;
}