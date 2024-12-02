#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>s;
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == '#' && s[i + 2] == '#' && s[i + 1] == '.')
            ans++;
    }
    cout<<ans;
    return 0;
}