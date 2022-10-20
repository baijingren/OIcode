#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,q,t;
int a[qwe];
struct Blk{
    int id,l,r,x,y;
} b[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    t=sqrt(n);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d",&l,&r);
        b[i].id=i;
        b[i].l=l,b[i].r=r;
        b[i].x=l/t+1,b[i].r=r/t+1;
    }
    for(int i=1;i<)
}