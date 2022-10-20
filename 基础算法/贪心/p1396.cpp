#include<bits/stdc++.h>
using namespace std;
const int qwe=1005;
int n;
int a[qwe],b[qwe];
int main(){
    scanf("%d",&n);
    int amax=0,bmax=0,ax=0,bx=0;
    int mx=0,my=0;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;
        b[y]++;
        mx=max(mx,x),my=max(my,y);
    }
    // cout<<mx<<' '<<my<<endl;
    for(int i=1;i<=max(mx,my);i++){
        // amax=max(amax,a[i]);
        // bmax=max(bmax,b[i]);
        // cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
        amax=a[i]>amax?ax=amax,amax=a[i]:amax=amax;
        bmax=b[i]>bmax?ax=bmax,bmax=b[i]:bmax=bmax;
    }
    cout<<amax+bmax+ax+bx<<endl;
}