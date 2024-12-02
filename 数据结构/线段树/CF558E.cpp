#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,q;
string s;
int tmp[qwe];
char temp[qwe];
struct SegmentTree{
    struct Tree{
        int num[27],tag[27],len;
    } t[qwe];
    void init(){
        for(int i=0;i<qwe;i++){
            memset(t[i].tag,-1,sizeof(t[i].tag));
        }
    }
    void pushup(int rt){
        for(int i=1;i<=26;i++){
            t[rt].num[i]=(t[rt<<1].num[i]+t[rt<<1|1].num[i]);
        }
    }
    void pushdown(int rt,int col){
        if(t[rt].tag[col]!=-1){
            t[rt].num[col]=t[rt].tag[col]*t[rt].len;
            t[rt<<1].num[col]=t[rt].tag[col]*t[rt<<1].len;
            t[rt<<1|1].num[col]=t[rt].tag[col]*t[rt<<1|1].len;
            t[rt<<1].tag[col]=
            t[rt<<1|1].tag[col]=t[rt].tag[col];
            t[rt].tag[col]=-1;
        }
    }
    void build(int rt,int l,int r){
        t[rt].len=r-l+1;
        if(l==r){
            t[rt].num[tmp[l]]++;
            return;
        }
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void change(int rt,int l,int r,int L,int R,int w,int col){
        if(L<=l && R>=r){
            for(int i=1;i<=26;i++){
                t[rt].num[i]=0;
            }
            t[rt].num[col]=w*(r-l+1);
            t[rt].tag[col]=w;
            return;
        }
        pushdown(rt,col);
        int mid=(l+r)>>1;
        if(L<=mid){
            change(rt<<1,l,mid,L,R,w,col);
        }
        if(R>mid){
            change(rt<<1|1,mid+1,r,L,R,w,col);
        }
        pushup(rt);
    }
    int query(int rt,int l,int r,int L,int R,int col){
        if(L<=l && R>=r){
            return t[rt].num[col];
        }
        pushdown(rt,col);
        int mid=(l+r)>>1;
        int ans=0;
        if(L<=mid){
            ans+=query(rt<<1,l,mid,L,R,col);
        }
        if(R>mid){
            ans+=query(rt<<1|1,mid,r,L,R,col);
        }
        return ans;
    }
    void print(int rt,int l,int r){
        if(l==r){
            for(int i=1;i<=26;i++){
                if(t[rt].num[i]){
                    temp[l]='a'+i-1;
                    break;
                }
            }
            return;
        }
        for(int i=1;i<=26;i++){
            pushdown(rt,i);
        }
        int mid=(l+r)>>1;
        print(rt<<1,l,mid);
        print(rt<<1|1,mid+1,r);
    }
} t;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    cin>>s;
    for(int i=1;i<=n;i++){
        tmp[i]=s[i]-'a'+1;
    }
    s.append()
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==1){
            for(int i=1;i<=n;i++){
                
            }
        }
        else{
            
        }
    }

}