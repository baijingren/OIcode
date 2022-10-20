#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
string s,ans[4];
int n;
int main(){
    cin>>s;
    n=s.length()-1;
    if(s[n]=='4'){
        for(int i=1;i<=3;i++){
            cout<<s.substr(0,n)<<i<<endl;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            ans[1]=s.substr(0,i)+'4';
        }
        else if(s[i]=='2'){
            ans[2]=s.substr(0,i)+'4';
        }
        else if(s[i]=='3'){
            ans[3]=s.substr(0,i)+'4';
        }
    }
    sort(ans,ans+3);
    for(int i=1;i<=3;i++){
        if(ans[i][0]=='T'){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}