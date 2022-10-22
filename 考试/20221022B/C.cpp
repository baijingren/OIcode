#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
int T;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        ll k=gcd(a,b);
        a/=k;
        b/=k;
        a+=b;
        cout<<a<<'/'<<b<<'\n';
    }
    return 0;
}