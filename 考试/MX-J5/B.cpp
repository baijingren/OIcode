#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, cnt, mx = 0;
int outp[qwe];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>outp[i];
        if(outp[i] == 0){
            cnt++;
        }
        else{
            mx=max(mx,outp[i]);
        }
    }
    if(cnt>mx){
         cout<<n-(cnt-mx);
    }
    else{
        cout<<n;
    }
    return 0;
}