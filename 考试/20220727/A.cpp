#include<bits/stdc++.h>
using namespace std;
#define ll __int28_t
const int qwe=1e6+5;
string s;
int n;
int k;
vector<int> a[15];
int sv[15];
ll ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>k;
    n=s.length();
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        a[x].emplace_back(y);
    }
    for(int i=0;i<n;i++){
        sv[s[i]-'0']++;
    }
    for(int i=1;i<=n;i++){
        
    }
    return 0;
}