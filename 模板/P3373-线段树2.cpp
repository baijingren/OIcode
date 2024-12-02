#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,p;
int a[qwe];
struct SegmentTree{
    struct Tree{
        int num,add,mul,len;
    } t[qwe];
    void pushup(int rt){
        t[rt].num=(t[rt<<1].num+t[rt<<1|1].num)%p;
    }
    void pushdown(int rt){
        if(t[rt].mul!=1){//对于乘法，需要对加法同时修改，并且要注意数据范围，以免炸int
            t[rt<<1].num=(1ll*t[rt<<1].num*t[rt].mul)%p;
            t[rt<<1].mul=(1ll*t[rt].mul*t[rt<<1].mul)%p;
            t[rt<<1|1].num=(1ll*t[rt<<1|1].num*t[rt].mul)%p;
            t[rt<<1|1].mul=(1ll*t[rt].mul*t[rt<<1|1].mul)%p;
            t[rt<<1].add=(1ll*t[rt<<1].add*t[rt].mul)%p;
            t[rt<<1|1].add=(1ll*t[rt<<1|1].add*t[rt].mul)%p;
            t[rt].mul=1;
        }
        if(t[rt].add){
            t[rt<<1].num=(t[rt<<1].num+1ll*t[rt<<1].len*t[rt].add%p)%p;
            t[rt<<1].add+=t[rt].add;
            t[rt<<1|1].num=(t[rt<<1|1].num+1ll*t[rt<<1|1].len*t[rt].add%p)%p;
            t[rt<<1|1].add+=t[rt].add;
            t[rt].add=0;
        }
    }
    void build(int rt,int l,int r){
        t[rt].len=r-l+1;
        t[rt].mul=1;
        if(l==r){
            t[rt].num=a[l];
            // cerr<<"A:"<<t[rt].num<<endl;
            return;
        }
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void change_add(int rt,int l,int r,int L,int R,int w){
        if(L<=l && R>=r){
            t[rt].add=(t[rt].add+w)%p;
            t[rt].num=(t[rt].num+1ll*t[rt].len*w%p)%p;
            // cerr<<"A:"<<t[rt].num<<endl;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid){
            change_add(rt<<1,l,mid,L,R,w);
        }
        if(R>mid){
            change_add(rt<<1|1,mid+1,r,L,R,w);
        }
        pushup(rt);
    }
    void change_mul(int rt,int l,int r,int L,int R,int w){
        if(L<=l && R>=r){
            t[rt].add=(1ll*t[rt].add*w)%p;
            t[rt].mul=(1ll*t[rt].mul*w)%p;
            t[rt].num=(1ll*t[rt].num*w)%p;
            // cerr<<"A:"<<t[rt].num<<endl;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid){
            change_mul(rt<<1,l,mid,L,R,w);
        }
        if(R>mid){
            change_mul(rt<<1|1,mid+1,r,L,R,w);
        }
        pushup(rt);
    }
    int query(int rt,int l,int r,int L,int R){
        if(L<=l && R>=r){
            return t[rt].num;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        int ans=0;
        if(L<=mid){
            ans=(ans+query(rt<<1,l,mid,L,R))%p;
        }
        if(R>mid){
            ans=(ans+query(rt<<1|1,mid+1,r,L,R))%p;
        }
        return ans;
    }
} t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // cerr<<a[i]<<endl;
    }
    t.build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1){
            cin>>k;
            t.change_mul(1,1,n,x,y,k);
        }
        else if(op==2){
            cin>>k;
            t.change_add(1,1,n,x,y,k);
        }
        else{
            cout<<t.query(1,1,n,x,y)<<'\n';
        }
    }
    return 0;
}