#include<bits/stdc++.h>
using namespace std;
int flag = 0;
char c;
int main(){
    for(int i=1;i<=3;i++){
        cin>>c;
        if(c == 'R' && flag == 0){
            cout<<"Yes"<<endl;
            return 0;
        }
        else if(c == 'M'){
            flag = 1;
        }
    }
    cout<<"No"<<endl;
    return 0;
}