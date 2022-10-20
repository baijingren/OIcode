#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe];
class LCT{
    struct L{
        int ch[2],num,sum,fa;
    };
public:
    L t[qwe];
    void pushup(int rt){
        t[rt].num=t[t[rt].ch[0]].num+t[t[rt].ch[1]].num;
        t[rt].sum=t[t[rt].ch[0]].sum^t[t[rt].ch[1]].sum^a[rt];
    }
    int rotate(int x){
        int y=t[x].fa,z=t[y].fa,k=(t[t[x].fa].ch[1]==x);
        if(!root(y)){
            t[z].ch[t[z].ch[1]==y]=x;
        }
        t[y].ch[k]=t[x].ch[k==1];
        // t[z].ch[k]=
        t[t[x].ch[k==1]].fa=y;
        t[x].ch[k]=y;
        // t[z].
        t[y].fa=x;
        t[x].fa=z;
        pushup(y);
        pushup(x);
    }
    void splay(int x){
        update(x);
    }
    void update(int x){
        int y=t[x].fa;
        if(!root(x)){
            update(y);
        }
        pushdown(x);
    }
    bool root(int x){
        int y=t[x].fa;
        if(t[y].ch[1]!=x && t[y].ch[0]!=x){
            return 1;
        }
        return 0;
    }
    void pushdown(int rt){
        
    }
    void access(int x){
        for(int y=0;x;y=x,x=t[x].fa){
            splay(x);
            t[x].ch[1]=y;
            pushup(x);
        }
    }
    int link(int x){
        makeroot(x);
    }
    void makeroot(int x){
        access(x);
        splay(x);
        swap(t[x].ch[0],t[x].ch[1]);
        
    }
};
LCT s;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        switch (op)
        {
        case 0:
            // query(x,y);
            s.split(x,y);
            printf("%d\n",s.t[y].sum);
            break;
        
        case 1:
            s.link(x,y);
            break;

        case 2:
            s.cut(x,y);
            break;
        
        case 3:
            s.splay(x);
            a[x]=y;
            break;
        }
    }
    return 0;
}