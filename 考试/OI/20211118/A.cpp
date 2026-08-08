#include<bits/stdc++.h>
using namespace std;
const int qwe=8e3+5;
const int mod=1e9+7;
int n,a,b;
int f[qwe][qwe];
void init(){
    
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    init();
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i][1]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&f[1][i]);
    }
    // for(int i=2;i<=n;i++){
    //     for(int j=2;j<=n;j++){
    //         f[i][j]=((a*(f[i][j-1]%mod))%mod+(b*f[i-1][j]%mod)%mod)%mod;
    //     }
    // }
    // printf("%d",f[n][n]%mod);
    return 0;
}