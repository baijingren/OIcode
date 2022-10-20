#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
ll l,r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>l>>r;
    cout<<"YES\n";
    for(ll i=l;i<=r;i+=2){
        cout<<i<<' '<<i+1<<'\n';
    }
    return 0;
}