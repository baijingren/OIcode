#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
int T,n;
ll c,ans=INT_MIN;
ll a[qwe],s[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        c=0;
        ans=INT_MIN;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,llabs(s[i])+(s[n]-s[i]));
        }
        cout<<ans<<endl;
    }
}