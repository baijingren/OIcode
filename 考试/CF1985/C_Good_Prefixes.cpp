#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
int T,n,cnt;
int a[qwe];
ll s[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int mx=0;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=s[i-1]+a[i];
            mx=max(mx,a[i]);
            if(s[i]-mx == mx){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}