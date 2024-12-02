#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
#define ll long long
int T,n;
int x,y,z;
ll ans,k;
int a[qwe],cnt=0,b[qwe],sum=0;
int main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>z>>k;
        ans=0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                ll o=k/i/j;
                if(1ll * o*i*j == k){
                    ans=max(ans,1ll*(x-i+1)*(y-j+1)*(z-o+1));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}