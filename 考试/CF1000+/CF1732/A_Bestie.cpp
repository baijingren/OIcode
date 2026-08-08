#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n,k;
int a[qwe];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        cin>>a[1];
        k=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            k=gcd(k,a[i]);
        }
        if(k==1){
            cout<<"0\n";
        }
        else if(gcd(k,n)==1){
            cout<<"1\n";
        }
        else if(gcd(k,n-1)==1){
            cout<<"2\n";
        }
        else{
            cout<<"3\n";
        }
    }
    return 0;
}