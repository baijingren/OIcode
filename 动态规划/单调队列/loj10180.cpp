#include<bits/stdc++.h>
using namespace std;
const int qwe=2e5+5;
int n,m;
int a[qwe],f[qwe];
int q[qwe];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int hd=0,ed=0;
    for(int i=1;i<=n;i++){
        if(q[hd]<i-n) hd++;
        f[i]=f[q[hd]]+a[i];
        while(hd<=ed && f[q[ed]]>=f[i])ed--;
        q[++hd]=i;
    }
    int ans=0;
    for(int i=n-m+1;i<=n;i++){
        ans=min(ans,)
    }
}