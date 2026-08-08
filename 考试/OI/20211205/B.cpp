#include<bits/stdc++.h>
using namespace std;
#define tr(i) tree[i].r
#define tl(i) tree[i].l
#define ts(i) tree[i].sum
#define tn(i) tree[i].num
const int qwe=1e6+5;
const int mod=998244353;
int n,m;
int a[qwe];
struct Tree{
    int l,r,num,sum;
} tree[qwe];
void pushup(int rt){
    ts(rt)=ts(rt<<1)+ts(rt<<1|1);
}
void build(int rt,int l,int r){
    tr(rt)=r;
    tl(rt)=l;
    if(l==r){
        ts(rt)=a[l];
        // pushup(rt);
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void change(int rt,int l,int r,bool w){
    for(int i=l;i<=r;i++){
        
    }
}
void changein(int rt,int l,int r){
    if(l>=tl(rt) && r<=tr(rt)){
        change(rt,l,r,0);
        return;
    }                                                                 
    int mid=(tr(rt)+tl(rt))>>1;
    if(l<mid){
        changein(rt<<1,l,r);
    }
    if(r>mid){
        changein(rt<<1|1,l,r);
    }
}
void changeback(int rt,int l,int r){
    if(l>=tl(rt) && r<=tr(rt)){
        change(rt,l,r,1);
        return;
    }
    int mid=tr(rt)+tl(rt)>>1;
    if(l<=mid){
        changeback(rt<<1,l,r);
    }
    if(r>mid){
        changeback(rt<<1|1,l,r);
    }
}
int query(int rt,int l,int r){
    if(l>=tl(rt) && r<= tr(rt)){
        return ts(rt)%mod;
    }
    int mid=tr(rt)+tl(rt)>>1;
    int ans=0;
    if(l<=mid){
        ans=(ans+query(rt<<1,l,r)%mod)%mod;
    }
    if(r>mid){
        ans=(ans+query(rt<<1|1,l,r)%mod)%mod;
    }
    return ans%mod;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    stack<int> la,ra;
    for(int i=1;i<=m;i++){
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        if(x==1){
            changein(1,l,r);
        }
        else if(x==2){
            printf("%d\n",query(1,l,r)%mod);
        }
        else if(x==3){
            changeback(1,la.top(),ra.top());
        }
    }
}