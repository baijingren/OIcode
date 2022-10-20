#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cin>>s;
    bool f=0;
    if(n==2){
        if(s[0]==s[1]){
            f=0;
        }
        else{
            f=1;
        }
    }
    if((s[0]=='A' && s[n-1]=='B')){
        f=1;
    }
    if(!f){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}