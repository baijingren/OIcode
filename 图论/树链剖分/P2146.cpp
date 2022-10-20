#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
typedef long long ll;
int n,cnt=0,dfn=0,q;
int hd[qwe],dep[qwe],size[qwe],fa[qwe],son[qwe],tp[qwe],id[qwe];
ll a[qwe],w[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
struct Tree{
    int l,r;
    ll mx,sum,ad;
} tree[4*qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
void dfs1(int u,int f){//求父节点，重子节点，子树大小，深度
    size[u]=1;
    int mx=0;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        // fa[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v,u);
        if(size[v]>mx){
            mx=size[v];
            son[u]=v;
        }
        size[u]+=size[v];
    }
}
void dfs2(int u,int f){//求重链
    a[++dfn]=w[u];
    id[u]=dfn;
    if(son[u]){
        tp[son[u]]=tp[u];
        dfs2(son[u],u);
    }
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        if(v!=son[u]){
            tp[v]=v;
            dfs2(v,u);
        }
    }
}
void pushup(int rt){
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
    tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}
void pushdown(int rt){
    if(tree[rt].ad){
        ll tad=tree[rt].ad;
        int a=(rt<<1),b=(rt<<1|1);
        tree[a].ad+=tad;//少+
        tree[b].ad+=tad;//同上
        tree[a].sum+=(tree[a].r-tree[a].l+1)*tad;
        tree[b].sum+=(tree[b].r-tree[b].l+1)*tad;
        tree[rt].ad=0;
    }
}
void build(int rt,int l,int r){
    tree[rt].l=l,tree[rt].r=r;
    if(l==r){
        tree[rt].mx=a[l];
        tree[rt].sum=a[l];
            return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void change(int rt,int l,int r,bool b){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        if(b){
            tree[rt].sum+=(tree[rt].r-tree[rt].l+1)*1;
            tree[rt].ad+=1;
        }
        else{
            tree[rt].sum+=(tree[rt].r-tree[rt].l+1)*(-1);
            tree[rt].ad+=(-1);
        }
        return;
    }
    
}
ll query_sum(int rt,int l,int r){
    if(l<=tree[rt].l&&tree[rt].r<=r){
        return tree[rt].sum;
    }
    ll ans=0;
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        ans+=query_sum(rt<<1,l,r);
    }
    if(r>mid){
        ans+=query_sum(rt<<1|1,l,r);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&fa[i]);
        add(i,fa[i]);
        add(fa[i],i);
    }
    scanf("%d",&q);
    char s[10];
    int l;
    for(int i=1;i<=q;i++){
        scanf("%s%d",s,&l);
        if(s[1]=='i'){
            ll ans=0;
            // query_sum(1,0,l);
            while(tp[0]!=tp[l]){
                ans+=query_sum(1,id[tp[l]],id[l]);
                change(1,id[tp[l]],id[l],1);
                l=fa[tp[l]];
            }
            ans+=query_sum(1,id[0],id[l]);
            printf("%d\n",ans);
            change(1,id[0],id[l],1);
            // change(1,l,1);
        }
        if(s[1]='u'){
            ll ans=size[l]-query_sum(1,id[l],id[l]+size[l]-1);
            change(1,id[l],id[l]+size[l]-1,0);
            printf("%d",ans);
        }
    }
}