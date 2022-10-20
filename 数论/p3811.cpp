#include<bits/stdc++.h>
using namespace std;
const int qwe=5e6+5;
int n,p;
long long f[qwe];
int main(){
    scanf("%d%d",&n,&p);
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=((-(p/i)*f[(p%i)])%p+p)%p;
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",f[i]);
    }
    return 0;
}