#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
const int mod=1e9+7;
int T,n;
ll ans;
int a[qwe];
ll s[qwe],f[qwe];
map<ll,ll> mp;
void init(){
    mp.clear();
    mp[0]=1;
    ans=1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        init();
        cin>>n;
        ll tmp=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            tmp-=a[i];
            ll temp=ans-mp[a[i]+tmp];
            mp[a[i]+tmp]=ans;
            ans+=temp%mod;
        }
        cout<<(ans%mod+mod)%mod<<'\n';
    }
    return 0;
}