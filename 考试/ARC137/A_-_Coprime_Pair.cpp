#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
// int T;
ll n,m;
int a[qwe];
int v[qwe],p[qwe];
int gcd(int x,int y){
    return x%y==0?0:gcd(y,x%y);
}
int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    // shai(r);
    for(auto i=m-n;;i--){
        for(auto j=n;j+i<=m;j++){
            if(gcd(i,j)==1){
                printf("%lld",i);
                return 0;
            }
        }
    }
    return 0;
}