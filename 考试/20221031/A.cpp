#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int k,T;
ll L[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    L[0]=1;
    L[1]=2;
    for(int i=2;i<=30;i++){
        L[i]=1ll*(i-1)*(1<<i)+2;
        // cerr<<L[i]<<' ';
    }
    while(T--){
        cin>>k;
        // for(int i=0;i<=30;i++){
            cout<<lower_bound(L,L+31,k)-L<<endl;
        // }
    }
    return 0;
}