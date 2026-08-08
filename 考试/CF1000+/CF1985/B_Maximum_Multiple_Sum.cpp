#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int mx=0,ans=0;
        for(int i=2;i<=n;i++){
            int x=n/i*i;
            // cerr<<x<<endl;
            if(mx<=((i+x)*(x/i)/2)){
                mx=(i+x)*(x/i)/2;
                ans=i;
            }
            // cout<<<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}