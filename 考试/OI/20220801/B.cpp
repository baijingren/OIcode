#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,cnt;
map<string,bool> mp;
bool print=0;
void output(bool x){
    if(print){
        return;
    }
    cout<<(x?"ok\n":"g\n");
    print=1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s,op;
        cin>>s;
        print=0;
        if(mp[s]){
            output(0);
        }
        op=s;
        while(1){
            cin>>s;
            if(s==";"){
                break;
            }
            else{
                
            }
            
        }
        if(!print){
            mp[op]=++cnt;
        }
    }
}