#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n,cnta=0,cntb=0;
int a[qwe],b[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1){
                cnta++;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(b[i]==1){
                cntb++;
            }
        }
        if(cnta==cntb){
            
        }
    }
    return 0;
}