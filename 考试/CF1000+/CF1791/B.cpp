#include<bits/stdc++.h>
using namespace std;
int T,n;
int u,r;
void init(){
    u=0;
    r=0;    
}
int main(){
    cin>>T;
    while(T--){
        init();
        cin>>n;
        bool f=0;
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            if(c=='U'){
                u++;
            }
            else if(c=='R'){
                r++;
            }
            else if(c=='D'){
                u--;
            }
            else if(c=='L'){
                r--;
            }
            if(u==1 && r==1){
                f=1;
            }
        }
        if(f){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}