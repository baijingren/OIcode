#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;

int T,n;
char c[qwe];

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        if(c[1] == c[n]){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}