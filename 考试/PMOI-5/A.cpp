#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,ans=1;
int main(){
    scanf("%d%d",&n,&k);
    ans=(k%mod)*((n%mod)*(n%mod)-1+mod)%mod+1;
    printf("%d",ans%mod);
    return 0;
}