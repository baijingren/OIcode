#include<bits/stdc++.h>
using namespace std;
const int qwe=1000005;
typedef long long ll;
int n,m;
int a[qwe],b[qwe];
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
struct Tree{
    int l,r;
    ll gcd,sum;
} tree[qwe*4];
void pushup(int rt){
    tree[rt].gcd=gcd(tree[rt<<1].gcd,tree[rt<<1|1].gcd);
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
void build(int rt,int l,int r){
    tree[rt].l=l,tree[rt].r=r;
    if(l==r){
        tree[rt].gcd=b[l];
        tree[rt].sum=b[l];
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void change(int rt,int l,ll ad){//此处不必修改区间
    if(tree[rt].l==tree[rt].r){
        tree[rt].sum+=ad;
        tree[rt].gcd+=ad;
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        change(rt<<1,l,ad);
    }
    else{//一并修改
        change(rt<<1|1,l,ad);
    }
    pushup(rt);
}
ll query_one(int rt,int l,int r){
    if(l<=tree[rt].l&&r>=tree[rt].r){
        return tree[rt].sum;
    }
    int mid=(tree[rt].l+tree[rt].r)/2;
    ll sum=0;
    if(l<=mid){
        sum+=query_one(rt<<1,l,r);
    }
    if(r>mid){
        sum+=query_one(rt<<1|1,l,r);
    }
    return sum;
}
ll query_gcd(int rt, int l, int r){
     if(l<=tree[rt].l&&r>=tree[rt].r) return tree[rt].gcd;
     int mid=(tree[rt].l+tree[rt].r)/2;
     ll lg=0,rg=0;
     if(l<=mid)
         lg=query_gcd(rt<<1,l,r);
     if(r>mid)
         rg=query_gcd(rt<<1|1,l,r);
     return gcd(lg,rg);
 }
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        char C;
        int l,r,d;
        scanf(" %c%lld%lld",&C,&l,&r);
        if(C=='C'){
            int d;
            scanf("%lld",&d);
            change(1,l,d);
            if(r + 1 <= n)
                 change(1, r+1, -d);
        }
        if(C=='Q'){
            ll t=query_one(1,1,l);
            printf("%lld\n",abs(gcd(t,query_gcd(1,l+1,r))));
            // cout<<endl<<t<<' '<<query_gcd(1,l+1,r)<<endl;
        }
    }
    return 0;
}