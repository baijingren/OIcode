#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
long long ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i+=2){
        ans+=__builtin_ctz(i);
    }
    cout<<ans<<endl;
    return 0;
}