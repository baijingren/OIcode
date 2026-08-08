#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,m;
int a[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        n*=2;
        m=1;
        while(n%2==0){
            n/=2;
            m*=2;
        }
        n=min(n,m);
        if(n<=1){
            printf("-1\n");
        }
        else{
            printf("%lld\n",n);
        }
    }
    return 0;
}