#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int w[qwe];
vector<int> e[qwe];
struct SegmentTree{
    struct Tree{
        int mx,tag;
    } t[qwe];
    void pushup(int rt){
        t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
    }
    void pushdown(int rt){
        t[rt<<1].tag=max(t[rt].tag,t[rt<<1].tag);
        t[rt<<1|1].tag=max(t[rt].tag,t[rt<<1|1].tag);
        t[rt<<1].mx=max(t[rt<<1].mx,t[rt].tag);
        t[rt<<1|1].mx=max(t[rt<<1|1].mx,t[rt].tag);
        t[rt].tag=0;
    }
    void change(int rt,int l,int r,int L,int R,int w){
        if(L<=l && R>=r){
            t[rt].mx=max(t[rt].mx,w);
            t[rt].tag=max(t[rt].tag,w);
            //
            return;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid){
            change(rt<<1,l,mid,L,R,w);
        }
        if(R>mid){
            change(rt<<1|1,mid+1,r,L,R,w);
        }
        pushup(rt);
    }
    int query(int rt,int l,int r,int p){
        if(l==r){
            return t[rt].mx;
        }
        int mid=(l+r)>>1;
        int ans=0;
        pushdown(rt);
        if(p<=mid){
            return query(rt<<1,l,mid,p);
        }
        if(p>mid){
            return query(rt<<1|1,mid+1,r,p);
        }
    }
} t;
int dfn[qwe],id[qwe],cnt=0;
int siz[qwe];
int fa[qwe];
void dfs(int u,int fa){
    dfn[u]=++cnt;
    id[cnt]=u;
    ::fa[u]=fa;
    siz[u]=1;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int vis[qwe];
int main(){
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    vis[1]=1;
    bool not_empty=0;
    for(int i=1;i<=m;i++){
        string s;
        int x;
        cin>>s>>x;
        if(s.compare("Query")==0){
            if(not_empty==0){
                cout<<"-1\n";
                continue;
            }
            cout<<t.query(1,1,n,dfn[x])<<'\n';
        }
        else if(s.compare("Modify")==0){
            not_empty=1;
            t.change(1,1,n,dfn[x],dfn[x]+siz[x]-1,w[x]);
            while(!vis[x]){
                t.change(1,1,n,dfn[fa[x]],dfn[x]-1,w[fa[x]]);
                t.change(1,1,n,dfn[x]+siz[x],dfn[fa[x]]+siz[fa[x]]-1,w[fa[x]]);
                vis[x]=1;
                x=fa[x];
            }
        }
    }
    return 0;
}