#include<bits/stdc++.h>
using namespace std;
#define int long long
const int qwe=1e6+5;
int n,cnt,num;
int ans[qwe*2],s[qwe];
vector<int> _ans_;
struct Node{
    int op,l,r,a,w,b;
    bool tag;
} a[qwe];
struct Tree{
    int l,r,num;
} t[qwe*4];
// void pushup(int rt){

// }
void build(int rt,int l,int r){
    t[rt].l=l;
    t[rt].r=r;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    // pushup(rt);
}
void change(int rt,int l,int r,int w){
    if(l<=t[rt].l && r>=t[rt].r){
        t[rt].num^=w;
        return;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid){
        change(rt<<1,l,r,w);
    }
    if(r>mid){
        change(rt<<1|1,l,r,w);
    }
}
void query(int rt,int w){
    w^=t[rt].num;
    if(t[rt].l==t[rt].r){
        ans[t[rt].l]=w;
        return;
    }
    query(rt<<1,w);
    query(rt<<1|1,w);
}
signed main(){
    s[++cnt]=-1e9;
    s[++cnt]=0;
    s[++cnt]=1e9;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].op);
        if(a[i].op==1){
            scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].w);
            s[++cnt]=a[i].l;
            s[++cnt]=a[i].r;
            s[++cnt]=a[i].l-1;
            s[++cnt]=a[i].r+1;
        }
        else if(a[i].op==2){
            scanf("%lld%lld",&a[i].a,&a[i].w);
            s[++cnt]=a[i].a;
            s[++cnt]=a[i].a-1;
            s[++cnt]=a[i].a+1;
        }
        else{
            scanf("%lld%lld",&a[i].b,&a[i].w);
            s[++cnt]=a[i].b;
            s[++cnt]=a[i].b-1;
            s[++cnt]=a[i].b+1;
        }
    }
    sort(s+1,s+cnt+1);
    num=(unique(s+1,s+cnt+1)-s-1);
    build(1,1,num);
    for(int i=1;i<=n;i++){
        if(a[i].op==1){
            int l=lower_bound(s+1,s+num+1,a[i].l)-s;
            int r=lower_bound(s+1,s+num+1,a[i].r)-s;
            change(1,l,r,a[i].w);
        }
        else if(a[i].op==2){
            int x=lower_bound(s+1,s+num+1,a[i].a)-s;
            change(1,x,x,a[i].w);
        }
        else if(a[i].op==3){
            int x=lower_bound(s+1,s+num+1,a[i].b)-s;
            // change(1,x,x,a[i].w);
            if(x>1){
                change(1,1,x-1,a[i].w);
            }
            if(x<num){
                change(1,x+1,num,a[i].w);
            }

        }
    }
    query(1,0);
    int _ans=0;
    for(int i=1;i<=num;i++){
        if(ans[i]>_ans){
            _ans=ans[i];
            _ans_.clear();
            _ans_.push_back(s[i]);
        }
        else if(ans[i]==_ans){
            _ans_.push_back(s[i]);
        }
    }
    printf("%lld ",_ans);
    _ans=LONG_LONG_MIN+1;
    for(auto v:_ans_){
            // cout<<v<<' '<<_ans<<' '<<abs(v)<<' '<<abs(_ans);
        if(abs(v)<abs(_ans)){
            _ans=v;
        }
        else if(abs(v)==abs(_ans)){
            _ans=max(_ans,v);
        }
        // cout<<v<<' ';
    }
    printf("%lld",_ans);
    // build(1,1,n);
    return 0;
}