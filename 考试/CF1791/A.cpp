#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
char a;
bool c[35];
void init(){
    char c[]="codeforces";
    int k=strlen(c);
    for(int i=0;i<k;i++){
        ::c[c[i]-'a'+1]=1;
    }
}
int main(){
    cin>>T;
    init();
    while(T--){
        cin>>a;
        if(c[a-'a'+1]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}