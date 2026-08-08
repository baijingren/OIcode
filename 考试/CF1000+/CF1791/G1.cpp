#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int T;
long long ans;
int a[qwe],b[qwe],c[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=i+a[i];
        }
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)
            c[i]=c[i-1]+b[i];
        // for(int i=1;i<=n;i++)
        //     cout<<c[i]<<' ';
        // cout<<endl;
        for(int i=1;i<=n;i++){
            if(c[i]>m){
                ans=i-1;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}