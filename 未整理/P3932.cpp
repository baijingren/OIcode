#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans;
int a[qwe],d[qwe],s[qwe],w[qwe],c[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        s[i]=s[i-1]+d[i];
        // w[i]=w[i-1]+s[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",a[qwe]);
    }
    for(int i=1;i<=n;i++){
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        
    }
}