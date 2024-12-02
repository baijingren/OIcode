#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T,n;
string a,b;
int main(){
    cin>>T;
    while(T--){
        // cin>>n;
        cin>>a;
        cin>>b;
        char c = a[0];
        a[0]=b[0];
        b[0]=c;
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}