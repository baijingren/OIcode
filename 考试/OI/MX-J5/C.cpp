#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;
int n;
int main(){
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(1ll*a*b<0){
            cout<<0<<endl;
        }
        else{
            cout<<min(min(abs(a),abs(b)),abs(a-b))<<endl;
        }
    }
}