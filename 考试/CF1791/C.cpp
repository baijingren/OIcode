#include<bits/stdc++.h>
using namespace std;

int T;
int n;
char c[2005];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=n/2;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            c[i]=c[i]-'0';
        }
        for(int i=1;i<=n;i++){
            if(c[i]^c[n-i+1]==0){
                ans=i-1;
                break;
            }
        }
        cout<<n-ans*2<<'\n';
    }
    return 0;
}