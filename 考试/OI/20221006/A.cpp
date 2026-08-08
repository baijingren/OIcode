#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n;
ll a[qwe],ans[qwe];
ll r[qwe],cnt=0;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    freopen("sgcd.in","r",stdin);
    freopen("sgcd.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        a[i]=gcd(a[1],a[i]);
    }
    ll p=a[1];
    for(ll i=2;i*i<=p;i++){
        if(p%i==0){
            r[++cnt]=i;
            while(p%i==0){
                p/=i;
            }
        }
    }
    if(p>1){
        r[++cnt]=p;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            ans[i]=-1;
            continue;
        }
        for(int j=1;j<=cnt;j++){
            if(a[i]%r[j]==0){
                ans[i]=a[i]/r[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}