#include<bits/stdc++.h>
using namespace std;
const int qwe=2e6+5;
int n,m;
int a[qwe];
class Tree{
    int cnt;
public:
    struct T{
        int ch[2],l,r,sum;
    } tree[qwe];
    void pushup(int rt){
        tree[rt].sum=(tree[tree[rt].ch[0]].sum+tree[tree[rt].ch[1]].sum);
    }
    int build(int l,int r){
        int rt=++cnt;
        tree[rt].l=l;
        tree[rt].r=r;
        if(l==r){
            tree[rt].sum=a[l];
            return rt;
        }
        int mid=(l+r>>1);
        tree[rt].ch[0]=(l,mid);
        tree[rt].ch[1]=(mid+1,r);
        pushup(rt);
        return rt;
    }
    void change(int root,int loc,int w){
        int rt=++cnt;
        tree[rt]=tree[root];
        // t[rt].sum++;
    }
    int query(int rt,int loc){

    }
};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int opt,vi;
        scanf("%d",&vi,&opt);
        
    }
}