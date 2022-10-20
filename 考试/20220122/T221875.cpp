#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,b1,b2;
int a[qwe],c[2][qwe],d[2][qwe],w[2][qwe],u[2][qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&b1,&b2);
    for(int i=1;i<=n;i++) scanf("%d",&c[0][i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[1][i]);
    for(int i=1;i<=n;i++) scanf("%d",&d[0][i]);
    for(int i=1;i<=n;i++) scanf("%d",&d[1][i]);
    for(int i=1;i<=n;i++) scanf("%d",&u[0][i]);
    for(int i=1;i<=n;i++) scanf("%d",&u[1][i]);
}