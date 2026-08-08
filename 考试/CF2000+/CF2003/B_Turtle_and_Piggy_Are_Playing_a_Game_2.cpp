#include<bits/stdc++.h>
using namespace std;
const int qwe  = 1e6+5;

int T,n;
int a[qwe];

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1, a+n+1);
        cout<<a[n/2+1]<<endl;
    }
}