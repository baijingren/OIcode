#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans=0;
// int l[qwe],w[qwe];
struct Node{
    int l,w;
} a[qwe];
int f[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].w);
    }
    sort(a+1,a+n+1,[](Node x,Node y){
        return x.l==y.l?x.w>y.w:x.l>y.l;
    });
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[i].w>a[j].w){
                f[i]=max(f[i],f[j]+1);
            }
        }
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans+1);
    return 0;
}