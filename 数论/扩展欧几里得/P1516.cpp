#include<bits/stdc++.h>
using namespace std;
long long x,y,m,n,l,ans;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ans=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return ans;
}
int main(){
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    long long a=n-m,b=x-y;
    if(a<0){
        a=-a;
        b=-b;
    }
    exgcd(a,l,x,y);
    if(b%ans){
        printf("Impossible\n");
        return 0;
    }
    printf("%lld\n",((x*(b/ans))%(l/ans)+(l/ans))%(l/ans));
    return 0;
}