#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(){
    scanf("%lld",&n);
    // printf("%lld",(ll)floor((long double)(n/10)));
    if(n<0){
        ll ans=(ll)ceil((long double)(-n)/10);
        printf("%lld",-ans);
    }
    else{
        printf("%lld",n/10);
    }
}