#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans;
// int gcd(int a,int b){
//     return b==0?a:gcd(b,a%b);
// }
int main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    scanf("%d",&n);
    ans=0;
    for(int i=2;i<n;i+=2){
        ans++;
        for(int j=2;j<=n/i;j++){
            if(j==((i*j)^(i+1)*j)){
                if((i+1)*j<=n){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}