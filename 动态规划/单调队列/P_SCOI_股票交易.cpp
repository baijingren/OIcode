#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int n,m,w;
int ap[qwe],bp[qwe],as[qwe],bs[qwe];
int q[qwe];
int main(){
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
    }
    for(int i=1;i<=n;i++){
        f[i][0]=f[i-1][0]=0;
    }
    return 0;
}