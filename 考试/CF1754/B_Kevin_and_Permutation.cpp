#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n;
int a[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        int cnt=0;
        for(int i=(n%2==0?n-1:n);i>0;i-=2){
            a[i]=++cnt;
        }
        for(int i=(n%2==0?n:n-1);i>0;i-=2){
            a[i]=++cnt;
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}