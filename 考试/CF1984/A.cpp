#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n,T;
int a[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[1]==a[n]){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int flag=1;
        cout<<"R";
        for(int i=2;i<n;i++){
            if(a[i]==a[i-1] && flag){
                cout<<"B";
                flag=0;
            }
            else
            {
                cout<<"R";
            }
        }
        if(flag){
            cout<<"B";
        }
        else{
            cout<<"R";
        }
        cout<<endl;
    }
}