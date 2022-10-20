#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e5+5;
int n,m,siz,_q;
ll ans,tmp;
ll _a[qwe];
int a[qwe],p[qwe],L[qwe],R[qwe];
int t[qwe];
int cnt[qwe],cntt[qwe];
struct Q{
    int l,r,k;
} q[qwe];
void add(int x,ll &s){
    cnt[x]++;
    s=max(s,1ll*cnt[x]*t[x]);
}
void del(int x){
    cnt[x]--;
}
int main(){
    scanf("%d%d",&n,&_q);
    siz=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[++m]=a[i];
        p[i]=i/siz;
    }
    // build();
    for(int i=1;i<=_q;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].k=i;
    }
    sort(q+1,q+_q+1,[](Q x,Q y){
        return p[x.l]==p[y.l]?x.r<y.r:p[x.l]<p[y.l];
    });
    sort(t+1,t+m+1);
    m=unique(t+1,t+m+1)-(t+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(t+1,t+m+1,a[i])-t;
    }
    int l=1,r=0,la=0,lb;
    for(int i=1;i<=_q;i++){
        if(p[q[i].l]==p[q[i].r]){
            for(int j=q[i].l;j<=q[i].r;j++){
                ++cntt[a[j]];
            }
            for(int j=q[i].l;j<=q[i].r;j++){
                _a[q[i].k]=max(_a[q[i].k],1ll*t[a[j]]*cntt[a[j]]);
            }
            for(int j=q[i].l;j<q[i].r;j++){
                --cntt[a[j]];
            }
            continue;
        }
        if(p[q[i].l]!=la){
            while(r>((p[q[i].l]+1)*siz)) del(a[r--]);
            while(l<((p[q[i].l]+1)*siz+1)) del(a[l++]);
            ans=0;
            la=p[q[i].l];
        }
        while(r<q[i].r) add(a[++r],ans);
        lb=l;
        tmp=ans;
        while(lb>q[i].l) add(a[--lb],tmp);
        _a[q[i].k]=tmp;
        while(lb<l) del(a[lb++]);
    }
    for(int i=1;i<=_q;i++){
        printf("%lld\n",_a[i]);
    }
    return 0;
}