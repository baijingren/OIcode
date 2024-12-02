#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n,m;
bool fst[qwe];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a;
        char b;
        cin>>a>>b;
        if(fst[a] == false && b == 'M'){
            cout<<"Yes"<<endl;
            fst[a] = true;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}