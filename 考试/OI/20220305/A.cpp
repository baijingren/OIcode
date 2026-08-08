#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=1e9+7;
int n;
char s[qwe];
int ans=0;
int main(){
    
    scanf("%d",&n);
    scanf("%s",s);
    n=strlen(s);
    for(int i=1;i<=n;i++){
        ans=(ans+(long long)i*(long long)i%mod)%mod;
    }
    printf("%d",ans);
}
//5940 1e9+7;