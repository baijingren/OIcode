#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,q;
int a[qwe];
struct Node{
    int l,r,mx;
} tree[qwe];
#define tl(i) tree[i].l
#define tr(i) tree[i].r
#define tm(i) tree[i].mx
void pushup(int rt){
    tm(rt)=max(tm(rt<<1),tm(rt<<1|1));
}
void build(int rt,int l,int r){
    tl(rt)=l;
    tr(rt)=r;
    // if(l==r){
        // tm(rt)=a[l];
    // }
    tm(rt)=0;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    // pushup(rt);
}
void change(int rt,int l,int r,int w){

}
int query(int rt,int l,int r){

}
struct Node{
    int l,r,id;
} v[qwe];
int main(){
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&v[i].l, &v[i].r);
        v[i].id=i;
        printf("1\n");
    }
    sort(v+1,v+n+1,[](Node x,Node y){
        return x.r<y.r;
    });
    build(1,1,n);
}