#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
int T;
long long ans;
int a[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        int tmp=INT_MAX,cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<=0){
                cnt++;
            }
            tmp=min(tmp,abs(a[i]));
            // cout<<tmp<<' ';
        }
        // cout<<endl;
        if((cnt&1)==1){
            ans=ans-1ll*tmp*2;
        }
        for(int i=1;i<=n;i++){
            ans=ans+1ll*abs(a[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}