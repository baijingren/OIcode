#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
typedef long long ll;
int n,m;
ll a[qwe];
struct Tree{
    int l,r;
    ll sum,ad;
} tree[4*qwe];
void pushup(int rt){
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
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
        tree[rt].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,ll d){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        tree[rt].sum+=(tree[rt].r-tree[rt].l+1)*d;
        // 错误：tree[rt].sum+=(r-l+1)*tree[rt].ad;
        tree[rt].ad+=d;
        return;
    }
    pushdown(rt);
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        update(rt<<1,l,r,d);
    }
    if(r>mid){
        update(rt<<1|1,l,r,d);
    }
    pushup(rt);
}
ll query(int rt,int l,int r){
    if(tree[rt].l>=l&&tree[rt].r<=r){
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid=(tree[rt].l+tree[rt].r)/2;
    ll sum=0;
    if(l<=mid){
        sum+=query(rt<<1,l,r);
    }
    if(r>mid){
        sum+=query(rt<<1|1,l,r);
    }
    return sum;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        ll q,x,y,z;
        scanf("%lld%lld%lld",&q,&x,&y);
        if(q==2){
            printf("%lld\n",query(1,x,y));
        }
        if(q==1){
            scanf("%lld",&z);
            update(1,x,y,z);
        }
    }
    return 0;
}