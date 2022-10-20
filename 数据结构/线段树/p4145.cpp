#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe=100005;
ll n,m;
ll a[qwe];
struct tree{
    ll l,r,sm,mx;
} tree[qwe*4];
void pushup(int rt){
    tree[rt].sm=tree[rt<<1].sm+tree[rt<<1|1].sm;
    tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}
void build(int rt,int l,int r){
    tree[rt].l=l,tree[rt].r=r;
    if(l==r){
        tree[rt].sm=a[l];
        tree[rt].mx=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r){
    if(tree[rt].mx<=1){//考虑全是0的情况
        return;
    }
    if(tree[rt].l==tree[rt].r){
        tree[rt].sm=sqrt(tree[rt].sm);
        tree[rt].mx=sqrt(tree[rt].mx);
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)/2;//不是(l+r)/2
    if(l<=mid){//此处两个if分开写，因为这里要考虑跨过现有边界的可能性；
        update(rt<<1,l,r);//此处区间不能更改
    }
    if(r>mid){
        update(rt<<1|1,l,r);
    }
    pushup(rt);
}
ll query(int rt,int l,int r){
    if(l<=tree[rt].l&&r>=tree[rt].r){
        return tree[rt].sm;//此处直接返回即可，不需要累加至sum
    }
    int mid=(tree[rt].l+tree[rt].r)/2;
    long long sum=0;
    if(l<=mid){
        sum+=query(rt<<1,l,r);
    }
    if(r>mid){
        sum+=query(rt<<1|1,l,r);
    }
    return sum;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        ll k,l,r;
        scanf("%lld%lld%lld",&k,&l,&r);
        if(l>r) swap(l,r);
        if(k==2){
            update(1,l,r);
        }
        else{
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}