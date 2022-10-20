#include<bits/stdc++.h>
using namespace std;
const int qwe=3e5+5;
typedef long long ll;
int n,cnt=0,dfn=0,q;
int hd[qwe],dep[qwe],size[qwe],fa[qwe],son[qwe],tp[qwe],id[qwe];
ll a[qwe],w[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
struct Tree{
    int l,r;
    ll mx,sum;
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
        fa[v]=u;
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
void change(int rt,int l,ll d){
    // if(l<=tree[rt].l&&tree[rt].r<=l){
    if(tree[rt].l==tree[rt].r){
        tree[rt].mx=d;
        tree[rt].sum=d;
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        change(rt<<1,l,d);
    }
    else{
        change(rt<<1|1,l,d);
    }
    pushup(rt);
}
ll query_max(int rt,int l,int r){
    if(l<=tree[rt].l&&tree[rt].r<=r){
        return tree[rt].mx;
    }
    ll ans=INT_MIN;
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        ans=max(ans,query_max(rt<<1,l,r));
    }
    if(r>mid){
        ans=max(ans,query_max(rt<<1|1,l,r));
    }
    return ans;
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
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    dep[1]=1,dfs1(1,0);
    tp[1]=1,dfs2(1,0);
    build(1,1,n);
    scanf("%d",&q);
    char s[15];
    int l,r;
    for(int i=1;i<=q;i++){
        scanf("%s%d%d",s,&l,&r);
        if(s[1]=='H'){
            change(1,id[l],r);//id[l]-->l
        }
        if(s[1]=='M'){
            ll ans=INT_MIN;
            while(tp[l]!=tp[r]){
                if(dep[tp[l]]<dep[tp[r]]){
                    swap(l,r);
                }
                ans=max(ans,query_max(1,id[tp[l]],id[l]));
                l=fa[tp[l]];//错误:l=tp[l];
            }
            if(dep[l]>dep[r]){
                swap(l,r);
            }
            ans=max(ans,query_max(1,id[l],id[r]));
            printf("%d\n",ans);
        }
        if(s[1]=='S'){
            ll ans=0;
            while(tp[l]!=tp[r]){
                if(dep[tp[l]]<dep[tp[r]]){
                    swap(l,r);
                }
                ans+=query_sum(1,id[tp[l]],id[l]);
                l=fa[tp[l]];//错误:l=tp[l];
            }
            if(dep[l]>dep[r]){
                swap(l,r);
            }
            ans+=query_sum(1,id[l],id[r]);
            printf("%d\n",ans);
        }
    }
    return 0;
}