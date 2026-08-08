#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,s;
int a[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&s);
        ll ans=s/(n*n);
        printf("%lld\n",ans);
    }
    return 0;
}