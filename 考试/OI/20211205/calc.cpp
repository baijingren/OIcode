#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    int n=998244353;
    while(n){
        if(n&1) printf("1");
        else printf("0");
        n>>=1;
    }
    cout<<endl;
    // n=872/2;
    // while(n){
    //     if(n&1) printf("1");
    //     else printf("0");
    //     n>>=1;
    // }
    // cout<<endl;
    // cout<<(872&872/2)<<endl;
    // n=872&872/2;
    // while(n){
    //     if(n&1) printf("1");
    //     else printf("0");
    //     n>>=1;
    // }
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    // while(scanf("%d",&n)!=EOF){
    //     printf("%d,",n);
    // }
    // printf("%lf",1e6/1999.0/1999.0);
}