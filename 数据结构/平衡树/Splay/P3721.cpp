#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
class Splay{
    struct Tree{
        int ch[2],num,cnt,dep,fa;
    };
public:
    Tree t[qwe];
    int root=0;
    void pushup(int rt){

    }
    void splay(int rt){
        
    }
    void insert(int k){

    }
    void rotate(int x){
        int y=t[x].fa, z=t[y].fa;
        int k=(t[y].ch[1]==x);
        t[z].ch[t[z].ch[1]==y]=x;
        t[x].fa=z;
        
        t[y].fa=x;
        pushup(y);
        pushup(x);
    }
    int min_or_max(bool x){

    }
    int rotate_min(){

    }
    int rotate_max(){

    }
};
Splay s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        switch(x){
        case 1:
            int k;
            scanf("%d",&k);
            s.insert(k);
            break;
        
        case 2:
            printf("%d",s.rotate_min());
            break;
        case 3:
        
        }
    }
}