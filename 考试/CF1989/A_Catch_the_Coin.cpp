#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
int x,y;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        int z = y-abs(x);
        x = -abs(x);
        if(z >= x-1){
            cout<<"YES"<<endl;
        }
        // else if()
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}