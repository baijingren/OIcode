#include<bits/stdc++.h>
using namespace std;
#define tl(rt) tree[rt].l
#define tr(rt) tree[rt].r
#define trn(rt) tree[rt].rnum
#define tln(rt) tree[rt].lnum
#define tmn(rt) tree[rt].mnum
#define tn(rt) tree[rt].num
const int qwe=1e6+5;
int n,m;
int a[qwe];
struct Tree{
    int l,r,lnum,rnum,mnum,num;
} tree[qwe*5];
void pushup(int rt){
    tln(rt)=max(tln(rt<<1),tln(rt<<1|1)+tn(rt<<1));
    trn(rt)=max(trn(rt<<1|1),trn(rt<<1)+tn(rt<<1|1));
    tmn(rt)=max(max(tmn(rt<<1),tmn(rt<<1|1)),tln(rt<<1|1)+trn(rt<<1));
    tmn(rt)=max(max(tln(rt),trn(rt)),tmn(rt));
    tn(rt)=tn(rt<<1)+tn(rt<<1|1);
}
void build(int rt,int l,int r){
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r){
        tree[rt].lnum=a[l];
        tree[rt].mnum=a[l];
        tree[rt].rnum=a[l];
        tree[rt].num=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
    // return;
}
void change(int rt,int p,int x){
    if(tl(rt)==p && tr(rt)==p){
        tln(rt)=x;
        trn(rt)=x;
        tmn(rt)=x;
        tn(rt)=x;
        // pushup(rt);
        return;
    }
    int mid=(tl(rt)+tr(rt))/2;
    if(mid<p){
        change(rt<<1|1,p,x);
    }
    else{
        change(rt<<1,p,x);
    }
    pushup(rt);
}
Tree query(int rt,int l,int r){
    if(tl(rt)>=l && tr(rt)<=r){
    // if(tree[rt].l>=l&&tree[rt].r<=r){
        // return max(tln(rt),max(tmn(rt),trn(rt)));
        return tree[rt];
    }
    // Tree ans;
    // int mid=(tl(rt)+tr(rt))/2;
    if(l>tr(rt<<1)){
        return query(rt<<1|1,l,r);
    }
    if(r<tl(rt<<1|1)){
        return query(rt<<1,l,r);
    }
    Tree L,R,M;
    L=query(rt<<1,l,r),R=query(rt<<1|1,l,r);
    M.lnum=max(L.lnum,R.lnum+L.num);
    M.rnum=max(R.rnum,L.rnum+R.num);
    M.mnum=max(max(L.mnum,R.mnum),L.rnum+R.lnum);
    M.mnum=max(M.mnum,max(M.lnum,M.rnum));
    M.num=L.num+R.num;
    // if(mid>=l&&mid<r){
    //     ans+=query(rt<<1|1,l,r);
    // }
    // else{
    //     ans+=query(rt<<1,l,r);
    // }
    return M;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int c,x,y;
        scanf("%d%d%d",&c,&x,&y);
        if(c==1){
            if(x>y){
                swap(x,y);
            }
            printf("%d",query(1,x,y).mnum);
            // q.push(query(1,x,y));
        }
        if(c==2){
            change(1,x,y);
        }
    }
}