#include<bits/stdc++.h>
using namespace std;
const int qwe = 2e5+5;
int n;
long long ans;
string s;

int a[30][qwe];
int main(){
    cin>>s;
    n = s.length();
    a[s[0] - 'A' + 1][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= 26; j++){
            if(s[i] - 'A' + 1 == j){
                a[j][i] = a[j][i-1] + 1;
            }
            else{
                a[j][i] = a[j][i-1];
            }
        }
    }
    for(int i = 1; i<= 3; i++){
        for(int j = 0; j < n; j++){
            // cerr<<"a["<<i<<"]["<<j<<"]:"<<a[i][j]<<'\n';
        }
    }
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j <= 26; j++){
            ans = ans + 1ll * a[j][i - 1] * (a[j][n-1] - a[j][i]);
        }
        // cerr<<"i:"<<i<<" ans:"<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}