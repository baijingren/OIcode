#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
long long n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>m>>n;
        if(m==1){
            if(n==0){
                cout<<'1'<<endl;
            }
            else{
                cout<<'2'<<endl;
            }
            continue;
        }
        if(n==0){
            cout<<(1ll<<m)<<endl;
        }
        else{
            cout<<(1ll<<m)-1<<endl;
        }
    }
    return 0;
}