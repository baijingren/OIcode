#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,p;
ll f[10];
int main(){
    scanf("%d%d",&n,&p);
    f[1]=1,f[2]=1,f[3]=2;
    for(int i=4;i<=n;i++){
        f[0]=f[1],f[1]=f[2],f[2]=f[3];
        f[3]=(f[1]+f[2])%p;
    }
    printf("%d",f[3]);
    return 0;
}