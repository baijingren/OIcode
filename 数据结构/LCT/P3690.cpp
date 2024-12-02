#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
#define R t[rt].ch[1]
#define L t[rt].ch[0]
struct LCT{
    struct Tree{
        int ch[2];
        int fa;
        int sum,val,tag,laz,siz;
    } t[qwe];
    void pushup(int rt){
        t[rt].siz=t[t[rt].ch[0]].siz+t[t[rt].ch[1]].siz;
    }
    void pushdown(int rt){
        if(t[rt].tag){
            
            t[rt].tag=0;
        }
    }
    void splay(int x){
        int y=t[x].fa;
        int z=t[y].fa;
        int k=get(x);
        if(!isroot(y)){
            t[z].ch[t[z].ch[1]==y]=x;
        }
        t[]
        while()
    }
    void build(int rt){

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==0){

        }
        else if(op==1){

        }
        else if(op==2){

        }
        else if(op==3){

        }
    }
}