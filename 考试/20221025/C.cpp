#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int n;
string s;
int mp[qwe][qwe];
int main(){
    freopen("fire.in","r",stdin);
    freopen("fire.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='B'){
                mp[i][j+1]=0;
            }
            else{
                mp[i][j+1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++){
            
        }
    }
}