#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define R(x) min(pos[x]*len,n)
const int qwe=1e6+5;
int n,m,len,k,a_len;
int a[qwe],pos[qwe],t[qwe];
int cnt[qwe],cnt_2[qwe];
ll ans[qwe];
struct Node{
    int l,r,id;
};
Node b[qwe];
void add(int x,ll ans){
    cnt[x]++;
    ans=max(ans,1ll*cnt[x]*t[x])
}
void del(int x){
    cnt[x]--;
}
void calc(int l,int r,int p){
    for(int i=l;i<=r;i++){
        cnt_2[a[i]]++;
    }
    for(int i=l;i<=r;i++){
        ans[p]=max(ans[p],(1ll*cnt_2[a[i]]*t[a[i]]));
    }
    for(int i=l;i<=r;i++){
        cnt_2[a[i]]--;
    }
}
int main(){
    scanf("%d",&n);
    a_len=0;
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[++a_len]=a[i];
        pos[i]=(i-1)/len+1;
    }
    k=pos[n];
    // sort(a+1,a+n+1);
    sort(t+1,t+a_len+1);
    a_len=unique(t+1,t+a_len+1)-(t+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(t+1,t+a_len+1,a[i])-t;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i].l,&b[i].r);
        b[i].id=i;
    }
    sort(b+1,b+m+1,[](Node x,Node y){
        return x.l==y.l?x.r<y.r:pos[x.l]<pos[y.l];
    });
    int l,r,last_blocks=0;
    for(int i=1;i<=m;i++){
        if(pos[b[i].l]==pos[b[i].r]){
            calc(b[i].l,b[i].r,b[i].id);
            continue;
        }
        if(pos[b[i].l]!=last_blocks){
            while(r>R(b[i].l)){
                del(a[r--]);
            }
            while(l<R(b[i].l)+1){
                del(a[l++]);
            }
            ans=0;
            last_blocks=pos[b[i].l];
        }
        while(r<b[i].r){
            add(a[++r],ans);
        }
        while(l>b[i].l){
            add()
        }
    }
}