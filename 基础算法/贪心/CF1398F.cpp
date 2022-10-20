#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
string s;
int pre[qwe][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        pre[i+1][0]=pre[i][0];
        pre[i+1][1]=pre[i][1];
        if(s[i]=='?'){
            continue;
        }
        pre[i+1][s[i]&1^1]=i+1;
    }
    // int pos=0;
    for(int len=1;len<=n;len++){
        int pos=0,ans=0;
        while(pos+len<=n){
            if(pre[pos+len][0]==pre[pos][0] || pre[pos+len][1]==pre[pos][1]){
                pos+=len;
                ans++;
            }
            else{
                pos=pre[pos+len][pre[pos+len][1]<pre[pos+len][0]];
            }
        }
        cout<<ans<<' ';
    }
    cout<<endl;
    return 0;
}