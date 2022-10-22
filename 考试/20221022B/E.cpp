#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,s[qwe];
int a[qwe];
int f[qwe][qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){

    }
}