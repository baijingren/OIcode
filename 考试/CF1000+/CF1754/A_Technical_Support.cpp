#include<bits/stdc++.h>
using namespace std;
int T;
int n;
string s;
int cntq=0,cnta=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        bool  flag=0;
        cnta=0;
        cntq=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='A'){
                cnta++;
            }
            else{
                cntq++;
            }
            if(cntq>cnta){
                flag=1;
                break;
            }
        }
        cout<<(flag?"No\n":"Yes\n");
    }
    return 0;
}