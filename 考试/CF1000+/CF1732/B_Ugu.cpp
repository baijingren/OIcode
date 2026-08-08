#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,T;
int a[qwe];
int ls[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%1d",&a[i]);
        }
        ls[n]=1;
        // a[n+1]=1;
        for(int i=n-1;i>=1;i--){
            if(a[i]!=a[i+1]){
                ls[i]=ls[i+1]+1;
            }
            else{
                ls[i]=ls[i+1];
            }
        }
        bool flag =0;
        for(int i=1;i<=n;i++){
            if(a[i-1]==1 && a[i]!=1){
                cout<<ls[i]<<endl;
                flag=1;
                break;
            }
        }
        if(flag){
            continue;
        }
        else{
            cout<<"0\n";
        }
    }
}