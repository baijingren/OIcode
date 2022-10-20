#include<bits/stdc++.h>
using namespace std;
const int qwe=3e6+5;
int n,x,y,ans;
vector<int> e[qwe];
int ed[qwe];
int fst,sed,flg;
int dfn[qwe],id[qwe],cnt=0;
void dfs(int u,int fa){
    dfn[u]=++cnt;
    id[cnt]=u;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x>>y;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        ed[u]++;
        ed[v]++;
    }
    for(int i=1;i<=n;i++){
        if(ed[i]==1){
            if(!fst){
                fst=i;
            }
            else{
                sed=i;
            }
        }
    }
    dfs(fst,0);
    fst=dfn[fst],sed=dfn[sed];
    x=dfn[x],y=dfn[y];
    if(x>y){
        swap(x,y);
    }
    if(x==fst){
        flg++;
    }
    if(y==sed){
        flg++;
    }
    if(flg==0){
        // ans=ceil(1.0*(n-2)/4);
        ans=max(n-y,y-(x+y)/2+(((x+y)%2)));
        ans=max(ans,x-1);
        // cerr<<"DEBUG:"<<(((x+y)%2))<<endl;
    }
    else if(flg==1){
        if(x==fst){
            ans=max(x-1,y-(x+y)/2+(((x+y)%2)));
        }
        else{
            ans=max(n-y,y-(x+y)/2+(((x+y)%2)));
        }
    }
    else if(flg==2){
        ans=ceil(1.0*(n-2)/2);
    }
    cout<<ans<<endl;
}